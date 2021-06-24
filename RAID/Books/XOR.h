//
// Created by anthony on 19/6/21.
//

#ifndef PROYECTO_III_XOR_H
#define PROYECTO_III_XOR_H

#include <string>
#include <iostream>

using namespace std;

/**
 * Clase para realizar la operacion de XOR para obtener paridad o informacion perdida
 */

class XOR {
private:
    /**
     * Aplica la operacion de XOR a tres strings
     * @param info un array de 3 strings del mismo tamano
     * @return la representacion binaria del string que ocurre al aplicar XOR
     */
    string useXOR(string info[3]);
public:
    /**
     * Constructor de la clase
     */
    XOR(){}
    /**
     * Genera la paridad para los tres discos
     * @param info un array de 3 strings del mismo tamano
     * @return informacion de paridad asociada a dichos strings
     */
    string generateParity(string info[3]);
    /**
     * Regenera informacion perdida al eliminar un disco
     * @param info un array de 3 strings del mismo tamano
     * @return informacion perdida para segun los tres strings
     */
    string getLostInfo(string info[3]);

};


#endif //PROYECTO_III_XOR_H
