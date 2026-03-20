#include "tablero.h"
#include "piezas.h"
#include <iostream>
#include <windows.h>

using namespace std;

void moverCursor(const unsigned short y, const unsigned short  x){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void inicializarTableroEnceros(void *& tablero, TipoTablero&  tipotablero, const unsigned short* alto){

    for (unsigned short i = 0; i < *alto; i++){
        switch (tipotablero) {
        case CHAR_: {
            char *filas = static_cast<char*>(tablero);
            filas[i] = 0;
            break;
        }
        case SHORT_: {
            short* filas = static_cast<short*>(tablero);
            filas[i] = 0;
            break;
        }
        case INT_: {
            int* filas = static_cast<int*>(tablero);
            filas[i] = 0;
            break;
        }
        case LONG64_: {
            long long* filas = static_cast<long long*>(tablero);
            filas[i] = 0;
            break;
        }
        default:
            break;
        }
    }
}


void dibujarTablero(const unsigned short *alto, void * tablero, TipoTablero tipotablero, int px, int py, int tipoPieza) {
    const short* bitsPieza = obtenerDatosPieza(tipoPieza);
    int bitsPorFila = (tipotablero == CHAR_) ? 8 : (tipotablero == SHORT_) ? 16 : (tipotablero == INT_) ? 32 : 64;

    for (unsigned short i = 0; i < *alto; i++) {
        long long filaTablero = 0;
        // Extraer valor de la fila según el tipo
        if (tipotablero == CHAR_) filaTablero = static_cast<char*>(tablero)[i];
        else if (tipotablero == SHORT_) filaTablero = static_cast<short*>(tablero)[i];
        else if (tipotablero == INT_) filaTablero = static_cast<int*>(tablero)[i];
        else filaTablero = static_cast<long long*>(tablero)[i];

        if ((filaTablero & ((1ULL << bitsPorFila) - 1)) == ((1ULL << bitsPorFila) - 1)){ //verificar filas llenas

            for (int k = i; k > 0; k--) {

                if (tipotablero == CHAR_) {
                    unsigned char* t = (unsigned char*)tablero;
                    t[k] = t[k - 1];
                }
                else if (tipotablero == SHORT_) {
                    unsigned short* t = (unsigned short*)tablero;
                    t[k] = t[k - 1];
                }
                else if (tipotablero == INT_) {
                    unsigned int* t = (unsigned int*)tablero;
                    t[k] = t[k - 1];
                }
                else {
                    unsigned long long* t = (unsigned long long*)tablero;
                    t[k] = t[k - 1];
                }
            }
        }

        for (int c = bitsPorFila - 1; c >= 0; c--) {
            bool dibujoPieza = false;

            // Verificar si en esta celda (i, c) hay un bit de la pieza móvil
            if (i >= py && i < py + 4 && c >= px && c < px + 4) {
                if ((*(bitsPieza + (i - py)) >> (c - px)) & 1) {
                    cout << "X"; // Pieza móvil
                    dibujoPieza = true;                  
                }
            }
            if (!dibujoPieza) {
               // bool  bit = (filaTablero >> c) & 1;
              //  cout << bit;

               cout << (((filaTablero >> c) & 1) ? "#" : ".");

            }
        }
        cout << endl;
    }



}
