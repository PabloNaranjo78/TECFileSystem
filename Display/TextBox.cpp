//
// Created by joel on 24/6/21.
//

#include "TextBox.h"


TextBox::TextBox(int Posx, int Posy, int Width, int Height, int Fsize) {
    posy = Posy;
    posx = Posx;
    width = Width;
    height = Height;
    fsize = Fsize;
    charlim = 50;
    currchar = 0;

    Build();
}


void TextBox::Build() {

    RectangleShape box(Vector2f(width,height));
    box.setPosition(posx,posy);
    box.setFillColor(Color(128,128,128));

    if (selected){
        box.setOutlineColor(Color::White);
        box.setOutlineThickness(4);
    } else{
        box.setOutlineColor(Color(255,255,255,0));
    }

    area = box;

    if (!font.loadFromFile("../Fonts/FontdinerSwanky.ttf")) cout << "Failed to load font" <<endl;

    text.setFont(font);
    text.setCharacterSize(fsize);
    text.setColor(Color::White);
    text.setPosition(Vector2f(posx+5,posy+5));
    text.setString("");

}


bool TextBox::isSelected() {
    return selected;
}


void TextBox::Write(char val) {

    if (currchar < charlim){
        string character = string(1,val);
        string valstr = text.getString();
        valstr += character;
        text.setString(valstr);
        currchar += 1;
    }
}


void TextBox::Draw(RenderWindow* win) {
    win->draw(area);
    win->draw(text);
}


void TextBox::CheckClick(int x, int y) {

    if (posx < x && x < posx + width && posy < y && y < posy + height){

        selected = true;
        area.setOutlineColor(Color::White);
        area.setOutlineThickness(4);

    } else {

        selected = false;
        area.setOutlineColor(Color(255,255,255,0));
    }

}


void TextBox::Delete() {
    if (text.getString() != ""){
        std::string valstr = text.getString();
        valstr.erase(valstr.end() - 1,valstr.end());
        text.setString(valstr);
        currchar -= 1;
    }
}

std::string TextBox::GetString() {
    return text.getString();
}
