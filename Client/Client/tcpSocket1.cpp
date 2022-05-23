#include "tcpSocket.h"
#include<iostream>
#include<WS2tcpip.h>
using namespace std;

bool init_Socket()
{
	//wsa windows socket async   windows异步套接字
	WSADATA wsadata;
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0) {
		cout << "网络库创建失败" << endl;
		return false;
	}
	return true;
}

bool close_Socket()
{

	if (WSACleanup() != 0) {
		cout << "网络库关闭失败" << endl;
		return false;
	}
	return true;
}

//每一步的形象比喻
//1.买手机
//2.插卡
//3.监听手机
SOCKET createClientSocket()
{
	//1.创建空的Socket
	//parm1:af 地址协议族 ipv4 ipv6 
	//parm2:type 传输协议类型 流式套接字 数据报
	//parm3:protocol 使用具体的某个传输协议
	//宏定义中的值
	//AF_INET     == 2 就是ipv4
	//SOCK_STREAM == 1 流式套接字 
	//IPPROTO_TCP == 6 TCP协议
	SOCKET fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);


	//INVALID_SOCKET 是 错误时返回的值
	if (fd == INVALID_SOCKET)
	{
		//创建失败
		err("socket");
		return INVALID_SOCKET;
	}

	//2.与服务器建立连接
	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	//端口号范围 [0,65536）0-1024系统保留端口
	addr.sin_port = 8888;
	InetPton(AF_INET, TEXT("127.0.0.1"), &addr.sin_addr.s_addr);

	if (connect(fd, (SOCKADDR *)&addr, sizeof(addr)) == INVALID_SOCKET)
	{
		err("connect");
		return false;
	}



	return fd;
}
