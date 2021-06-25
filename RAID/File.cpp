//
// Created by anthony on 20/6/21.
//

#include "File.h"


File::File(string path, string filename, string currentText) {
    this->path = path;
    this->filename = filename;
    this->currentText = currentText;
    // Create and open a text file
    ofstream MyFile(this->path+this->filename);

    // Write to the file
    MyFile << this->currentText;

    // Close the file
    MyFile.close();
}

void File::updateText(string newText) {
    this->currentText = newText;
    // Create and open a text file
    ofstream MyFile(this->path+this->filename);

    // Write to the file
    MyFile << this->currentText;

    // Close the file
    MyFile.close();
}

string File::getText() {
    // Create a text string, which is used to output the text file
    string readText;
    string out = "";

// Read from the text file
    ifstream readFile(this->path);

// Use a while loop together with the getline() function to read the file line by line
    while (getline (readFile, readText)) {
        // Output the text from the file
        out += readText;
        cout << "Texto leido: " << readText;
    }

// Close the file
    readFile.close();

    return out;
}