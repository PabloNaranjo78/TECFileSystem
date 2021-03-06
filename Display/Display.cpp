//
// Created by joel on 18/6/21.
//

#include <iostream>
#include <fstream>
#include "Display.h"
#include "../ceRobot/ceRobot.h"
#include "TextBox.h"
#include "Button.h"
#include "../ceSearch/ceSearch.h"
#include "../RAID/ControllerNode.h"

Display::Display() {

    cout << "inicializando----------------" << endl;
    ceRobot robot = ceRobot(pathBooks);
    bool firstime = true;
    if (firstime){
        sendCurrentFiles(&robot);
        firstime = false;
    }


    find = false;
    ceSearch search = ceSearch();


    my_window = new RenderWindow(VideoMode(1100, 900), "TEC File System", Style::Titlebar | Style::Close );
    this->my_window->setFramerateLimit(30);
    Event event;

    setImage(getFiles(pathBooks).size());


    TextBox textBox = TextBox(250,250,620,50,20);
    Button button = Button(400,350,300,50,25,"Search",Color::Blue);
    Button buttonBack = Button(10,10,100,100,25,"Back",Color(150,150,150,0));

    //bool iniciado = true;

    while (my_window->isOpen()) {
        my_window->clear();

        if(find){
            buttonBack.Draw(my_window);
            displayImages();
        } else {
            textBox.Draw(my_window);
            button.Draw(my_window);
        }

        my_window->display();

        while (my_window->pollEvent(event)) {

            switch (event.type) {

                case Event::Closed:
                    my_window->close();

                case Event::TextEntered:
                    if (textBox.isSelected()){
//                        cout<<event.text.unicode<<endl;
                        if (event.text.unicode == 8){
                            textBox.Delete();
                        } else if (event.text.unicode == 13 || event.text.unicode == 0){
                            textBox.CheckClick(0,0);
                        } else {
                            char letter = static_cast<char>(event.text.unicode);
                            textBox.Write(letter);
                        }
                    }

                case Event::MouseButtonReleased:
                    checkMousePosition();

                    if(find){

                        if(buttonBack.getPosx()<pos_mouse.x && pos_mouse.x<buttonBack.getPosx()+buttonBack.getWidth()){
                            if(buttonBack.getPosy()<pos_mouse.y && pos_mouse.y<buttonBack.getPosy()+buttonBack.getHeight()) {
                                //iniciado = true;
                                find = false;
                            }
                        }

                        for (int i = 0; i < elements.size(); ++i) {
                            if (files[i]->getImageSprite()->getPosition().x<pos_mouse.x && pos_mouse.x<files[i]->getImageSprite()->getPosition().x + files[i]->getImageSprite()->getGlobalBounds().width){
                                if (files[i]->getImageSprite()->getPosition().y<pos_mouse.y && pos_mouse.y<files[i]->getImageSprite()->getPosition().y + files[i]->getImageSprite()->getGlobalBounds().height) {
                                    cout<<"Se presion?? el elemento: "<< i <<endl;

                                    cout<<"Archivo: "<<search.getElementsToShow()[i] <<endl;
                                    cout<<search.getContentElementsToShow()[i]<<endl;
                                }
                            }
                        }


                    } else{
                        textBox.CheckClick((int)pos_mouse.x, (int)pos_mouse.y);

                        if(button.getPosx()<pos_mouse.x && pos_mouse.x<button.getPosx()+button.getWidth()){
                            if(button.getPosy()<pos_mouse.y && pos_mouse.y<button.getPosy()+button.getHeight()) {
//                                cout<<textBox.GetString()<<endl;

                                cout << "entra" << endl;
                                json sender;
                                sender["code"] = "send";
                                string received = client->sendData("code1");
                                sleep(1);
                                cout << "Recibido en el cliente" << received << endl;

                                json parser = json::parse(received);

                                int counterJson = parser["counter"];

                                for (int i = 0; i < counterJson; i++) {
                                    search.setElements(parser["filename" + to_string(i + 1)],
                                                       parser["text" + to_string(i + 1)]);
                                    cout << "Valores asociados: " << parser["filename" + to_string(i + 1)] << ", " << parser["text" + to_string(i + 1)] << endl;
                                }
                                search.doSearch(textBox.GetString());
                                setImage(search.getElementsToShow().size());

                                find = true;

                            }
                        }
                    }

            }
        }
    }
}

void Display::checkMousePosition() {

    this->pos_mouse = Mouse::getPosition(*this->my_window);
    this->pos_mouse = (Vector2i) this->my_window->mapPixelToCoords(this->pos_mouse);
}

void Display::setImage(int aux){
    files = vector<fileSprite*>();

    int x=0, y=100;

    for (int i = 1; i <= aux; ++i) {

        fileSprite *file = new fileSprite();

        if((x+file->getImageSprite()->getGlobalBounds().width)<my_window->getSize().x-150){
            x += 100;
        } else{
            x = 100;
            y += 100;
        }

        file->getImageSprite()->setPosition(x,y);
        files.push_back(file);
    }
}

void Display::displayImages(){

    if(find){
        for (int i = 0; i < files.size(); ++i) {
            my_window->draw(*files[i]->getImageSprite());

//        my_window->draw(*files[i]->getPathFile());
        }
    } else {

    }
}


vector<string> Display::getFiles(string path){

    DIR *direction;
    struct dirent *element;
    string elem;

    if((direction = opendir(path.c_str()))){
        while ((element = readdir(direction))){
            elem = element->d_name;
            if (elem!="." && elem!="..")
//                cout<<elem<<"  ";
                elements.push_back(elem);
        }
        //cout<<endl;
    }
    closedir(direction);
    return elements;
}

string Display::readFile(string filePath) {

    string fileContent;
    string aux = "";

    ifstream txtFile;
    txtFile.open(filePath, ios::in);

    if (txtFile.fail()){cout<<"No se pudo abrir el archivo"<<endl;}

    while (!txtFile.eof()){
        getline(txtFile,fileContent);
        aux+= "\n" + fileContent;
    }
    return aux;
}

void Display::sendCurrentFiles(ceRobot* robot) {

    json stacker;
    int fileNum = robot->getElements().size();
    string filesArray[fileNum];
    string namesArray[fileNum];
    for (int i=0; i<fileNum; i++){
        namesArray[i] = robot->getElements()[i];
        filesArray[i] = robot->getContentElements()[i];
    }
    stacker["counter"] = fileNum;
    for (int i=0; i<fileNum; i++){
        stacker["filename"+to_string(i+1)] = namesArray[i];
        stacker["text"+to_string(i+1)] = filesArray[i];
    }
    cout << "String a enviar" << endl;
    string to_send = stacker.dump();
    cout << to_send << endl;
    client->sendData(to_send);


}