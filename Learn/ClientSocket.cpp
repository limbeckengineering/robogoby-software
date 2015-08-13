#include "ClientSocket.h"

ClientSocket::ClientSocket(std::string portno, std::string IP, std::string name)
{
	this->name = name;
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed with error: %d\n", iResult);
		exit(1);
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	iResult = getaddrinfo(IP.c_str(), portno.c_str(), &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		exit(1);
	}

	printf("Client named %s created\n", this->name.c_str());

}

void ClientSocket::connectToServer()
{
	// Attempt to connect to an address until one succeeds
	for (ptr = result; ptr != NULL;ptr = ptr->ai_next) {

		// Create a SOCKET for connecting to server
		ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
			ptr->ai_protocol);
		if (ConnectSocket == INVALID_SOCKET) {
			printf("socket failed with error: %ld\n", WSAGetLastError());
			WSACleanup();
			exit(1);
		}

		// Connect to server.
		iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
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
		exit(1);
	}

	printf("Client named %s connected to server\n", name.c_str());
}

int ClientSocket::writeCli(const char * buf, int len, int flags, bool loopCheck)
{
	if (loopCheck) {
		int index = 0;
		int bytesLeft = len;

		while (bytesLeft > 0) {

			iResult = send(ConnectSocket, &buf[index], bytesLeft, flags);
			if (iResult < 0) { printf("send failed: %d\n", WSAGetLastError()); }
			printf("%s wrote %d bytes\n", name.c_str(), iResult);

			index += iResult;
			bytesLeft -= iResult;
		}

		return index;

	}
	else {
		iResult = send(ConnectSocket, buf, len, flags);
		if (iResult < 0) { printf("send failed: %d\n", WSAGetLastError()); }
		printf("%s wrote %d bytes\n", name.c_str(), iResult);
		return iResult;
	}
}

int ClientSocket::readCli(char * buf, int len, int flags, bool loopCheck)
{
	if (loopCheck) {
		int index = 0;
		int bytesLeft = len;

		while (bytesLeft > 0) {
			iResult = recv(ConnectSocket, &buf[index], bytesLeft, flags);
			if (iResult < 0) { printf("recv failed: %d\n", WSAGetLastError()); }
			printf("%s red in %d bytes\n", name.c_str(), iResult);

			index += iResult;
			bytesLeft -= iResult;

		}

		return index;
	}
	else {
		iResult = recv(ConnectSocket, buf, len, flags);
		if (iResult < 0) { printf("recv failed: %d\n", WSAGetLastError()); }
		printf("%s red in %d bytes\n", name.c_str(), iResult);
		return iResult;
	}
}


ClientSocket::~ClientSocket()
{
	closesocket(ConnectSocket);
	WSACleanup();
	printf("Client named %s destroyed\n", name.c_str());
}
