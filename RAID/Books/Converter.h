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
private:
    string checkSize(string input);
    string convertChar(string bin);
    string convertInt(int num);

public:
    Converter(){}
    string convertToBin(string input);
    string getString(string binInput);


};


#endif //PROYECTO_III_CONVERTER_H
