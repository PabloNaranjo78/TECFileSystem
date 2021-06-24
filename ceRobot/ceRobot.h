//
// Created by joel on 23/6/21.
//

#ifndef PROYECTO_III_CEROBOT_H
#define PROYECTO_III_CEROBOT_H

#include "SFML/Graphics.hpp"
#include <dirent.h>
#include "string"
#include <fstream>
#include <iostream>

using namespace sf;
using namespace std;

class ceRobot {

    private:
        vector<string> elements;
        vector<string> contentElements;
        string pathBooks = "../Libros";

public:
        ceRobot(string path);
        vector<string> getFiles(string path);
        string readFile(string filePath);
};


#endif //PROYECTO_III_CEROBOT_H
