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
         *
         */
        fileSprite();

        /**
         *
         * @param x posición
         * @param y
         */
        fileSprite(int x, int y);

        /**
         *
         * @param my_window
         */
        void draw(RenderWindow *my_window);

        /**
         *
         * @return
         */
        const string &getFileName() const;

        /**
         *
         * @param fileName
         */
        void setFileName(const string &fileName);

        /**
         *
         * @return
         */
        Texture *getImageTexture() const;

        /**
         *
         * @param imageTexture
         */
        void setImageTexture(Texture *imageTexture);

        /**
         *
         * @return
         */
        Sprite *getImageSprite() const;

        /**
         *
         * @param imageSprite
         */
        void setImageSprite(Sprite *imageSprite);

};


#endif //PROYECTO_III_FILESPRITE_H
