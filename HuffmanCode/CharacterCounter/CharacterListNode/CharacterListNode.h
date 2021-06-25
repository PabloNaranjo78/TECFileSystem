//
// Created by pablo on 23/6/21.
//

#ifndef PROYECTO_III_CHARACTERLISTNODE_H
#define PROYECTO_III_CHARACTERLISTNODE_H
#include "iostream"
using namespace std;
/**
 * @brief Nodos para la lista enlazada del HuffmanCode, este contiene el caracter y su frecuencia
 */
class CharacterListNode {
public:
    /**
     * @brief Constructor de la clase CharacterListNode
     */
    CharacterListNode();
    /**
     * @brief Se encarga de agregar un nuevo caracter a esta nodo
     * @param character string con el caracter a agregar
     */
    void addData(string character);
    /**
     * @brief Este método funciona para cambiar el contenido de este nodo
     * @param character caracter con el cual se desea remplazar el existente.
     */
    void setData(string character);
    /**
     * @brief Añade +1 al contador de caracteres repetidos
     */
    void addCounter();
    /**
     * @brief Se utiliza para obtener el caracter que está contenido en este nodo
     * @return retorna un string con el caracter guardado
     */
    string getCharacter();
    /**
     * @brief Retorna el contador de elementos que hay en este nodo
     * @return un entero con la cantidad de elementos
     */
    int getCounter();
    /**
     * @brief Funciona para cambiar el contador de elementos
     * @param counter entero con el cual se desea cambiar el contador del nodo
     */
    void setCounter(int counter);
    /**
     * Método para asignar los hijos a los nodos
     * @param rNode Hijo derecho
     * @param lNode Hijo izquierdo
     */
    void setChildren(CharacterListNode* rNode, CharacterListNode* lNode);
    CharacterListNode* nextNode = nullptr;
    CharacterListNode* prevNode = nullptr;

    CharacterListNode* leftSon = nullptr;
    CharacterListNode* rightSon = nullptr;

    string ChildrenData= "#";

private:
    string character;
    int counter = 0;
};


#endif //PROYECTO_III_CHARACTERLISTNODE_H
