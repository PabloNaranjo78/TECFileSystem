//
// Created by joel on 22/6/21.
//

#include "fileSprite.h"

fileSprite::fileSprite() {

    imageTexture = new Texture;
    imageSprite = new Sprite;
    imageTexture->loadFromFile("../Display/Carpeta.png");
//    pathFile->setPosition(0,0);
//    pathFile->setString("../Display/Carpeta.png");
    imageSprite->setTexture(*imageTexture);
    imageSprite->setScale(0.03,0.03);

}

fileSprite::fileSprite(int x, int y) {
    imageTexture = new Texture;
    imageSprite = new Sprite;
    imageTexture->loadFromFile("../Display/Carpeta.png");
//    pathFile->setString("../Display/Carpeta.png");
    imageSprite->setTexture(*imageTexture);
    imageSprite->setScale(0.03,0.03);
    imageSprite->setPosition((float)x,(float)y);
}

void fileSprite::draw(RenderWindow *my_window) {
    my_window->draw(*imageSprite);
}

Texture *fileSprite::getImageTexture() const {
    return imageTexture;
}

void fileSprite::setImageTexture(Texture *imageTexture) {
    fileSprite::imageTexture = imageTexture;
}

Sprite *fileSprite::getImageSprite() const {
    return imageSprite;
}

void fileSprite::setImageSprite(Sprite *imageSprite) {
    fileSprite::imageSprite = imageSprite;
}

const string &fileSprite::getFileName() const {
    return fileName;
}

void fileSprite::setFileName(const string &fileName) {
    fileSprite::fileName = fileName;
}



