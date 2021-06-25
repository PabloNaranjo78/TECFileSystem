//
// Created by joel on 23/6/21.
//

#include "ceSearch.h"

ceSearch::ceSearch() {

}

void ceSearch::doSearch(string text) {
    for (int i = 0; i < elements.size(); ++i) {
        if((contentElements[i].find(text) != string::npos) || (elements[i].find(text) != string::npos)){
            elementsToShow.push_back(elements[i]);
            contentElementsToShow.push_back(contentElements[i]);
        }
    }
}

void ceSearch::setElements(string fileName, string fileContent){
    elements.push_back(fileName);
    contentElements.push_back(fileContent);
}

const vector<string> &ceSearch::getContentElements() const {
    return contentElements;
}

void ceSearch::setContentElements(const vector<string> &contentElements) {
    ceSearch::contentElements = contentElements;
}

const vector<string> &ceSearch::getElements() const {
    return elements;
}

void ceSearch::setElements1(const vector<string> &elements) {
    ceSearch::elements = elements;
}

const vector<string> &ceSearch::getElementsToShow() const {
    return elementsToShow;
}

void ceSearch::setElementsToShow(const vector<string> &elementsToShow) {
    ceSearch::elementsToShow = elementsToShow;
}

const vector<string> &ceSearch::getContentElementsToShow() const {
    return contentElementsToShow;
}

void ceSearch::setContentElementsToShow(const vector<string> &contentElementsToShow) {
    ceSearch::contentElementsToShow = contentElementsToShow;
}
