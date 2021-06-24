#include <iostream>
#include "SFML/Graphics.hpp"
#include "Display/Display.h"
#include "RAID/Books/Converter.h"
#include "RAID/Books/XOR.h"
#include "RAID/DiskNode.h"
#include "RAID/ControllerNode.h"
using namespace sf;

int main() {

    //Display display;
//    Converter * converter = new Converter();
//    XOR * axor = new XOR();
//    string result1 = converter->convertToBin("hola");
//    string result2 = converter->convertToBin("owoo");
//    string result3 = converter->convertToBin("uwuu");
//
//    //converter->getString(result);
//
//    string array[3] = {result1, result2, result3};
//    string parity = axor->generateParity(array);
//
//    cout << "Info de paridad: " << parity << endl;
//
//    string array2[3] = {parity, result2, result3};
//    string lostinfo = axor->getLostInfo(array2);
//    cout << "Info perdad: " << converter->getString(lostinfo) << endl;

    //DiskNode * disk = new DiskNode("../DiskArray/", "DiscoPrueba");

    ControllerNode * controller = new ControllerNode();
    controller->createFile("S", "hola como estas");
    string contentFile = controller->getFileContentByName("S");
    cout << "Contenido del archivo: " << contentFile << endl;

    remove("../DiskArray/Disk1");
    controller->checkDisks();
    contentFile = controller->getFileContentByName("S");
    cout << "Contenido del archivo despues de borrar: " << contentFile << endl;

    controller->createFile("D", "adios, me voy");
    contentFile = controller->getFileContentByName("D");
    cout << "Contenido del segundo archivo: " << contentFile << endl;

    controller->modifyFIle("D", "Bueno, ya me fui");
    contentFile = controller->getFileContentByName("D");
    cout << "Contenido del segundo archivo modificado: " << contentFile << endl;

    return 0;
}


