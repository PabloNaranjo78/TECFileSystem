//
// Created by joel on 22/6/21.
//

#ifndef PROYECTO_III_FILESPRITE_H
#define PROYECTO_III_FILESPRITE_H
#include "SFML/Graphics.hpp"
#include "string"

using namespace sf;
using namespace std;

class fileSprite {


    private:
        string fileName;
        Texture* imageTexture;
        Sprite* imageSprite;

    public:
        /**
         * @brief constructor del fileSprite
         */
        fileSprite();

        /**
         * @brief constructor del fileSprite indicando la posición en x y la posición en y
         * @param x
         * @param y
         */
        fileSprite(int x, int y);

        /**
         * @brief Permite dibujar el ícono del archivo en la ventana especificada
         * @param my_window
         */
        void draw(RenderWindow *my_window);

        /**
         * @brief retorna el nombre del archivo
         * @return fileName
         */
        const string &getFileName() const;

        /**
         * @brief permite cambiar el archivo al que hace referencia
         * @param fileName
         */
        void setFileName(const string &fileName);

        /**
         * @brief retorna
         * @return ImageTexture
         */
        Texture *getImageTexture() const;

        /**
         * @brief Permite cambiar la textura de la imagen
         * @param imageTexture
         */
        void setImageTexture(Texture *imageTexture);

        /**
         * @brief Retorna el sprite de la imagen
         * @return ImageSprite
         */
        Sprite *getImageSprite() const;

        /**
         * @brief permite cambiar el sprite de la imagen
         * @param imageSprite
         */
        void setImageSprite(Sprite *imageSprite);

};


#endif //PROYECTO_III_FILESPRITE_H
