#pragma once
#include<WinSock2.h> //windowsƽ̨�������ͷ�ļ�
#pragma comment(lib,"ws2_32.lib")
#include<stdbool.h>
#include<iostream>

#define err(errMsg) cout   <<errMsg << "����"<<endl;

//�������
bool init_Socket();
//�ر������
bool close_Socket();
//�����ͻ���scoket
SOCKET createClientSocket();