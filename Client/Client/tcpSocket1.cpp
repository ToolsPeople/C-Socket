#include "tcpSocket.h"
#include<iostream>
#include<WS2tcpip.h>
using namespace std;

bool init_Socket()
{
	//wsa windows socket async   windows�첽�׽���
	WSADATA wsadata;
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0) {
		cout << "����ⴴ��ʧ��" << endl;
		return false;
	}
	return true;
}

bool close_Socket()
{

	if (WSACleanup() != 0) {
		cout << "�����ر�ʧ��" << endl;
		return false;
	}
	return true;
}

//ÿһ�����������
//1.���ֻ�
//2.�忨
//3.�����ֻ�
SOCKET createClientSocket()
{
	//1.�����յ�Socket
	//parm1:af ��ַЭ���� ipv4 ipv6 
	//parm2:type ����Э������ ��ʽ�׽��� ���ݱ�
	//parm3:protocol ʹ�þ����ĳ������Э��
	//�궨���е�ֵ
	//AF_INET     == 2 ����ipv4
	//SOCK_STREAM == 1 ��ʽ�׽��� 
	//IPPROTO_TCP == 6 TCPЭ��
	SOCKET fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);


	//INVALID_SOCKET �� ����ʱ���ص�ֵ
	if (fd == INVALID_SOCKET)
	{
		//����ʧ��
		err("socket");
		return INVALID_SOCKET;
	}

	//2.���������������
	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	//�˿ںŷ�Χ [0,65536��0-1024ϵͳ�����˿�
	addr.sin_port = 8888;
	InetPton(AF_INET, TEXT("127.0.0.1"), &addr.sin_addr.s_addr);

	if (connect(fd, (SOCKADDR *)&addr, sizeof(addr)) == INVALID_SOCKET)
	{
		err("connect");
		return false;
	}



	return fd;
}
