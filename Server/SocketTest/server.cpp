#include "tcpSocket.h"
#include<iostream>
using namespace std;

int main()
{
	init_Socket();
	SOCKET serfd = createServerSocket();

	cout << "�ȴ��ͻ�������" << endl;
	//����пͻ�����������
	SOCKET clifd = accept(serfd,NULL,NULL);
	if (clifd == INVALID_SOCKET) {
		err("accept")
	}
	else
	{
		cout << "���ӳɹ�" << endl;
	}
	
	//���ԺͿͻ��˽���ͨ����
	char sendbuf[BUFSIZ] = { 0 };
	char recvbuf[BUFSIZ] = { 0 };
	while (true)
	{
		//recv��ָ����socket������Ϣ
		if (recv(clifd, recvbuf, BUFSIZ, 0) > 0) {
			cout <<"recv:"<< recvbuf << endl;
			memset(recvbuf, 0, sizeof(recvbuf));
		}
		//������Ϣ
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