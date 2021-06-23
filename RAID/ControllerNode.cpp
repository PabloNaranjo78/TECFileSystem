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

}

string ControllerNode::fillFile(string currentBin) {

    for (int i=0; i<80-currentBin.length(); i++){
        currentBin += "0";
    }
    return currentBin;
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

        }else if (i == 1 && text.length() < 0){

            this->disks[i]->createFile(fileName, this->fillFile(""));
            cout << "Segundo disco escrito" << endl;

        }else if (i == 2){

            this->disks[i]->createFile(fileName, this->fillFile(converter->convertToBin(fileName+to_string(originalLength))));
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