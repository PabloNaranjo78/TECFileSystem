//
// Created by joel on 23/6/21.
//

#ifndef PROYECTO_III_CESEARCH_H
#define PROYECTO_III_CESEARCH_H

#include "SFML/Graphics.hpp"
#include <dirent.h>
#include "string"
#include <fstream>
#include <iostream>

using namespace sf;
using namespace std;

class ceSearch {

    private:

        vector<string> contentElements;
        vector<string> elements;
        vector<string> elementsToShow;
        vector<string> contentElementsToShow;

    public:
            ceSearch();
            void doSearch(string text);
            void setElements(string fileName, string fileContent);

            const vector<string> &getContentElements() const;
            void setContentElements(const vector<string> &contentElements);
            const vector<string> &getElements() const;
            void setElements1(const vector<string> &elements);
            const vector<string> &getElementsToShow() const;
            void setElementsToShow(const vector<string> &elementsToShow);
            const vector<string> &getContentElementsToShow() const;
            void setContentElementsToShow(const vector<string> &contentElementsToShow);
};


#endif //PROYECTO_III_CESEARCH_H
