//
// Created by pablo on 24/6/21.
//

#ifndef PROYECTO_III_SERVER_H
#define PROYECTO_III_SERVER_H

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <thread>
#include <iostream>
using namespace std;
class Server {
public:
    Server();
    void startServer();
    string sendData(string inData);

private:
    int server = socket(AF_INET,SOCK_STREAM,0);
    int port = 5000;
    int queue = 20;
    int conection;
    string outData;

    struct sockaddr_in server_sockaddr;
};




#endif //PROYECTO_III_SERVER_H