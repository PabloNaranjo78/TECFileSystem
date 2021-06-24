//
// Created by joel on 24/6/21.
//

#ifndef PROYECTO_III_BUTTON_H
#define PROYECTO_III_BUTTON_H

#include <SFML/Graphics.hpp>
#pragma once

using namespace sf;
using namespace std;

/**
 * @brief Declaracion de la clase boton, la cual define un area y un texto que cuando se da click en su posicion retorna true.
 *  Puede activarse y desactivarse.
 */
class Button {

    private:

        int posx, posy, width, height, fsize;
        Color bgcolor;
        string text = "";
        Text sText;
        Font font;
        RectangleShape area;
        Color color;
        bool enabled = true;

    public:

        /**
         * @brief Consiste en el constructor del boton, recibe los datos para su posicion, ancho y alto, ajustes de letra, texto
         * del boton y el color del area del fondo de este.
         * @param Posx
         * @param Posy
         * @param Width
         * @param Height
         * @param Fsize
         * @param Text
         * @param Color
         */
        Button(int Posx, int Posy, int Width, int Height, int Fsize, string Text, Color Color);

        /**
         * @brief Metodo build que se encarga de construir las figuras y asignar los valores respectivos a cada una apenas se crea
         * el texto. Utiliza una formula para que el texto siempre se encuentre centrado en el boton.
         */
        void Build();

        /**
        * @brief Metodo que se encarga de revisar si se da click en el area del boton, recibe la posicion "x" y "y" donde sucedio el click.
        * @param x
        * @param y
        * @return
        */
        bool Clicked(int, int);

        /**
        * @brief Revisa si la posicion del mouse es encima del boton, para resaltar el color del borde.
        * @param x
        * @param y
        */
        void MouseOver(int, int);

        /**
        * Dibuja tanto el area como el texto del boton en la interfaz, recibe el puntero de la ventana de GUI.
        * @param win
        */
        void Draw(RenderWindow*);

        /**
        * Retorna true o false dependiendo del caso para verificar si el boton se encuentra desactivado.
        * @return
        */
        bool isEnabled();

        /**
        * Activa o desactiva el boton segun el valor booleano que reciba del flag.
        * @param flag
        */
        void SetEnabled(bool flag);

        /**
         * Devuelve el valor de Posx
         * @return Posx
         */
        int getPosx() const;

        /**
        * Devuelve el valor de Posx
        * @return Posx
        */
        int getPosy() const;

        /**
        * Devuelve el valor de Posx
        * @return Posx
        */
        int getWidth() const;

        /**
        * Devuelve el valor de Posx
        * @return Posx
        */
        int getHeight() const;
};


#endif //PROYECTO_III_BUTTON_H
