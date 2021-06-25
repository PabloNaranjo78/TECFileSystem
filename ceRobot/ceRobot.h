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
        vector<string> contentElements;
        vector<string> elements;
        string pathBooks = "../Libros";

    public:

        /**
         * @brief Retorna la lista con el nombre de los elementos
         * @return elements
         */
        const vector<string> &getElements() const;

        /**
         * @brief Retorna la lista con el contenido de los libros
         * @return contentElements
         */
        const vector<string> &getContentElements() const;


        /**
         * @brief Constructor del ceRobot recibiendo la ruta de los libros
         * @param path
         */
        ceRobot(string path);

        /**
         * @brief Retorna una lista con los nombres de los elementos
         * @param path
         * @return elements
         */
        vector<string> getFiles(string path);

        /**
         * @brief Retorna el texto contenido en el archivo de la ruta especificada
         * @param filePath
         * @return aux
         */
        string readFile(string filePath);
};


#endif //PROYECTO_III_CEROBOT_H
