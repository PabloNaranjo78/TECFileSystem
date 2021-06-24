//
// Created by anthony on 20/6/21.
//

#ifndef PROYECTO_III_DISKNODE_H
#define PROYECTO_III_DISKNODE_H


#include <string>
#include "File.h"
#include <bits/stdc++.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;

/**
 * Clase para las representaciones de disco, que corresponden a los nodos del controlador
 */

class DiskNode {
private:
    // IP/Port
    //int fileCounter;
    string diskId;
    /**
     * Crea un directorio para representar el disco
     */
    void createDirectory();
public:
    File ** files = (File**)malloc(10*sizeof(File)); //Se pueden guardar hasta 10 archivos por disco (100 bytes)
    int counter;
    string path;
    /**
     * Constructor de la clase
     * @param previousPath path anterior a las carpetas de disco
     * @param diskId identificador de disco
     */
    DiskNode(string previousPath, string diskId);
    /**
     * Crea un archivo que representa una parte de un libro
     * @param filename nombre del archivo
     * @param info texto que contiene
     */
    void createFile(string filename, string info);
    /**
     * Actualiza el contenido de un archivo
     * @param fileName nombre del archivo
     * @param newText texto actualizado
     */
    void updateFileContent(string fileName, string newText);
    /**
     * Retorna el contenido de un archivo
     * @param filename nombre del archivo
     * @return string que contiene el texto asociado
     */
    string getFileContent(string filename);

};


#endif //PROYECTO_III_DISKNODE_H
