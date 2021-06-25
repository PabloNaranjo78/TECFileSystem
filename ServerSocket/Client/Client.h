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
/**
 * @brief Clase cliente engardaga de manejar la instancia de cliente del socket
 */
class Client {
public:
    /**
     * @brief Constructor de la clase Client, inicializa los procesos necesarios para el funcionamiento de los sockets
     */
    Client();
    /**
     * @brief Toma un string, lo envía por sockets codificado con Hoffman
     * @param outData string de información a enviar, esta de codifica y comprime utilizando Huffman
     * @return retorna la respuesta del servidor en forma de string, a su vez, decodifica el contenido con Huffman
     */
    string sendData(string outData);
    int port = 50000;
    string ip = "127.0.0.1";

private:
    struct sockaddr_in server_addr;
    int client = socket(AF_INET,SOCK_STREAM,0);
    char inData[10000];
    char outData[10000];
};



#endif //PROYECTO_III_CLIENT_H
