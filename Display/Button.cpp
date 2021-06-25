//
// Created by joel on 24/6/21.
//

#include "Button.h"


Button::Button(int Posx, int Posy, int Width, int Height, int Fsize , string Text, Color Color) {

    posx = Posx;
    posy = Posy;
    width = Width;
    height = Height;
    text = Text;
    color = Color;
    fsize = Fsize;

    Build();

}


void Button::Build() {

    sf::RectangleShape figure(Vector2f(width,height));
    figure.setPosition(posx,posy);
    figure.setFillColor(color);
    figure.setOutlineColor(Color(0,0,0));
    figure.setOutlineThickness(3);

    font.loadFromFile("../Fonts/consolas.ttf");
    sText.setString(this->text);
    sText.setCharacterSize(fsize);
    sText.setFont(font);
    sText.setPosition(posx+(width/2-sText.getLocalBounds().width/2),posy+(height/2-sText.getLocalBounds().height/2)-8);
    sText.setFillColor(Color(255,255,255,255));

    this->area = figure;

}


void Button::Draw(RenderWindow *win) {

    win->draw(area);
    win->draw(sText);

}


int Button::getPosx() const {
    return posx;
}

int Button::getPosy() const {
    return posy;
}

int Button::getWidth() const {
    return width;
}

int Button::getHeight() const {
    return height;
}
