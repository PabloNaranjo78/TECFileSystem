//
// Created by pablo on 23/6/21.
//

#include "CharacterList.h"

using namespace std;

void CharacterList::addCharacters(string newCharacters) {
    int characters = newCharacters.length();

    for (int i = 0; i < characters; ++i) {

        if (ListNode == nullptr){
            ListNode = new CharacterListNode;
            string tempS;
            tempS = newCharacters[i];
            ListNode->addData(tempS);
        }
        else{
            bool notInList = true;

            CharacterListNode **tempSearch = &ListNode;
            while ((*tempSearch)!= nullptr){
                string tempS;
                tempS = newCharacters[i];
                if ((*tempSearch)->getCharacter()==tempS){
                    notInList = false;
                    (*tempSearch)->addCounter();
                    break;
                }
                tempSearch = &(*tempSearch)->nextNode;

            }

            if (notInList){
            CharacterListNode* temp = ListNode;
            ListNode = new CharacterListNode;
            string tempS;
            tempS = newCharacters[i];
            ListNode->addData(tempS);
            ListNode->nextNode = temp;
            ListNode->nextNode->prevNode = ListNode;
            }
        }
    }

    printList();

    sortList();


}

CharacterList::CharacterList() {

}

void CharacterList::printList() {
    CharacterListNode* temp = ListNode;
    while(temp!= nullptr){
        cout<<temp->getCharacter()<<"->"<<temp->getCounter()<<endl;
        temp = temp->nextNode;
    }
}

void CharacterList::sortList() {
    CharacterListNode **pointerNode = &ListNode;
    if (!checkSort()){
        while((*pointerNode)->nextNode!= nullptr){
            if ((*pointerNode)->getCounter()>(*pointerNode)->nextNode->getCounter()){
                string tempData;
                int tempCounter;
                tempData = (*pointerNode)->getCharacter();
                tempCounter = (*pointerNode)->getCounter();

                (*pointerNode)->setCounter((*pointerNode)->nextNode->getCounter());
                (*pointerNode)->setData((*pointerNode)->nextNode->getCharacter());
                (*pointerNode)->nextNode->setCounter(tempCounter);
                (*pointerNode)->nextNode->setData(tempData);

            }
            pointerNode = &(*pointerNode)->nextNode;
            }
        sortList();
    }

  //  if (ListNode->leftSon != nullptr and ListNode->rightSon != nullptr)cout<<ListNode->leftSon->getCounter()<<"hhh"<<ListNode->rightSon->getCounter()<<endl;

}

bool CharacterList::checkSort() {
    bool sort = true;
    CharacterListNode **pointerNode = &ListNode;
    while((*pointerNode)->nextNode!= nullptr){
        if ((*pointerNode)->getCounter()>(*pointerNode)->nextNode->getCounter()){
            sort = false;
            break;
        }
        pointerNode = &(*pointerNode)->nextNode;
    }
    return sort;
}

CharacterListNode* CharacterList::getList() {
    return ListNode;
}

void CharacterList::deleteNode(string character) {
    CharacterListNode **pointerNode = &ListNode;
    while((*pointerNode)->nextNode!= nullptr){
        cout<<(*pointerNode)->getCharacter()<<endl;
        if ((*pointerNode)->nextNode->getCharacter() == character){
            if ((*pointerNode)->nextNode->nextNode == nullptr) {
                (*pointerNode)->nextNode = nullptr;
                break;
                }
            else{
            (*pointerNode)->nextNode = (*pointerNode)->nextNode->nextNode;}
        }
        pointerNode = &(*pointerNode)->nextNode;
    }
}

void CharacterList::addNode(CharacterListNode* newNode) {
    CharacterListNode* temp = ListNode;
    ListNode = newNode;
    ListNode->nextNode = temp;

    sortList();
}

CharacterListNode* CharacterList::getNode() {
    return ListNode;
}

void CharacterList::deleteFirstNode() {
    ListNode = ListNode->nextNode;
}

void CharacterList::printTree() {
    if (ListNode->leftSon == nullptr){
        cout<<"EEEEEE"<<endl;
//        cout<<ListNode->leftSon->getCharacter()<<endl;
    }
}
