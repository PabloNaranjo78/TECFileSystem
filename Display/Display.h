//
// Created by joel on 18/6/21.
//

#ifndef PROYECTO_III_DISPLAY_H
#define PROYECTO_III_DISPLAY_H

#include "SFML/Graphics.hpp"
#include <dirent.h>
#include "fileSprite.h"

using namespace sf;
using namespace std;

class Display {

    private:
        Vector2i pos_mouse;
        vector<fileSprite*> files;
        vector<string> elements;
        string pathBooks = "../Libros";
        string pathDisks = "../DiskArray";
        bool find = false;
    public:
        RenderWindow* my_window;
        Display();
        void checkMousePosition();
        void setImage(int aux);
        void displayImages();
        vector<string> getFiles(string path);
        string readFile(int i);
        string readFile(string filePath);
};


#endif //PROYECTO_III_DISPLAY_H
