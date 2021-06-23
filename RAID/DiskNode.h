//
// Created by anthony on 20/6/21.
//

#ifndef PROYECTO_III_DISKNODE_H
#define PROYECTO_III_DISKNODE_H


#include <string>
#include "File.h"
#include <bits/stdc++.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;

class DiskNode {
private:
    // IP/Port
    File * files[10]; //Se pueden guardar hasta 10 archivos por disco (100 bytes)
    int counter;
    string diskId;
    void createDirectory();
public:
    string path;
    DiskNode(string previousPath, string diskId);
    void createFile(string filename, string info);
    void updateFileContent(string fileName, string newText);
    string getFileContent(string filename);

};


#endif //PROYECTO_III_DISKNODE_H
