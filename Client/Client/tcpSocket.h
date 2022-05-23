#pragma once
#include<WinSock2.h> //windows平台的网络库头文件
#pragma comment(lib,"ws2_32.lib")
#include<stdbool.h>
#include<iostream>

#define err(errMsg) cout   <<errMsg << "错误"<<endl;

//打开网络库
bool init_Socket();
//关闭网络库
bool close_Socket();
//创建客户端scoket
SOCKET createClientSocket();