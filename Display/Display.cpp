//
// Created by joel on 18/6/21.
//

#include "Display.h"

Display::Display() {

    my_window = new RenderWindow(VideoMode(1100, 900), "TEC File System");
    bool aux = true;

    while (aux) {
        my_window->clear();
        my_window->display();

    }
}
