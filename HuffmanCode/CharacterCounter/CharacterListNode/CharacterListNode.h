//
// Created by pablo on 23/6/21.
//

#ifndef PROYECTO_III_CHARACTERLISTNODE_H
#define PROYECTO_III_CHARACTERLISTNODE_H
#include "iostream"
using namespace std;
class CharacterListNode {
public:
    CharacterListNode();
    void addData(string character);
    void setData(string character);
    void addCounter();
    string getCharacter();
    int getCounter();
    void setCounter(int counter);
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
