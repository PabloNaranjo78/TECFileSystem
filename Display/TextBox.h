//
// Created by joel on 24/6/21.
//

#ifndef PROYECTO_III_TEXTBOX_H
#define PROYECTO_III_TEXTBOX_H

#include "SFML/Graphics.hpp"
#include <iostream>
#pragma once

using namespace sf;
using namespace std;

class TextBox {

    private:
        int posx, posy, width, height, fsize, charlim, currchar;
        bool selected;
        RectangleShape area;
        Text text;
        Font font;

    public:

        /**
         * @brief Constructor de la clase textbox, recibe posicion, largo y alto, ajuste para la letra.
         * @param Posx
         * @param Posy
         * @param Width
         * @param Height
         * @param Fsize
         */
        TextBox(int Posx, int Posy, int Width, int Height, int Fsize);

        /**
        * @brief Metodo para generar el area y texto iniciales del cuadro de texto.
        */
        void Build();

        /**
         * @brief Metodo para ver si el cuadro esta seleccionado, retorna true o false
         * @return bool
         */
        bool isSelected();

        /**
         * @brief Metodo para escribir lo que introduzca el usuario con el teclado
         * @param val
         */
        void Write(char val);

        /**
         * @brief Metodo que se encarga de colocar en pantalla el cuadro y el texto. Recibe el puntero a la ventana.
         * @param win
         */
        void Draw(RenderWindow* win);

        /**
         * @brief Metodo que revisa la posicion donde se haya dado click en la ventana para activar o desactivar el cuadro de texto.
         * @param x
         * @param y
         */
        void CheckClick(int x, int y);

        /**
         * @brief Metodo para eliminar la ultima letra del texto en el objeto.
         */
        void Delete();

        /**
         *
         * @return
         */
        string GetString();
};


#endif //PROYECTO_III_TEXTBOX_H
