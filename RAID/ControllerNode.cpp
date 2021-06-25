//
// Created by anthony on 20/6/21.
//

#include "ControllerNode.h"

ControllerNode::ControllerNode() {
    this->initialPath = "../DiskArray/";
    this->initDisks();
    this->setSocketInfo();
    this->server = new Server();
    this->server->port = stoi(this->port);
    this->getInfoFromServer();
}

void ControllerNode::initDisks() {
    for (int i=0; i<4; i++){
        this->disks[i] = new DiskNode(this->initialPath, "Disk"+ to_string(i));
    }
}

bool ControllerNode::checkDisks() {
    DIR * dir = NULL;
    bool result = true;
    for (int i = 0; i < 4; i++) {
        dir = opendir((this->initialPath+"Disk"+ to_string(i)).c_str());
        if (dir) {
            /* Directory exists. */
            closedir(dir);
        } else if (ENOENT == errno) {
            /* Directory does not exist. */
            cout << "directory does not exist" << endl;
            result = false;
            this->recoverDisk(i);
            break;

        } else {
            /* opendir() failed for some other reason. */
            cout << "directory failed to open" << endl;
        }

    }
    return result;
}

void ControllerNode::recoverDisk(int diskNum) {
    string currentInfo[3];
    int j = 0;
    string currentFileName;
    int maxFiles;
    XOR * restorer = new XOR();
    for (int i =0; i<4; i++){
        if (i != diskNum){
            maxFiles = this->disks[i]->counter;
            break;
        }
    }
    for (int x=0; x<maxFiles; x++) {
        j = 0;
        currentFileName = "";
        for (int i = 0; i < 4; i++) {
            if (i != diskNum) {
                currentFileName = this->disks[i]->files[x]->filename;
                currentInfo[j] = this->disks[i]->getFileContent(currentFileName);
                j++;
            }
        }
        this->disks[diskNum]->createFile(currentFileName, restorer->getLostInfo(currentInfo));
    }

}

string ControllerNode::fillFile(string currentBin) {

    for (int i=0; i<80-currentBin.length(); i++){
        currentBin += "0";
    }
    return currentBin;
}


string ControllerNode::getFileContentByName(string fileName) {
    this->checkDisks();
    Converter * converter = new Converter();
    string content = "", bytes_to_read;
    int readBytes = 0;
    bytes_to_read = converter->getString(this->disks[2]->getFileContent(fileName));
    cout << "Bytes para leer: " << bytes_to_read << endl;
    readBytes = stoi(bytes_to_read);
    string rawContent = this->disks[0]->getFileContent(fileName) + this->disks[1]->getFileContent(fileName);
    for (int i=0; i<readBytes; i++){
        content += converter->getString(rawContent.substr(i*8, 8));
    }
    return content;

}

void ControllerNode::getInfoFromServer() {

    string response = this->server->sendData("files");
    json parser;
    parser = json::parse(response);

    int counterJson = parser["counter"];
    string fileName[counterJson], info[counterJson];
    for (int i=1; i<counterJson; i++){
        fileName[i] = parser["filename"+to_string(i)];
        info[i] = parser["text"+to_string(i)];
        this->createFile(fileName[i], info[i]);
    }

}

void ControllerNode::sendCurrentFiles() {
    this->checkDisks();
    json stacker;
    int fileNum = this->disks[0]->counter;
    string filesArray[fileNum];
    string namesArray[fileNum];
    for (int i=0; i<fileNum; i++){
        namesArray[i] = this->disks[0]->files[i]->filename;
        filesArray[i] = this->getFileContentByName(this->disks[0]->files[i]->filename);
    }
    stacker["counter"] = fileNum;
    for (int i=0; i<fileNum; i++){
        stacker["filename"+to_string(i+1)] = namesArray[i];
        stacker["text"+to_string(i+1)] = filesArray[i];
    }
    string to_send = stacker.dump();
    this->server->sendData(to_send);
}

