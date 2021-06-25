#include <iostream>
#include "SFML/Graphics.hpp"
#include "Display/Display.h"
#include "HuffmanCode/CharacterCounter/CharacterList/CharacterList.h"
#include "HuffmanCode/HCBinaryTree/HCBinaryTree.h"

#include "RAID/Books/Converter.h"
#include "RAID/Books/XOR.h"
#include "RAID/DiskNode.h"
#include "RAID/ControllerNode.h"
#include "ServerSocket/Server/Server.h"
#include "ServerSocket/Client/Client.h"

using namespace sf;
using namespace std;
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

//    ControllerNode * controller = new ControllerNode();
//    controller->createFile("S", "hola como estas");
//    string contentFile = controller->getFileContentByName("S");
//    cout << "Contenido del archivo: " << contentFile << endl;
//
//    remove("../DiskArray/Disk1");
//    controller->checkDisks();
//    contentFile = controller->getFileContentByName("S");
//    cout << "Contenido del archivo despues de borrar: " << contentFile << endl;
//
//    controller->createFile("D", "adios, me voy");
//    contentFile = controller->getFileContentByName("D");
//    cout << "Contenido del segundo archivo: " << contentFile << endl;
//
//    controller->modifyFIle("D", "Bueno, ya me fui");
//    contentFile = controller->getFileContentByName("D");
//    cout << "Contenido del segundo archivo modificado: " << contentFile << endl;

    /*
      CharacterList list;
      list.addCharacters("LOREM IPSUM DOLOR SIT AMET, CONSECTETUR ADIPISCING ELIT, SED DO EIUSMOD TEMPOR INCIDIDUNT UT LABORE ET DOLORE MAGNA ALIQUA. UT ENIM AD MINIM VENIAM, QUIS NOSTRUD EXERCITATION ULLAMCO LABORIS NISI UT ALIQUIP EX EA COMMODO CONSEQUAT");
  cout<<endl;

      cout<<endl;
      list.deleteFirstNode();
      cout<<endl;
      list.printList();
      cout<<endl;
      HCBinaryTree tree;
      tree.createTree(list);
    //  cout<<tree.encodeString("LOREM IPSUM DOLOR SIT AMET, CONSECTETUR ADIPISCING ELIT, SED DO EIUSMOD TEMPOR INCIDIDUNT UT LABORE ET DOLORE MAGNA ALIQUA. UT ENIM AD MINIM VENIAM, QUIS NOSTRUD EXERCITATION ULLAMCO LABORIS NISI UT ALIQUIP EX EA COMMODO CONSEQUAT",
                 //             "((((L/D)/(S/N))/(I/(U/M)))/(((A/T)/((((B/G)/Q)/C)/E))/( /(O/(R/(P/((./X)/,)))))))");
  */
   // HCBinaryTree tree;
   // tree.createTree(list);
   // cout<<tree.decodeString("000011101111010110111110010111110001001100111110000111100000111011110110001001010011101000011110111001111111111010101111000110010101110101100110111001011011110110100000010101111100100010101010100011101000111010110000010100111111111100010101100011100001111011010110100110001001111110000111010011011011111111011101111011001000111010101000010100001011000111001110011010011100000100010100001110111101011110101110011100001111000001110111101011110011110001010001001110001101000000001010100101101000111111001100110100111010110011010011111010000001110011101000110100111110101100110101000011111111111101010010110010001011000111110001010011111001100001110101111111101101111110101010101001100010010101110001111001100000000010000111101011110110000010001010000111011110010001011000110100010010110011010011101000000001010100101100101111101101011111111011101011100011010101111001110111111000011110110101011110001100101011101001011010001001",
           //                 "((((L/D)/(S/N))/(I/(U/M)))/(((A/T)/((((B/G)/Q)/C)/E))/( /(O/(R/(P/((./X)/,)))))))");

    Server server;
    Client client;
    cout<<"Cliente"<<endl;
    cout<<client.sendData("Viva cristo rey")<<endl;

return 0;
}


