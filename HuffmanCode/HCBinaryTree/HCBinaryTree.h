//
// Created by pablo on 22/6/21.
//

#ifndef PROYECTO_III_HCBINARYTREE_H
#define PROYECTO_III_HCBINARYTREE_H


#include "../CharacterCounter/CharacterListNode/CharacterListNode.h"
#include "../CharacterCounter/CharacterList/CharacterList.h"

class HCBinaryTree {
public:
    HCBinaryTree();
    void createTree(CharacterList inList);
    void printTree();
    string encodeString(string stringList, string key);
    string decodeString(string code, string key);
private:
    int countCharacters(string stringList);
    string printTreeAux(CharacterListNode* node);
    CharacterList treeListNode;
};


#endif //PROYECTO_III_HCBINARYTREE_H
