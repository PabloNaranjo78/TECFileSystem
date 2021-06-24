//
// Created by anthony on 20/6/21.
//

#ifndef PROYECTO_III_FILE_H
#define PROYECTO_III_FILE_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class File {
public:
    string path;
    string filename;
    string currentText;
    /**
     * COnstructor de la clase
     * @param path path necesario para llegar al archivo desde el disco que proviene
     * @param filename nombre del archivo
     * @param currentText texto que se desea escribir
     */
    File(string path, string filename, string currentText);
    /**
     * Actualiza el texto en un archivo
     * @param newText nuevo texto a colocar en el archivo
     */
    void updateText(string newText);
    /**
     * Retorna el texto leido en el archivo
     * @return texto que se contiene en el .txt
     */
    string getText();
};


#endif //PROYECTO_III_FILE_H
