//
// Created by anthony on 20/6/21.
//

#ifndef PROYECTO_III_CONTROLLERNODE_H
#define PROYECTO_III_CONTROLLERNODE_H

#include <string>
#include <iostream>
#include "DiskNode.h"
#include "Books/Converter.h"
#include "Books/XOR.h"
#include <dirent.h>
#include <errno.h>


using namespace std;

class ControllerNode {
private:
    string initialPath;
    int counter;
    DiskNode * disks[4]; //Almacena 5 discos de 100 bytes cada uno para una capacidad total de 400 bytes (considerando paridad y metadata)
    void initDisks();
public:
    ControllerNode();
    bool checkDisks();
    void recoverDisk(int diskNum);
    void createFile(string fileName, string text);
    void modifyFIle(string fileName, string updatedText);
    void getFileContentByName(string fileName);
    string fillFile(string currentBin);
};


#endif //PROYECTO_III_CONTROLLERNODE_H
