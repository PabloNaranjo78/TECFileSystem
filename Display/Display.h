//
// Created by joel on 18/6/21.
//

#ifndef PROYECTO_III_DISPLAY_H
#define PROYECTO_III_DISPLAY_H

#include "SFML/Graphics.hpp"
#include <dirent.h>
#include "fileSprite.h"
#include "../ServerSocket/Json/json.hpp"
#include "../ceRobot/ceRobot.h"
#include "../ServerSocket/Client/Client.h"
using namespace sf;
using namespace std;
using json = nlohmann::json;

class Display {

    private:
        Vector2i pos_mouse;
        vector<fileSprite*> files;
        vector<string> elements;
        string pathBooks = "../Libros";
        string pathDisks = "../DiskArray";
        bool find = false;
        RenderWindow* my_window;
        Client client;

public:
        /**
         * @brief Constructor del display, muestra la aplicación gráfica
         */
        Display();

        /**
         * @brief Obtiene la posición del mouse
         */
        void checkMousePosition();

        /**
         * @brief Crea la cantidad de archivos especificada
         * @param aux
         */
        void setImage(int aux);

        /**
         * @brief Muestra los archivos que se encuentren en la ruta especificada
         */
        void displayImages();

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

        void sendCurrentFiles(ceRobot* robot);
};


#endif //PROYECTO_III_DISPLAY_H
