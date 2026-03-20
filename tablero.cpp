#include "tablero.h"
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


void dibujarTablero(const unsigned short *alto, void *tablero, TipoTablero tipotablero, int px, int py, int tipoPieza) {
    const short* bitsPieza = obtenerDatosPieza(tipoPieza);
    int bitsPorFila = (tipotablero == CHAR_) ? 8 : (tipotablero == SHORT_) ? 16 : (tipotablero == INT_) ? 32 : 64;

    for (unsigned short i = 0; i < *alto; i++) {
        long long filaTablero = 0;
        // Extraer valor de la fila según el tipo
        if (tipotablero == CHAR_) filaTablero = static_cast<char*>(tablero)[i];
        else if (tipotablero == SHORT_) filaTablero = static_cast<short*>(tablero)[i];
        else if (tipotablero == INT_) filaTablero = static_cast<int*>(tablero)[i];
        else filaTablero = static_cast<long long*>(tablero)[i];

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
                cout << (((filaTablero >> c) & 1) ? "#" : ".");
            }
        }
        cout << endl;
    }
}
