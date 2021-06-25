//
// Created by pablo on 24/6/21.
//

#include "Server.h"


using json = nlohmann::json;

Server::Server() {
    startServer();
}

void Server::startServer() {
    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_port = htons(port);

    server_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server,(struct sockaddr*)&server_sockaddr, sizeof(server_sockaddr))==-1){
        cout<<"Error conectando"<<endl;
        return;
    }
    if (listen(server,queue)==-1){
        cout<<"Error escuchando cliente"<<endl;
        return;
    }

    struct  sockaddr_in client_addr;
    socklen_t socklen = sizeof(client_addr);

    conection = accept(server, (struct sockaddr *) &client_addr, &socklen);
    if (conection < 0) {
        cout << "Error de conexión" << endl;
        return;
    }
}

string Server::sendData(string sendDataOut) {
    cout << "Esperando conexión..." << endl;
    char inData[1024];
    memset(inData,'\0', strlen(inData));
    cout << inData << "---------" << endl;
    recv(conection, inData, sizeof(inData), 0);
    cout << "Nueva conexión" << endl;
    cout << inData << "---------" << endl;

    json inDataJson = json::parse(inData);

    string codeIN = inDataJson["code"];
    string keyIN = inDataJson["key"];

    HCBinaryTree* huffmanCodeIn = new HCBinaryTree;

    string inDataResult = huffmanCodeIn->decodeString(codeIN,keyIN);

    HCBinaryTree* huffmanCodeOut = new HCBinaryTree;
    CharacterList characterListOut;
//    string tempS;
//    tempS = sendDataOut;
    characterListOut.addCharacters(sendDataOut);
    string outKey = huffmanCodeOut->createTree(characterListOut);
    string outDataResult = huffmanCodeOut->encodeString(sendDataOut,outKey);
    json outJson;
    outJson["code"] = outDataResult;
    outJson["key"] = outKey;

    string outDataFinal = outJson.dump();
    char outChar[10000];
    memset(outChar,'\0', strlen(outChar));
    strcpy(outChar,outDataFinal.c_str());
    send(conection, outChar, sizeof (outChar), 0);

    return inDataResult;

}
