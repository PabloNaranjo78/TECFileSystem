//
// Created by anthony on 19/6/21.
//

#ifndef PROYECTO_III_XOR_H
#define PROYECTO_III_XOR_H

#include <string>
#include <iostream>

using namespace std;

class XOR {
private:
    string useXOR(string info[3]);
public:
    XOR(){}
    string generateParity(string info[3]);
    string getLostInfo(string info[3]);

};


#endif //PROYECTO_III_XOR_H
