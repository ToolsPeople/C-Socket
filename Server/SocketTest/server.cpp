#include "tcpSocket.h"
#include<iostream>
using namespace std;

int main()
{
	init_Socket();
	SOCKET serfd = createServerSocket();

	cout << "等待客户端连接" << endl;
	//如果有客户端请求连接
	SOCKET clifd = accept(serfd,NULL,NULL);
	if (clifd == INVALID_SOCKET) {
		err("accept")
	}
	else
	{
		cout << "连接成功" << endl;
	}
	
	//可以和客户端进行通信了
	char sendbuf[BUFSIZ] = { 0 };
	char recvbuf[BUFSIZ] = { 0 };
	while (true)
	{
		//recv从指定的socket接受消息
		if (recv(clifd, recvbuf, BUFSIZ, 0) > 0) {
			cout <<"recv:"<< recvbuf << endl;
			memset(recvbuf, 0, sizeof(recvbuf));
		}
		//发送消息
		cout << "send:";
		gets_s(sendbuf, BUFSIZ);
		if (send(clifd, sendbuf, strlen(sendbuf), 0)==SOCKET_ERROR)
		{
			err("send");
		}
	}
	




	closesocket(clifd);
	closesocket(serfd);
	close_Socket();
	return 0;
}