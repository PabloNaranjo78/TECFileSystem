//
// Created by pablo on 23/6/21.
//

#ifndef PROYECTO_III_CHARACTERLIST_H
#define PROYECTO_III_CHARACTERLIST_H
#include "iostream"
#include "../CharacterListNode/CharacterListNode.h"

using namespace std;

class CharacterList {
public:
    CharacterList();
    void addCharacters(string newCharacters);
    void printList();
    bool checkSort();
    void printTree();
    void deleteNode(string character);
    void deleteFirstNode();
    void addNode(CharacterListNode* newNode);
    CharacterListNode* getList();
    CharacterListNode* getNode();
private:
    CharacterListNode* ListNode = nullptr;
    void sortList();
};


#endif //PROYECTO_III_CHARACTERLIST_H
