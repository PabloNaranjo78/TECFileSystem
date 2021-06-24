//
// Created by anthony on 20/6/21.
//

#include "ControllerNode.h"

ControllerNode::ControllerNode() {
    this->initialPath = "../DiskArray/";
    this->initDisks();

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

void ControllerNode::createFile(string fileName, string text) {
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