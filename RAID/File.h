//
// Created by anthony on 20/6/21.
//

#ifndef PROYECTO_III_FILE_H
#define PROYECTO_III_FILE_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class File {
public:
    string path;
    string filename;
    string currentText;
    File(string path, string filename, string currentText);
    void updateText(string newText);
};


#endif //PROYECTO_III_FILE_H
