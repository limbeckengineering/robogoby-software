#pragma once

#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

class ClientSocket
{
public:
	ClientSocket(std::string portno, std::string IP, std::string name);
	void connectToServer();
	int writeCli(const char * buf, int len, int flags);
	int readCli(char * buf, int len, int flags);
	virtual ~ClientSocket();

private: 
	WSADATA wsaData;
	SOCKET ConnectSocket = INVALID_SOCKET;
	struct addrinfo *result = NULL,
		*ptr = NULL,
		hints;
	int iResult;
	std::string name;
};

