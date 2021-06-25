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
#include "../Json/json.hpp"
#include "../../HuffmanCode/HCBinaryTree/HCBinaryTree.h"

using namespace std;
/**
 * @brief ServerSocket encargado del manejo de la instancia e inicio del servidor
 */
class Server {
public:
    /**
     * @brief Método constructor de la clase server
     */
    Server();
    /**
     * @brief Método encargado del inicio del servidor, este hace los llamados para abrir el socket.
     */
    void startServer();
    /**
     * @brief Este método toma el string de su entrada, lo codifica con Hoffman y lo envía por sockets
     * @param inData un string con la información a enviar
     * @return retorna la respuesta del servidor en forma de string, este de se decodifica con Hoffman
     */
    string sendData(string inData);
    int port = 50000;
    string ip = "127.0.0.1";
private:
    int server = socket(AF_INET,SOCK_STREAM,0);
    int queue = 20;
    int conection;
    string outData;

    struct sockaddr_in server_sockaddr;
};




#endif //PROYECTO_III_SERVER_H
