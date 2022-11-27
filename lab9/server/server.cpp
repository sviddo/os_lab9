#include <winsock2.h>
#include <ws2tcpip.h> 
#include <iostream>
#include <string>
#include <array>

//used to link winsock lib
#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_PORT "101"
#define BUFFER_LEN 512

struct ClientData {
	SOCKET Client;
	HANDLE KillEvent;
	//...
};


DWORD WINAPI SendData(LPVOID lpParameter) {
	ClientData* Data = (ClientData*)lpParameter;
	SOCKET Client = Data->Client;
	HANDLE KillEvent = Data->KillEvent;
	delete Data;

	//sending data to socket
	while (true) {
		DWORD WaitRes = WaitForSingleObject(KillEvent, 0);
		if(WaitForSingleObject(KillEvent, 0) == WAIT_OBJECT_0)
			break;
		std::string msg = "...";
		send(Client, msg.c_str(), msg.size(), NULL);
	}
	return 0;
}

DWORD WINAPI ProcessClient(LPVOID lpParameter) {
	SOCKET ClientSocket = (SOCKET)lpParameter;

	char recvbuf[BUFFER_LEN];
	HANDLE NewThread = NULL;
	bool IsRunning = false;
	HANDLE KillEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	while (true) {
		int iResult = recv(ClientSocket, recvbuf, BUFFER_LEN, 0);
		if (iResult > 0) {
			std::string message(recvbuf);
			std::cout << message;
			//do something

			//if client subscribes
			if (IsRunning) {
				SetEvent(KillEvent);
			}

			ClientData *Data = new ClientData();
			Data->Client = ClientSocket;
			Data->KillEvent = KillEvent;
			//...

			NewThread = CreateThread(NULL, NULL, SendData, (void*)Data, NULL, NULL);
			IsRunning = true;

			//if client cancels subscription
			if (IsRunning) {
				SetEvent(KillEvent);
				IsRunning = false;
			}
		}
		if (iResult == 0) //client exits
			break;
	}
	shutdown(ClientSocket, SD_SEND);
	closesocket(ClientSocket);
	return 0;
}


int main() {
	struct addrinfo* result = NULL, * ptr = NULL, hints;
	WSADATA wsaData;

	//is used to initiate the use of dll
	int res = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (res != 0) {
		std::cout << "WSASTARTUP failed.\nError code: " << res;
	}
	std::cout << "Started up\n";
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	res = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
	if (res != 0) {
		std::cout << "getaddrinfo failed;(\n";
		WSACleanup();
	}
	std::cout << "Getaddrinfo successful\n";

	//Creating socket
	SOCKET ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (ListenSocket == INVALID_SOCKET) {
		std::cout << "Error creating socket: " << WSAGetLastError() << "\n";
		WSACleanup();
		return -1;
	}
	std::cout << "Created socket\n";

	//bind function associates socket with local address
	res = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	if (res == SOCKET_ERROR) {
		std::cout << "Bind failed.\nError code: " << WSAGetLastError() << "\n";
		WSACleanup();
		return -1;
	}
	std::cout << "Bind successful\n";

	//addrinfo no longer needed
	freeaddrinfo(result);

	if (listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR) {
		std::cout << "Listen failed.\nError code: " << WSAGetLastError() << "\n";
		closesocket(ListenSocket);
		return -1;
	}
	std::cout << "Listen successful\n";

	while (true) {
		//accepting connections
		SOCKET ClientSocket = INVALID_SOCKET;
		while (ClientSocket == INVALID_SOCKET) {
			ClientSocket = accept(ListenSocket, (SOCKADDR*)&ClientAddress, &AddrLen);
		}
		std::cout << "Client connected.\n";

		//Creating separate threads to process clients
		DWORD ThreadID;
		CreateThread(NULL, NULL, ProcessClient, (void*)ClientSocket, NULL, &ThreadID);
	}
	return 0;
}
