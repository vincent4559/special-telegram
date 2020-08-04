	#pragma comment (lib, "ws2_32.lib")
#include <iostream>
#include <ws2tcpip.h>

#include <string>

using namespace std;

int main() {
	//start up winsock
	WSADATA wsa;
	WORD vers = MAKEWORD(2, 2);
	int wsoOK = WSAStartup(vers, &wsa);
	if (wsoOK != 0) {
		cout << "can't start winsock" << endl;
		return 0;
	}
	//bind socket to ip address and port
	SOCKET sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock == INVALID_SOCKET){
		cout << "socket error" << endl;
		return 0;
	}

	sockaddr_in hint;
	hint.sin_addr.S_un.S_addr = ADDR_ANY;;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(54000);

	if ((bind(sock, (sockaddr*)&hint, sizeof(hint)) == SOCKET_ERROR)) {
		cout << "bind failed" << endl;
	}
	

	sockaddr_in client;
	int clientLength = sizeof(client);
	ZeroMemory(&client, clientLength);

	char buff[1024];
	ZeroMemory(&buff, 1024);

	//enter a loop
	while (true) {

		ZeroMemory(&buff, 1024);
		//wait for message 
		int bytes = recvfrom(sock, buff, 1024, 0, (sockaddr*)&client, &clientLength);
		if (bytes == SOCKET_ERROR) {
			cout << "error recieving from client" << WSAGetLastError << endl;
			continue;
		}
		//display message and client info
		char clientip[256];
		ZeroMemory(&clientip, 256);

		inet_ntop(AF_INET, &client.sin_addr, clientip, 256);
		
		cout << "message recieved from " << clientip << " : " << buff << endl;

	}
	//close socket
	closesocket(sock);
	//clear winsock
	WSACleanup();
}
