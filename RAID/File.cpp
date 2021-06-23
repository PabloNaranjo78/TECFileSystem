//
// Created by anthony on 20/6/21.
//

#include "File.h"


File::File(string path, string filename, string currentText) {
    this->path = path;
    this->filename = filename;
    this->currentText = currentText;
    // Create and open a text file
    ofstream MyFile(this->path+this->filename+".txt");

    // Write to the file
    MyFile << this->currentText;

    // Close the file
    MyFile.close();
}

void File::updateText(string newText) {

}