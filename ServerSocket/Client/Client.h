//
// Created by pablo on 24/6/21.
//

#ifndef PROYECTO_III_CLIENT_H
#define PROYECTO_III_CLIENT_H

#include <sys/types.h>
#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>
#include <fcntl.h>
#include <sys/shm.h>
#include <string>

using namespace std;

class Client {
public:
    Client();
    string sendData(string outData);
private:
    int port = 5000;
    string ip = "127.0.0.1";
    struct sockaddr_in server_addr;
    int client = socket(AF_INET,SOCK_STREAM,0);
    char inData[10000];
    char outData[1024];
};



#endif //PROYECTO_III_CLIENT_H
