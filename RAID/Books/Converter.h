//
// Created by anthony on 19/6/21.
//

#ifndef PROYECTO_III_CONVERTER_H
#define PROYECTO_III_CONVERTER_H

#include <string>
#include <math.h>
#include <iostream>

using namespace std;
/**
 * Convertir bilateral de binario a string
 */
class Converter {
private:
    /**
     * Verifica el tamano deseado de un binario
     * @param input binario original
     * @return binario con 8 bits
     */
    string checkSize(string input);
    /**
     * Convierte un binario en un char
     * @param bin binario de entrada como string
     * @return char asociado
     */
    string convertChar(string bin);
    /**
     * Convierte a entero a un string que representa un binario
     * @param num Numero a convertir
     * @return string string que representa el binario
     */
    string convertInt(int num);

public:
    /**
     * Constructor de la clase
     */
    Converter(){}
    /**
     * Convierte un string a un binario (string)
     * @param input string
     * @return binario que funciona como salida
     */
    string convertToBin(string input);
    /**
     * Obtiene el string de una representacion binaria
     * @param binInput representacion binaria de los char
     * @return string que representa
     */
    string getString(string binInput);


};


#endif //PROYECTO_III_CONVERTER_H
