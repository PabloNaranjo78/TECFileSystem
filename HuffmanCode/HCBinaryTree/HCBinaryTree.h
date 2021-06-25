//
// Created by pablo on 22/6/21.
//

#ifndef PROYECTO_III_HCBINARYTREE_H
#define PROYECTO_III_HCBINARYTREE_H


#include "../CharacterCounter/CharacterListNode/CharacterListNode.h"
#include "../CharacterCounter/CharacterList/CharacterList.h"

/**
 * @brief Clase encargada del manejo del HuffmanCode
 */
class HCBinaryTree {
public:
    /**
     * @brief Constructor de la clase.
     */
    HCBinaryTree();

    /**
     * @bref Toma la llave y el string a encriptar, procesa el string con esta llave y la comprime.
     * @param stringList string de información que se desea comprimir
     * @param key clave para realizar la compresión, esta debe ser un árbol separado por paréntesis y "/"
     * @return retorna un string donde su contenido es una cadena de 0 y 1 que representa el contenido comprimido.
     */
    string encodeString(string stringList, string key);
    /**
     * @brief Toma el contenido ya codificado y lo retorna a su estado original
     * @param code código de string comprimido compuesto de 0 y 1
     * @param key clave para realizar la descompresión, este debe ser un árbol separado por parántesis y "/"
     * @return retorna el string decodificado a partir del código de entrada
     */
    string decodeString(string code, string key);
    /**
     * @brief Método encargado de crear el árbol separado por paréntesis y "/"
     * @param inList Toma por entrada una lista enlazada ordenada que contenga la frecuencia de aparición de los carateres en el string a codificar
     * @return retorna un string con el árbol bimario separado por parántesis y "/"
     */
    string createTree(CharacterList inList);
private:
    /**
     * @brief Método encargado de contar la cantidad de caracteres que se está encriptando
     * @param stringList toma por entrada un string con el árbol
     * @return retorna un entero con la cantidad de caracteres que se están encriptando.
     */
    int countCharacters(string stringList);

    CharacterList treeListNode;
};


#endif //PROYECTO_III_HCBINARYTREE_H
