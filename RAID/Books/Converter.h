//
// Created by anthony on 19/6/21.
//

#ifndef PROYECTO_III_CONVERTER_H
#define PROYECTO_III_CONVERTER_H

#include <string>
#include <math.h>
#include <iostream>

using namespace std;
class Converter {
public:
    Converter(){}
    string convertToBin(string input);
    string convertInt(int num);
    string getString(string binInput);
    string checkSize(string input);
    string convertChar(string bin);

};


#endif //PROYECTO_III_CONVERTER_H
