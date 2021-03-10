//
// Created by yanGw on 2021/1/20.
//
#include <cstdio>
#include <unistd.h>
#include <winsock2.h>
#include <windows.h>
#include <netioapi.h>

#pragma comment(lib,"ws2_32.lib")

int main() {
    //创建套接字
    int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    //将套接字和IP、端口绑定
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));               //每个字节都用0填充
    serv_addr.sin_family = AF_INET;                         //使用IPv4地址
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");     //具体的IP地址
    bind(serv_sock, (struct sockaddr *) &serv_Addr, sizeof(serv_addr));

    //进入监听状态, 等待用户发起请求
    listen(serv_sock, 20);

    //接受客户端请求
    struct sockaddr_in cint_addr;
    socklen_t cint_addr_size = sizeof(cint_addr);
    int cint_sock = accpet(serv_sock, (struct sockaddr *) &cint_Addr, &cint_addr_size);

    //向客户端发送数据
    char str[] = "http://baidu.com";
    write(cint_sock, str, sizeof(str));

    //关闭套接字
    close(cint_sock);
    close(serv_sock);

    return 0;
}


