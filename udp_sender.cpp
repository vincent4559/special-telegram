#pragma comment(lib, "Ws2_32.lib")
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <stdio.h> 
#include <assert.h>
#include <string.h> 
#include <string>
using namespace std;


int main() {
	string userInput = "hello";
	int port = 54000;
	char buffer[4096];
	SOCKET sock;

	struct sockaddr_in serv_addr;


	WSADATA wsa;
	int wsResult = WSAStartup(MAKEWORD(2, 2), &wsa);
	if (wsResult != 0) {
		cerr << "Can't start winsock, err #" << wsResult;
		return 0;
	}

	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock == INVALID_SOCKET) {
		cerr << "Can't initialize socket err #" << WSAGetLastError() << endl;
		WSACleanup();
		return 0;
	}
	ZeroMemory(&serv_addr, sizeof(sockaddr_in));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);
	inet_pton(AF_INET, "192.168.2.92", &(serv_addr.sin_addr));




	while (userInput != "") {

		cout << "enter a message you would like to send: ";
	    getline(cin, userInput);

		int tmp = sendto(sock, userInput.c_str(), userInput.size() + 1, 0, (sockaddr*)&serv_addr, sizeof(sockaddr));
		if (tmp != SOCKET_ERROR) {
			ZeroMemory(buffer, 4096);
			cout << endl;

		}
		else {
			cerr << "error sending: " << WSAGetLastError();
			return 0;
		}
	}
		
	closesocket(sock);
	WSACleanup();
	   



}







