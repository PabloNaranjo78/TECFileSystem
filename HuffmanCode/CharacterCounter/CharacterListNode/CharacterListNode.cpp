//
// Created by pablo on 23/6/21.
//

#include "CharacterListNode.h"

CharacterListNode::CharacterListNode() {

}

void CharacterListNode::addData(string _character) {
    addCounter();
    character = _character;
}

void CharacterListNode::addCounter() {
    counter++;
}

string CharacterListNode::getCharacter() {
    return character;
}

int CharacterListNode::getCounter() {
    return counter;
}

void CharacterListNode::setCounter(int _counter) {
    counter = _counter;
}

void CharacterListNode::setData(string _character) {

    character = _character;

}

void CharacterListNode::setChildren(CharacterListNode* rNode, CharacterListNode* lNode) {
    leftSon = lNode;
    rightSon = rNode;
}



