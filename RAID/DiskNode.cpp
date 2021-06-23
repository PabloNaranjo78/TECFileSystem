//
// Created by anthony on 20/6/21.
//

#include "DiskNode.h"

DiskNode::DiskNode(string previousPath, string diskId) {
    this->path = previousPath+diskId;
    this->diskId = diskId;
    this->counter = 0;
    this->createDirectory();
}

void DiskNode::createDirectory() {
    if (mkdir(this->path.c_str(), 0777) == -1)
        cout << "Directory failed to create" << endl;
    else
        cout << "Directory created" << endl;

}
void DiskNode::createFile(string filename, string info) {

    if (this->counter < 10){

        File * file = new File(this->path+"/", filename, info);
        this->files[this->counter] = file;
        this->counter++;

    }else {
        cout << "maximo de archivos alcanzado" << endl;
    }

}

string DiskNode::getFileContent(string filename) {
    string result = "";
    for (int i=0; i<4; i++){
        if (filename == files[i]->filename){
            cout << "Archivo encontrado" << endl;
            result = files[i]->currentText;
            cout << "string en el archivo: "<< result << endl;
            break;
        }
    }
    return result;
}

void DiskNode::updateFileContent(string fileName, string newText) {
    for (int i=0; i<4; i++){
        if (fileName == files[i]->filename){
            files[i]->updateText(newText);
        }
    }
}