#include "validaciones.h"
#include <iostream>
#include <limits>

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

bool validacionNumeroIngresado(const unsigned short *numero, bool esAlto){

    if (esAlto){
        if (!esEntero()) return false;

        return true;
    }

    if (!esMultDeOcho(numero)) return false;
    if (excedeLimite(numero)) return false;

        return true;
}

void validarTipoTablero(void *& tablero, const unsigned short *ancho, const unsigned short *alto,  TipoTablero&  tipotablero){

    if (tablero != nullptr){
        switch(tipotablero) {
            case CHAR_:    delete[] static_cast<char*>(tablero); break;
            case SHORT_:   delete[] static_cast<short*>(tablero); break;
            case INT_:     delete[] static_cast<int*>(tablero); break;
            case LONG64_:  delete[] static_cast<long long*>(tablero); break;
        }

        tablero = nullptr;
    }

    if (*ancho == 8) {
        tablero = new char[*alto];
        tipotablero = CHAR_;
    }
    else if (*ancho <= 16 ){
        tablero = new short[*alto];
        tipotablero = SHORT_;
    }
    else if (*ancho <= 32) {
        tablero = new int[*alto];
        tipotablero = INT_;
    }
    else if (*ancho <= 64) {
        tablero = new long long[*alto];
        tipotablero = LONG64_;
    }
}


bool esTeclaValida(char tecla) {
    if (tecla >= 'A' && tecla <= 'Z') tecla |= 32; 
    return (tecla == 'a' || tecla == 's' || tecla == 'd' || tecla == 'w' || tecla == 'q');
}

bool esPosicionValida(int px, int py, int anchoPieza, int altoPieza, TipoTablero tipo, const unsigned short* altoTablero) {
    int anchoMax = 0;
    switch(tipo) {
        case CHAR_: anchoMax = 8; break;
        case SHORT_: anchoMax = 16; break;
        case INT_: anchoMax = 32; break;
        case LONG64_: anchoMax = 64; break;
    }

    if (px < 0 || (px + anchoPieza) > anchoMax) return false;
    if (py < 0 || (py + altoPieza) > *altoTablero) return false;

    return true;
}


bool hayColision(void* tablero, TipoTablero tipo, int px, int py, const short* piezaActual, const unsigned short* altoTablero, const unsigned short* anchoTablero) {

    for (int i = 0; i < 4; i++) {
        unsigned short filaPieza = piezaActual[i];

        if (filaPieza == 0) continue; 

        int filaDestino = py + i;

        if (px < 0) return true; 
        if ((unsigned int)px + 4 > *anchoTablero) {
             if (((unsigned long long)filaPieza << px) >= (1ULL << *anchoTablero)) return true;
        }

        if (filaDestino >= *altoTablero) return true; 

        if (filaDestino >= 0 && filaDestino < *altoTablero) {
            unsigned long long filaTablero = 0;
            switch(tipo) {
                case CHAR_:   filaTablero = (unsigned char)static_cast<char*>(tablero)[filaDestino]; break;
                case SHORT_:  filaTablero = (unsigned short)static_cast<short*>(tablero)[filaDestino]; break;
                case INT_:    filaTablero = (unsigned int)static_cast<int*>(tablero)[filaDestino]; break;
                case LONG64_: filaTablero = (unsigned long long)static_cast<long long*>(tablero)[filaDestino]; break;
            }

            if ((filaTablero & ((unsigned long long)filaPieza << px)) != 0) {
                return true;
            }
        }
    }
    return false;
}


void eliminarMemoria(void *& tablero, TipoTablero&  tipotablero){
    if (tablero != nullptr){
        switch(tipotablero) {
        case CHAR_:    delete[] static_cast<char*>(tablero); break;
        case SHORT_:   delete[] static_cast<short*>(tablero); break;
        case INT_:     delete[] static_cast<int*>(tablero); break;
        case LONG64_:  delete[] static_cast<long long*>(tablero); break;
        }

        tablero = nullptr;
    }
}
