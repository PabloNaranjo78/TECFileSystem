//
// Created by pablo on 24/6/21.
//

#include "Client.h"
#include "iostream"
#include "../../HuffmanCode/HCBinaryTree/HCBinaryTree.h"
#include "../Json/json.hpp"

using namespace std;
using json = nlohmann::json;

Client::Client() {
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip.c_str());

    if (connect(client,(struct sockaddr*)&server_addr, sizeof(server_addr))<0){
        cout<<"Error de conexión"<<endl;
    }
}

string Client::sendData(string _outData) {

    HCBinaryTree* huffmanCodeOut = new HCBinaryTree;
    CharacterList characterListOut;
//    string tempS;
//    tempS = sendDataOut;
    characterListOut.addCharacters(_outData);
    string outKey = huffmanCodeOut->createTree(characterListOut);
    string outDataResult = huffmanCodeOut->encodeString(_outData,outKey);
    json outJson;
    outJson["code"] = outDataResult;
    outJson["key"] = outKey;

    string outDataFinal = outJson.dump();

    strncpy(outData,outDataFinal.c_str(),1024);
    send(client,outData, strlen(outData),0);

    recv(client, inData, sizeof(inData), 0);

    cout << inData << "---------" << endl;

    json inDataJson = json::parse(inData);

    string codeIN = inDataJson["code"];
    string keyIN = inDataJson["key"];

    HCBinaryTree* huffmanCodeIn = new HCBinaryTree;

    string inDataResult = huffmanCodeIn->decodeString(codeIN,keyIN);

    cout<<inDataResult<<endl;

    return inData;
}