void ControllerNode::createFile(string fileName, string text) {
    this->checkDisks();
    int originalLength = text.length();
    XOR * xor_tool = new XOR();
    Converter * converter = new Converter();
    for (int i=0; i<4; i++){
        if (i == 0 && text.length() >= 10) {
            this->disks[i]->createFile(fileName, converter->convertToBin(text.substr(0, 10)));
            text = text.substr(10, text.length()-10);
            cout << "Primer disco escrito" << endl;
        }
        else if (i == 0 && text.length() < 10){

            this->disks[i]->createFile(fileName, this->fillFile(converter->convertToBin(text)));
            text = "";
            cout << "Primer disco escrito" << endl;

        }else if (i == 1 && text.length() > 0 && text.length() <= 10){

            this->disks[i]->createFile(fileName, this->fillFile(converter->convertToBin(text)));
            cout << "Segundo disco escrito" << endl;

        }else if (i == 1 && text.length() <= 0){

            this->disks[i]->createFile(fileName, this->fillFile(""));
            cout << "Segundo disco escrito" << endl;

        }else if (i == 1 && text.length() > 10){

            cout << "Se excede el almacenamiento disponible por archivo (20 caracteres)" << endl;
            break;

        }else if (i == 2){

            this->disks[i]->createFile(fileName, this->fillFile(converter->convertToBin(to_string(originalLength))));
            cout << "Tercer disco escrito" << endl;

        }else if (i == 3){
            cout << "Buscando paridad" << endl;
            string currentInfo[3] = {this->disks[0]->getFileContent(fileName), this->disks[1]->getFileContent(fileName), this->disks[2]->getFileContent(fileName)};
            string parity = xor_tool->generateParity(currentInfo);
            this->disks[i]->createFile(fileName, parity);
            cout << "Cuarto disco escrito" << endl;
        }
    }
}


void ControllerNode::modifyFIle(string fileName, string updatedText) {
    int originalLength = updatedText.length();
    XOR * xor_tool = new XOR();
    Converter * converter = new Converter();
    for (int i=0; i<4; i++){
        if (i == 0 && updatedText.length() >= 10) {
            this->disks[i]->updateFileContent(fileName, converter->convertToBin(updatedText.substr(0, 10)));
            updatedText = updatedText.substr(10, updatedText.length()-10);
            cout << "Primer disco escrito" << endl;
        }
        else if (i == 0 && updatedText.length() < 10){

            this->disks[i]->updateFileContent(fileName, this->fillFile(converter->convertToBin(updatedText)));
            updatedText = "";
            cout << "Primer disco escrito" << endl;

        }else if (i == 1 && updatedText.length() > 0 && updatedText.length() <= 10){

            this->disks[i]->updateFileContent(fileName, this->fillFile(converter->convertToBin(updatedText)));
            cout << "Segundo disco escrito" << endl;

        }else if (i == 1 && updatedText.length() <= 0){

            this->disks[i]->updateFileContent(fileName, this->fillFile(""));
            cout << "Segundo disco escrito" << endl;

        }
        else if (i == 1 && updatedText.length() > 10){

            cout << "Se excede el almacenamiento disponible por archivo (20 caracteres)" << endl;
            break;

        }else if (i == 2){

            this->disks[i]->updateFileContent(fileName, this->fillFile(converter->convertToBin(to_string(originalLength))));
            cout << "Tercer disco escrito" << endl;

        }else if (i == 3){
            cout << "Buscando paridad" << endl;
            string currentInfo[3] = {this->disks[0]->getFileContent(fileName), this->disks[1]->getFileContent(fileName), this->disks[2]->getFileContent(fileName)};
            string parity = xor_tool->generateParity(currentInfo);
            this->disks[i]->updateFileContent(fileName, parity);
            cout << "Cuarto disco escrito" << endl;
        }
    }
}

void ControllerNode::setSocketInfo() {

    XMLDocument doc;
    XMLError errorResult = doc.LoadFile("../RAID/config.xml");

    cout << "Se abre el archivo" << endl;

    XMLNode* root = doc.FirstChildElement("Parameters");
    XMLElement *ip = root->FirstChildElement("ip");
    XMLElement *port = root->FirstChildElement("port");
    this->ip = ip->GetText();
    this->port = port->GetText();
    this->ip = stoi(this->ip);

    cout << "-------------------------------------------" << endl;
    cout << "IP: " << this->ip << endl;
    cout << "Port: " << this->port << endl;
    cout << "-------------------------------------------" << endl;

}