#include "validaciones.h"
#include <iostream>
#include <limits>
#include <cstdint>

using namespace std;

bool  esEntero(){

    bool esEnteroCin = true;

    if (cin.fail()){
        cout << "Tipo de dato invalido, vuelva a intentar." << endl;
        esEnteroCin = false;
    }

    cin. clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return esEnteroCin;
}

bool  esMultDeOcho(const unsigned short* numero){
    if (*numero % 8 != 0){
        cout << "El numero debe ser multiplo de 8, vuelva a intentar." << endl;
        return false;
    }

    return true;
}

bool  excedeLimite(const unsigned short* numero){
    if (*numero > 64){
        cout << "El numero deber ser menor o igual a 64, vuelva a intentar." << endl;
        return true;
    }

    if (*numero < 8){
        cout << "El numero deber ser mayor o igual que 8, vuelva a intentar." << endl;
        return true;
    }

    return false;
}

bool validacionNumeroIngresado(const unsigned short *numero){
        if (!esEntero()) return false;
        if (!esMultDeOcho(numero)) return false;
        if (excedeLimite(numero)) return false;

        return true;
}

void validarTipoTablero(void *& tablero, const unsigned short *ancho, const unsigned short *alto,  TipoTablero&  tipotablero){

    if (tablero != nullptr){
        switch(tipotablero) {
            case CHAR:    delete[] static_cast<char*>(tablero); break;
            case SHORT:   delete[] static_cast<short*>(tablero); break;
            case INT:     delete[] static_cast<int*>(tablero); break;
            case LONG64:  delete[] static_cast<long long*>(tablero); break;
        }

        tablero = nullptr;
    }

    if (*ancho == 8) {
        tablero = new char[*alto];
        tipotablero = CHAR;
    }
    else if (*ancho <= 16 ){
        tablero = new short[*alto];
        tipotablero = SHORT;
    }
    else if (*ancho <= 32) {
        tablero = new int[*alto];
        tipotablero = INT;
    }
    else if (*ancho <= 64) {
        tablero = new long long[12];
        tipotablero = LONG64;
    }
}
