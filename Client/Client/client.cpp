#include "tcpSocket.h"
#include <iostream>
using namespace std;

int main()
{
	init_Socket();

	SOCKET fd = createClientSocket();
	char sendbuf[BUFSIZ] = "你好我是客户端";
	char recvbuf[BUFSIZ] = { 0 };
	while (true)
	{
		//发送消息
		cout << "send: ";
		gets_s(sendbuf, BUFSIZ);
		if (send(fd,sendbuf, strlen(sendbuf), 0) == SOCKET_ERROR)
		{
			err("send");
		}

		//recv从指定的socket接受消息
		if (recv(fd,recvbuf, BUFSIZ, 0) > 0) {
			cout <<"recv:"<< recvbuf << endl;
			memset(recvbuf, 0, sizeof(recvbuf));
		}
		

	}

	closesocket(fd);
	close_Socket();
	return 0;
}
