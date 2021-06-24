//
// Created by joel on 23/6/21.
//


#include "ceRobot.h"

ceRobot::ceRobot(string path) {
    elements = getFiles(path);

    for (auto & element : elements) {
        contentElements.push_back(readFile(pathBooks + "/" + element));
    }

    //Enviar información de contentElements por sockets

    /*for(int i; i < elements.size(); ++i){
        cout<<elements[i]<<endl;
        cout<<contentElements[i]<<endl<<endl;
    }*/

}

vector<string> ceRobot::getFiles(string path){

    DIR *direction;
    struct dirent *element;
    string elem;

    if((direction = opendir(path.c_str()))){
        while ((element = readdir(direction))){
            elem = element->d_name;
            if (elem!="." && elem!="..")
                elements.push_back(elem);
        }
    }
    closedir(direction);
    return elements;
}

string ceRobot::readFile(string filePath) {

    string fileContent;
    string aux = "";

    ifstream txtFile;
    txtFile.open(filePath, ios::in);

    if (txtFile.fail()){cout<<"No se pudo abrir el archivo"<<endl;}

    while (!txtFile.eof()){
        getline(txtFile,fileContent);
        aux+= "\n" + fileContent;
    }
    return aux;
}
