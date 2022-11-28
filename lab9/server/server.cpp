#include <winsock2.h>
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <cstdlib>
using namespace std;

#define MAX_CLIENTS 10
#define DEFAULT_BUFLEN 512

#pragma comment(lib, "ws2_32.lib") // Winsock library
#pragma warning(disable:4996)

SOCKET server_socket;

typedef struct SocketData {
	SOCKET socket;
} SOCKET_DATA, * SOCKET_DATA_PTR;


bool is_avaliable = true;
int send_data(SOCKET socket, const char* message)
{
	// Send an initial buffer
	while (!is_avaliable)
	{
		Sleep(100);
	}
	is_avaliable = false;
	send(socket, message, (int)strlen(message), 0);
	is_avaliable = true;

	return 0;
}



DWORD WINAPI subscribe_weather(LPVOID lpRaram)
{
	SOCKET_DATA_PTR Args = SOCKET_DATA_PTR(lpRaram);
	SOCKET socket = Args->socket;
	//delete Args;
	while (true)
	{
		time_t theTime = time(NULL);
		struct tm* aTime = localtime(&theTime);

		int day = aTime->tm_mday;
		int month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
		int year = aTime->tm_year + 1900; // Year is # years since 1900
		int hour = aTime->tm_hour;
		int minutes = aTime->tm_min;
		int seconds = aTime->tm_sec;
		string weather_string = "w" + to_string(year) + "." +
			to_string(month) + "." +
			to_string(day) + "|" +
			to_string(hour) + ":" +
			to_string(minutes) + ":" +
			to_string(seconds) + "#" + to_string((float(rand()) / float((RAND_MAX)) * 30.0));

		send_data(socket, weather_string.c_str());

		Sleep(15000);
	}
}


DWORD WINAPI subscribe_stocks(LPVOID lpRaram)
{
	SOCKET_DATA_PTR Args = SOCKET_DATA_PTR(lpRaram);
	SOCKET socket = Args->socket;
	//delete Args;
	while (true)
	{
		string stocks = "s" + to_string((float(rand()) / float((RAND_MAX)) * 140)) + "#" +
			to_string((float(rand()) / float((RAND_MAX)) * 180)) + "#" +
			to_string((float(rand()) / float((RAND_MAX)) * 130));

		send_data(socket, stocks.c_str());

		Sleep(5000);
	}
}


DWORD WINAPI subscribe_currency(LPVOID lpRaram)
{
	SOCKET_DATA_PTR Args = SOCKET_DATA_PTR(lpRaram);
	SOCKET socket = Args->socket;
	//delete Args;

	while (true)
	{
		string currency = "c" + to_string((float(rand()) / float((RAND_MAX)) * 45)) + "#" +
			to_string((float(rand()) / float((RAND_MAX)) * 40)) + "#" +
			to_string((float(rand()) / float((RAND_MAX)) * 50));

		send_data(socket, currency.c_str());
		Sleep(5000);
	}
}


DWORD WINAPI handle_socket_connection(LPVOID lpRaram)
{
	SOCKET_DATA_PTR Args = SOCKET_DATA_PTR(lpRaram);
	SOCKET socket = Args->socket;
	//delete Args;
	bool is_subscribed_weather = false;
	bool is_subscribed_stocks = false;
	bool is_subscribed_currency = false;
	char client_message[DEFAULT_BUFLEN];
	int iResult;
	HANDLE subscriptions[3] = { 0, 0, 0 };
	int weather = 0, stocks = 0, currency = 0;
	int* flag_weather = &weather;
	int* flag_stocks = &stocks;
	int* flag_currency = &currency;
	DWORD id;
	// Receive until the peer closes the connection
	do {
		iResult = recv(socket, client_message, DEFAULT_BUFLEN, 0);
		if (iResult > 0) {
			std::string converted_string = client_message;
			if (converted_string[0] == 's')
			{
				SOCKET_DATA args;
				args.socket = socket;
				if (converted_string[1] == ((char*)"1")[0])
				{
					*flag_weather = 0;
					subscriptions[0] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)subscribe_weather, &args, 0, &id);
				}
				if (converted_string[2] == ((char*)"1")[0])
				{
					*flag_stocks = 0;
					subscriptions[1] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)subscribe_stocks, &args, 0, &id);
				}
				if (converted_string[3] == ((char*)"1")[0])
				{
					*flag_currency = 0;
					subscriptions[2] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)subscribe_currency, &args, 0, &id);
				}
			}
			else if (converted_string[0] == 'u')
			{
				if (converted_string[1] == ((char*)"1")[0])
				{
					TerminateThread(subscriptions[0], 0);
				}
				if (converted_string[2] == ((char*)"1")[0])
				{
					TerminateThread(subscriptions[1], 0);
				}
				if (converted_string[3] == ((char*)"1")[0])
				{
					TerminateThread(subscriptions[2], 0);
				}
			}
		}
		else if (iResult == 0)
			printf("Connection closed\n");
		else
			printf("recv failed with error: %d\n", WSAGetLastError());

	} while (iResult > 0);
	return 0;
}


int main() {
	system("title Server");

	puts("Start server... DONE.");
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
		printf("Failed. Error Code: %d", WSAGetLastError());
		return 1;
	}

	// create a socket
	if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
		printf("Could not create socket: %d", WSAGetLastError());
		return 2;
	}
	// puts("Create socket... DONE.");

	// prepare the sockaddr_in structure
	sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(27015);

	// bind socket
	if (bind(server_socket, (sockaddr*)&server, sizeof(server)) == SOCKET_ERROR) {
		printf("Bind failed with error code: %d", WSAGetLastError());
		return 3;
	}

	// puts("Bind socket... DONE.");

	// listen to incoming connections
	listen(server_socket, MAX_CLIENTS);

	// accept and incoming connection
	puts("Server is waiting for incoming connections...\nPlease, start one or more client-side app.");

	// size of our receive buffer, this is string length
	// set of socket descriptors
	// fd means "file descriptors"

	while (true) {
		SOCKET new_socket; // new client socket
		sockaddr_in address;
		int addrlen = sizeof(sockaddr_in);
		if ((new_socket = accept(server_socket, (sockaddr*)&address, &addrlen)) < 0) {
			perror("accept function error");
			return 5;
		}

		// inform server side of socket number - used in send and recv commands
		printf("New connection, socket fd is %d, ip is: %s, port: %d\n", new_socket, inet_ntoa(address.sin_addr), ntohs(address.sin_port));

		// populate arguments for socket and start handling it
		SOCKET_DATA_PTR args = (SOCKET_DATA_PTR)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY,
			sizeof(SOCKET_DATA));;
		args->socket = new_socket;
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)handle_socket_connection, args, 0, NULL);
	}
	WSACleanup();
}
