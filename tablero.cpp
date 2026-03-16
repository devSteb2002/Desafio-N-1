#include "tablero.h"
#include <iostream>
#include <windows.h>

using namespace std;

const short piezas[7][4] = {
    {
        1,
        1,    // figura palo
        1,
        1,
    } ,
    {
        11,  // figura cuadrado
        11
    },
    {
        111, // figura T
        010,
        010,
    },
    {
        0111,
        0100, // figura s
        0100,
    },
    {
        1110,
        0010, // figura z
        0010,
    },
    {
        010,
        010, // figura j
        110
    },
    {
        010,
        010, // figura l
        011
    },
};

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

void dibujarTablero(const unsigned short *alto, void *& tablero, TipoTablero&  tipotablero){

    cout << "=====================" << endl;
    cout << " NUEVA PARTIDA                  " << endl;
    cout << endl;

    for (unsigned short i = 0; i < *alto; i++){

        switch(tipotablero) {
        case CHAR_:   {
             char *filas = static_cast<char*>(tablero);

            for (char  c = sizeof(char)*8 - 1; c >= 0; c--){
                if (((filas[i] >> c) & 1) == 1){
                    cout << "#";
                }else cout << ".";
            }

            cout << endl;

            break;
        }
        case SHORT_:  {
            short *filas = static_cast<short*>(tablero);

            for (short c = sizeof(short) * 8 - 1; c >= 0; c--){
                if (((filas[i] >> c) & 1) == 1){
                    cout << "#";
                }else cout << ".";
            }

              cout << endl;

            break;
        }
        case INT_:     {
            int *filas = static_cast<int*>(tablero);

            for (int c = sizeof(int) * 8 - 1; c >= 0; c--){
                if (((filas[i] >> c) & 1) == 1){
                    cout << "#";
                }else cout << ".";
            }

            cout << endl;

            break;
        }
        case LONG64_: {
            long long *filas = static_cast<long long*>(tablero);

            for (long long c = sizeof(long long) * 8 - 1; c >= 0; c--){
                if (((filas[i] >> c) & 1) == 1){
                    cout << "#";
                }else cout << ".";
            }

              cout << endl;

            break;
            }
        }
    }
}

void generarPiezaAleatoria(const unsigned short *alto, void *& tablero){

}
