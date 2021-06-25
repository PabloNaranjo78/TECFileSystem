//
// Created by pablo on 22/6/21.
//

#include "HCBinaryTree.h"
#include "../CharacterCounter/CharacterListNode/CharacterListNode.h"
#include "../CharacterCounter/CharacterList/CharacterList.h"


HCBinaryTree::HCBinaryTree() {
}

string HCBinaryTree::createTree(CharacterList inList) {
    treeListNode = inList;
    while(treeListNode.getNode()->nextNode!= nullptr) {
        CharacterListNode *newNode = new CharacterListNode();
        newNode->setCounter(treeListNode.getList()->getCounter() + treeListNode.getList()->nextNode->getCounter());
        newNode->setData("("+treeListNode.getNode()->getCharacter()+"/"+treeListNode.getNode()->nextNode->getCharacter()+")");

        treeListNode.deleteFirstNode();
        treeListNode.deleteFirstNode();
        treeListNode.addNode(newNode);
    }
    //treeListNode.printList();
    cout<<treeListNode.getNode()->getCharacter()<<endl;
    return treeListNode.getNode()->getCharacter();

//    treeListNode.printList();

    //  printTree();
  //  printTree();
  cout<<treeListNode.getNode()->ChildrenData<<endl;
}

string HCBinaryTree::encodeString(string stringList, string key) {
    int num = 0;
    string temp = "";
    string result[2][countCharacters(key)];

    for (int i = 0; i < key.length(); ++i) {
        if (key[i]=='('){
            temp+="0";
        }else if (key[i]=='/'){
            temp = temp.substr(0,temp.length()-1);
            temp+= "1";
        } else if (key[i]==')'){
            temp = temp.substr(0,temp.length()-1);
        }
        if (key[i]!='(' and key[i]!=')' and key[i]!='/'){
            cout<<key[i]<<"->"<<temp<<endl;
            result[0][num]= key[i];
            result[1][num] = temp;
            num++;
        }
    }

    string finalResult = "";
    for (int i = 0; i < stringList.length(); ++i) {
        for (int j = 0; j < countCharacters(key); ++j) {
            string tempS;
            tempS = stringList[i];
            if (tempS == result[0][j]){
                finalResult+=result[1][j];
            }
        }
    }
    return finalResult;

}

int HCBinaryTree::countCharacters(string stringList) {
    int result = 0;
    for (int i = 0; i < stringList.length(); ++i) {
        if (stringList[i]!='/' and stringList[i]!='(' and stringList[i]!=')'){
            result++;
        }
    }
    return result;
}

string HCBinaryTree::decodeString(string code, string key) {

    int num = 0;
    string temp = "";
    string result[2][countCharacters(key)];

    for (int i = 0; i < key.length(); ++i) {
        if (key[i]=='('){
            temp+="0";
        }else if (key[i]=='/'){
            temp = temp.substr(0,temp.length()-1);
            temp+= "1";
        } else if (key[i]==')'){
            temp = temp.substr(0,temp.length()-1);
        }
        if (key[i]!='(' and key[i]!=')' and key[i]!='/'){
            cout<<key[i]<<"->"<<temp<<endl;
            result[0][num]= key[i];
            result[1][num] = temp;
            num++;
        }
    }

    string tempNum = "";
    string finalResult = "";
    while (code.length()>0){
        tempNum+= code.substr(0,1);
        code = code.substr(1);
        for (int i = 0; i < countCharacters(key); ++i) {
            if (tempNum == result[1][i]){
                finalResult+= result[0][i];
                tempNum = "";
            }
        }
    }

    return finalResult;
}

