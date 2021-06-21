//
// Created by anthony on 19/6/21.
//

#include "Converter.h"

string Converter::convertToBin(string input) {

    string s(input);
    char p[s.length()];
    for (int i = 0; i < sizeof(p); i++) {
        p[i] = s[i];
        cout << p[i] << " ";
    }
    cout << endl;
    int inArray[sizeof(p)];
    for (int i=0; i < sizeof(p); i++){
        inArray[i] = p[i];
        cout << inArray[i] << " ";
    }
    cout << endl;
    string result = "";
    for (int i=0; i< s.length(); i++){
        result += this->convertInt(inArray[i]);
    }
    cout << "Resultado: " << result << endl;
    return result;

}

string Converter::convertInt(int num) {
    cout << "into function: " << endl;
    // array to store binary number
    int binaryNum[32];

    // counter for binary array
    int i = 0;
    while (num > 0) {

        // storing remainder in binary array
        binaryNum[i] = num % 2;
        num = num / 2;
        i++;

    }
    cout << "Primer paso: " << endl;
    string result = "";
    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--){
        cout << binaryNum[j];
        result += to_string(binaryNum[j]);
    }
    cout << endl;
    cout << "paso 2" << endl;
    cout << "Resultado preliminar: " << result << endl;
    result = this->checkSize(result);
    cout << "Resultado final: " << result << endl;
    return result;
}

string Converter::getString(string binInput) {
    cout << "Into string getting" << endl;
    int limit = binInput.length()/8;
    cout << "Limite: " << limit << endl;
    string result = "";
    string current = "", charAt = "";
    for (int i=0; i<limit; i++){
        current = binInput.substr(i*8, 8);
        cout << "Analizando el binario: " << current << endl;
        charAt = this->convertChar(current);
        result += charAt;
    }
    cout << "Resltados: " << result << endl;
    return result;
}

string Converter::convertChar(string bin) {
    string result = "";
    int result_int = 0;
    int binary[8];

    for (int i=0; i<8; i++){
        if (bin[i] == '1'){
            binary[i] = 1;
        }else{
            binary[i] = 0;
        }
    }

    int exp = 7;
    for (int i=0; i<8; i++){
        result_int += binary[i]*pow(2, exp);
        exp --;
    }
    cout << "result int: " << result_int << endl;
    char c_result = result_int;
    char c_array[1] = {c_result};
    result = c_array;
    return result;
}

string Converter::checkSize(string input) {
    string result = input;
    if (input.length() < 8){
        int limit = 8 - input.length();
        for (int i=0; i<limit; i++){
            result = "0" + result;
        }
    }
    return result;
}