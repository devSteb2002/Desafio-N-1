#include "juego.h"
#include <iostream>

using namespace std;

void  inicioJuego(unsigned short *alto, unsigned short *ancho){

    cout << "==========================================" << endl;
    cout << " TETRIS (nuevo juego)                                                                  " << endl;
    cout << "==========================================" << endl;

    do {
        // validacion del alto del tablero
        //Nota: esta validacion se esta haciendo hasta un maximo de 64
        //porque 64 es la maxima capacidad de bits que puede tener un entero
        //ademas un tablero de tetris de mas de 64 filas y columnas es excesivo
         cout << "Ingrese el alto del tablero: ";
         cin >> *alto;
         if (validacionNumeroIngresado(alto)) break;

    } while (true);

    do {
        // validacion del ancho del tablero
        cout << "Ingrese el ancho del tablero: ";
        cin >> *ancho;
      if (validacionNumeroIngresado(ancho)) break;

    } while (true);


}

void inicializarTableroEnceros(void *& tablero, TipoTablero&  tipotablero, const unsigned short* alto){


    for (unsigned short i = 0; i < *alto; i++){
        switch (tipotablero) {
        case CHAR: {
            char *filas = static_cast<char*>(tablero);
            filas[i] = 0;
            break;
        }
        case SHORT: {
            short* filas = static_cast<short*>(tablero);
            filas[i] = 0;
            break;
        }
        case INT: {
            int* filas = static_cast<int*>(tablero);
            filas[i] = 0;
            break;
        }
        case LONG64: {
            long long* filas = static_cast<long long*>(tablero);
            filas[i] = 0;
            break;
        }
        default:
            break;
        }
    }


}

void cargarPiezas(Pieza piezas[7]){

    char I[4][4] = {
        {0,0,0,0},
        {1,1,1,1},
        {0,0,0,0},
        {0,0,0,0}
    };

    char O[4][4] = {
        {0,1,1,0},
        {0,1,1,0},
        {0,0,0,0},
        {0,0,0,0}
    };

    char T[4][4] = {
        {0,1,0,0},
        {1,1,1,0},
        {0,0,0,0},
        {0,0,0,0}
    };

    char S[4][4] = {
        {0,1,1,0},
        {1,1,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };

    char Z[4][4] = {
        {1,1,0,0},
        {0,1,1,0},
        {0,0,0,0},
        {0,0,0,0}
    };

    char J[4][4] = {
        {1,0,0,0},
        {1,1,1,0},
        {0,0,0,0},
        {0,0,0,0}
    };

    char L[4][4] = {
        {0,0,1,0},
        {1,1,1,0},
        {0,0,0,0},
        {0,0,0,0}
    };

    char (*temp[7])[4] = {I,O,T,S,Z,J,L};

    for(int p = 0; p < 7; p++){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                piezas[p].forma[i][j] = temp[p][i][j];
            }
        }
    }
}
void mostrarPieza(Pieza &p){

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){

            if(p.forma[i][j] == 1)
                cout << "# ";
            else
                cout << ". ";
        }

        cout << endl;
    }
}


