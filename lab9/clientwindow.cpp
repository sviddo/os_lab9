#include <string>
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <processthreadsapi.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>
#include <strsafe.h>
#include <string>
#include <iostream>
#include "clientwindow.h"
#include "ui_clientwindow.h"

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"

WSADATA wsaData;
SOCKET ConnectSocket = INVALID_SOCKET;
struct addrinfo *result = NULL,
                *ptr = NULL,
                hints;
const char *sendbuf = "this is a test";
char recvbuf[DEFAULT_BUFLEN];
int iResult;
int recvbuflen = DEFAULT_BUFLEN;

bool is_launched = false;
bool is_subscribed_weather = false;
bool is_subscribed_stocks = false;
bool is_subscribed_currency = false;

Ui::ClientWindow *ui_global;

ClientWindow::ClientWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
    ui_global = ui;
}

ClientWindow::~ClientWindow()
{
    delete ui;
}

HANDLE thread_handle;
DWORD thread_id;


int handle_startup_work()
{
    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);

    ZeroMemory( &hints, sizeof(hints) );
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
    iResult = getaddrinfo("127.0.0.1", DEFAULT_PORT, &hints, &result);

    // Attempt to connect to an address until one succeeds
    for(ptr=result; ptr != NULL ;ptr=ptr->ai_next) {
        // Create a SOCKET for connecting to server
        ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
            ptr->ai_protocol);

        // Connect to server.
        iResult = connect( ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR) {
            closesocket(ConnectSocket);
            ConnectSocket = INVALID_SOCKET;
            continue;
        }
        break;
    }

    freeaddrinfo(result);

    if (ConnectSocket == INVALID_SOCKET) {
        printf("Unable to connect to server!\n");
        WSACleanup();
        return 1;
    }

    return 0;
}



int send_data(const char* message)
{
    // Send an initial buffer
    iResult = send( ConnectSocket, message, (int)strlen(sendbuf), 0 );
    if (iResult == SOCKET_ERROR) {
        printf("send failed with error: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }

    return 0;
}



int close_socket()
{
    // shutdown the connection since no more data will be sent
    iResult = shutdown(ConnectSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }

    // cleanup
    closesocket(ConnectSocket);
    WSACleanup();

    return 0;
}



DWORD WINAPI receive_data_from_server()
{
    // Receive until the peer closes the connection
    do {
        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        if ( iResult > 0 ){
            std::string result = recvbuf;
            char symbol_to_check = result[0];
            result = result.substr(1);
            if (symbol_to_check == ((char*)"w")[0])
            {
                std::string delimiter = "#";
                size_t pos = 0;
                std::string token;
                std::string array[2];
                int i = 0;
                while ((pos = result.find(delimiter)) != std::string::npos) {
                    token = result.substr(0, pos);
                    array[i] = token;
                    std::cout << token << std::endl;
                    result.erase(0, pos + delimiter.length());
                    i++;
                }
                ui_global->dateTimeLabel->setText(QString::fromStdString(array[0]));
                ui_global->tempLabel->setText(QString::fromStdString(result));
            } else if (symbol_to_check == ((char*)"s")[0])
            {
                std::string delimiter = "#";
                size_t pos = 0;
                std::string token;
                std::string array[3];
                int i = 0;
                while ((pos = result.find(delimiter)) != std::string::npos) {
                    token = result.substr(0, pos);
                    array[i] = token;
                    std::cout << token << std::endl;
                    result.erase(0, pos + delimiter.length());
                    i++;
                }
                ui_global->appleLabel->setText(QString::fromStdString(array[0]));
                ui_global->teslaLabel->setText(QString::fromStdString(array[1]));
                ui_global->amazonLabel->setText(QString::fromStdString(result));
            } else if (symbol_to_check == ((char*)"c")[0])
            {
                std::string delimiter = "#";
                size_t pos = 0;
                std::string token;
                std::string array[3];
                int i = 0;
                while ((pos = result.find(delimiter)) != std::string::npos) {
                    token = result.substr(0, pos);
                    array[i] = token;
                    std::cout << token << std::endl;
                    result.erase(0, pos + delimiter.length());
                    i++;
                }
                ui_global->dollarLabel->setText(QString::fromStdString(array[0]));
                ui_global->euroLabel->setText(QString::fromStdString(array[1]));
                ui_global->poundLabel->setText(QString::fromStdString(result));
            }
        }
        else if ( iResult == 0 )
            printf("Connection closed\n");
        else
            printf("recv failed with error: %d\n", WSAGetLastError());

    } while( iResult > 0 );
    return 0;
}


void ClientWindow::on_subscribeButton_clicked()
{
    if ((!is_subscribed_weather) && (!is_subscribed_stocks) && (!is_subscribed_currency))
    {
        handle_startup_work();
        thread_handle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)receive_data_from_server, NULL, 0, &thread_id);
    }
    std::string requestStr = "s";
    if(ui->weatherCheckBox->isChecked()){
            QStringList citiesList;
            QString choiceCity = "Львів";
            bool ok = false;
            citiesList << "Львів" << "Київ" << "Івано-Франківськ" << "Харків" << "Дніпро";
            choiceCity = QInputDialog::getItem(this, "", "Оберіть місто, обновлення погоди\nз якого ви хочете бачити: ",
                                                       citiesList, false ,&ok);
            requestStr += "1";
            ui->cityLabel->setText(choiceCity);
    } else requestStr += "0";
    requestStr += (ui->stocksCheckBox->isChecked()) ? "1" : "0";
    requestStr += (ui->currencyCheckBox->isChecked()) ? "1" : "0";
    if (ui->stocksCheckBox->isChecked())
    {
        is_subscribed_stocks = true;
    }
    if (ui->currencyCheckBox->isChecked())
    {
        is_subscribed_currency = true;
    }
    if (ui->weatherCheckBox->isChecked())
    {
        is_subscribed_weather = true;
    }
    const char* request = requestStr.c_str();
    send_data(request);
}


void ClientWindow::on_unsubscribeButton_clicked()
{
    if (ui->weatherCheckBox->isChecked())
    {
        is_subscribed_weather = false;
        ui->dateTimeLabel->setText("");
        ui->cityLabel->setText("");
        ui->tempLabel->setText("");
    }
    if (ui->stocksCheckBox->isChecked())
    {
        is_subscribed_stocks = false;
        ui->teslaLabel->setText("");
        ui->appleLabel->setText("");
        ui->amazonLabel->setText("");
    }
    if (ui->currencyCheckBox->isChecked())
    {
        is_subscribed_currency = false;
        ui->dollarLabel->setText("");
        ui->euroLabel->setText("");
        ui->poundLabel->setText("");
    }
    std::string request = std::string("u") + ((ui->weatherCheckBox->isChecked()) ? "1" : "0") +
        ((ui->stocksCheckBox->isChecked()) ? "1" : "0") +
        ((ui->currencyCheckBox->isChecked()) ? "1" : "0");
    send_data(request.c_str());
    if ((!is_subscribed_weather) && (!is_subscribed_stocks) && (!is_subscribed_currency))
    {
        TerminateThread(thread_handle, 0);
        close_socket();
    }
}

