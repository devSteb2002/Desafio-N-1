#include "tablero.h"
#include <iostream>
#include <windows.h>

using namespace std;


const short piezas[7][4] = {
    {
        0b1,
        0b1,    // Figura: Palo (I)
        0b1,
        0b1
    },
    {
        0b11,   // Figura: Cuadrado (O)
        0b11,
        0,
        0
    },
    {
        0b111,  // Figura: T
        0b010,
        0,
        0
    },
    {
        0b011,  // Figura: S
        0b110,
        0,
        0
    },
    {
        0b110,  // Figura: Z
        0b011,
        0,
        0
    },
    {
        0b010,  // Figura: J
        0b010,
        0b110,
        0
    },
    {
        0b010,  // Figura: L
        0b010,
        0b011,
        0
    }
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

void generarPiezaAleatoria(const unsigned short *alto, void *& tablero, TipoTablero tipotablero) {
    if (tablero == nullptr || alto == nullptr) return;

    static std::random_device rd; 
    static std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> dis(0, 6);

    int indicePieza = dis(gen);
    int desplazamiento = 0;

    // Calculamos cuánto desplazar los bits según el ancho del tipo de dato
    switch(tipotablero) {
        case 0: desplazamiento = (8 - 4) / 2;  break; // char: 8 bits
        case 1: desplazamiento = (16 - 4) / 2; break; // short: 16 bits
        case 2: desplazamiento = (32 - 4) / 2; break; // int: 32 bits
        case 3: desplazamiento = (64 - 4) / 2; break; // long long: 64 bits
    }

    switch(tipotablero) {
        case 0: { 
            char *filas = static_cast<char*>(tablero);
            for (int i = 0; i < 4 && i < *alto; i++) {
                // Desplazamos los bits de la pieza al centro antes del OR
                filas[i] |= (char)(piezas[indicePieza][i] << desplazamiento);
            }
            break;
        }
        case 1: { 
            short *filas = static_cast<short*>(tablero);
            for (int i = 0; i < 4 && i < *alto; i++) {
                filas[i] |= (short)(piezas[indicePieza][i] << desplazamiento);
            }
            break;
        }
        case 2: { 
            int *filas = static_cast<int*>(tablero);
            for (int i = 0; i < 4 && i < *alto; i++) {
                filas[i] |= (int)(piezas[indicePieza][i] << desplazamiento);
            }
            break;
        }
        case 3: { 
            long long *filas = static_cast<long long*>(tablero);
            for (int i = 0; i < 4 && i < *alto; i++) {
                filas[i] |= (long long)((unsigned long long)piezas[indicePieza][i] << desplazamiento);
            }
            break;
        }
    }
}
