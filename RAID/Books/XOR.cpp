//
// Created by anthony on 19/6/21.
//

#include "XOR.h"

string XOR::useXOR(string *info) {
    string result = "";

    for (int i = 0; i<3; i++){
        cout << info[i] << endl;
    }

    for (int i = 0; i<info[0].length(); i++){
        if (info[0][i] == info[1][i]){
            result += "0";
        }else{
            result += "1";
        }
    }
    string result_final = "";
    for (int i = 0; i<info[0].length(); i++){
        if (result[i] == info[2][i]){
            result_final += "0";
        }else{
            result_final += "1";
        }
    }

    return result_final;
}

string XOR::generateParity(string *info) {
    return this->useXOR(info);
}

string XOR::getLostInfo(string *info) {
    return this->useXOR(info);
}