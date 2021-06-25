//
// Created by pablo on 23/6/21.
//

#ifndef PROYECTO_III_CHARACTERLIST_H
#define PROYECTO_III_CHARACTERLIST_H
#include "iostream"
#include "../CharacterListNode/CharacterListNode.h"

using namespace std;
/**
 * @brief Clase encargada llevar registro de los caracteres y cuantas veces se repiten para el HuffmanCode
 */
class CharacterList {
public:
    /**
     * @brief Constructor de la clase CharacterList, encargada de llevar registro de los caracteres y cantidad de estos que componen el string a codificar
     */
    CharacterList();
    /**
     * @brief Método encargado de añadir un string a la lista, esta la procesa y agrega uno a uno los caracteres
     * @param newCharacters string con los datos que se desean almacenar en esta lista enlazada
     */
    void addCharacters(string newCharacters);
    /**
     * @brief Método encargado de imprimir en consola la lista enlazada y su contenido
     */
    void printList();
    /**
     * Método encargado de revisar que la lista esté ordenada
     * @return retorna true si está ordenada, false en caso contrario.
     */
    bool checkSort();
    /**
     * @brief Método encargado de la impresión del árbol en consola.
     */
    void printTree();
    /**
     * @brief Método para eliminar un elemento específico de la lista enlazada
     * @param character que se desea eliminar de la lista
     */
    void deleteNode(string character);
    /**
     * @brief Elimina el último elemento de la lista enlazada
     */
    void deleteFirstNode();
    /**
     * @brief Añade un nodo a la lista enlazada
     * @param newNode Nodo a añadir a la lista enlazada
     */
    void addNode(CharacterListNode* newNode);
    /**
     * @brief Método para obtener elementos de la lista enlazada
     * @return primer nodo de la lista enlazada
     */
    CharacterListNode* getList();
    /**
     * @brief Método encargado de retornar nodo de la lista enlazada
     * @return retorna el nodo que se tiene en este momento de primero.
     */
    CharacterListNode* getNode();
private:
    CharacterListNode* ListNode = nullptr;
    /**
     * @brief Aplica bubble sort a la lista enlazada para ordenarla.
     */
    void sortList();
};


#endif //PROYECTO_III_CHARACTERLIST_H
