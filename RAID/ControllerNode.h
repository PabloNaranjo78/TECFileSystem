//
// Created by anthony on 20/6/21.
//

#ifndef PROYECTO_III_CONTROLLERNODE_H
#define PROYECTO_III_CONTROLLERNODE_H

#include <string>
#include <iostream>
#include "DiskNode.h"
#include "Books/Converter.h"
#include "Books/XOR.h"
#include <dirent.h>
#include <errno.h>
#include "TinyXml/tinyxml2.h"

using namespace tinyxml2;
using namespace std;

/**
 * Constructor de la clase del controlador de nodos de disco del RAID
 */

class ControllerNode {
private:
    string ip, port;
    string initialPath;
    int counter;
    DiskNode ** disks =(DiskNode**) malloc(4*sizeof(DiskNode)); //Almacena 4 discos de 100 bytes cada uno para una capacidad total de 400 bytes (considerando paridad y metadata)
    /**
     * Meotodo para iniciar las variables necesarias para los discos
     */
    void initDisks();
    /**
     * Setea los parametros relacionados a sockets leyendo desde XML
     */
    void setSocketInfo();
public:
    /**
     * Constructor de la clase
     */
    ControllerNode();
    /**
     * Verifica si algun disco tiene una perdida de informacion
     * @return valor de verdad que indica si los 4 discos se presentan de forma integra
     */
    bool checkDisks();
    /**
     * Recupera la informacion perdida de un disco
     * @param diskNum Disco perdido
     */
    void recoverDisk(int diskNum);
    /**
     * Crea un archivo en el RAID
     * @param fileName nombre del archivo
     * @param text texto que contiene
     */
    void createFile(string fileName, string text);
    /**
     * Modifica el contenido de un archivo
     * @param fileName Nombre del archivo
     * @param updatedText string actualizado
     */
    void modifyFIle(string fileName, string updatedText);
    /**
     * Obtiene el contenido de un archivo segun su nombre
     * @param fileName nombre del archivo
     * @return texto que contiene
     */
    string getFileContentByName(string fileName);
    /**
     * Funcion auxiliar para rellenar con ceros un binario menor a 80 bits
     * @param currentBin binario actual
     * @return binario completo segun lo solicitado
     */
    string fillFile(string currentBin);
};


#endif //PROYECTO_III_CONTROLLERNODE_H
