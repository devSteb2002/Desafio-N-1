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
void dibujarTablero(void *tablero, TipoTablero tipotablero,
                    const unsigned short *alto,
                    const unsigned short *ancho) {

    for(unsigned short i = 0; i < *alto; i++) {

        long long fila = 0;

        // Extraer la fila según el tipo
        switch(tipotablero) {
        case CHAR:
            fila = static_cast<char*>(tablero)[i];
            break;
        case SHORT:
            fila = static_cast<short*>(tablero)[i];
            break;
        case INT:
            fila = static_cast<int*>(tablero)[i];
            break;
        case LONG64:
            fila = static_cast<long long*>(tablero)[i];
            break;
        }

        // Imprimir cada bit de la fila
        for(int j = *ancho - 1; j >= 0; j--) {
            if ((fila >> j) & 1)
                cout << "# ";
            else
                cout << ". ";
        }

        cout << endl;
    }
}


bool puedeColocarPieza(void* tablero,TipoTablero tipo,Pieza pieza,int fila,int columna,unsigned short alto,unsigned short ancho)
{
    for(int i = 0; i < TAM_PIEZA; i++)
    {
        for(int j = 0; j < TAM_PIEZA; j++)
        {
            if(pieza.forma[i][j] == 1)
            {
                int filaTablero = fila + i;
                int colTablero = columna + j;

                if(!posicionValida(filaTablero, colTablero, alto, ancho))
                    return false;

                if(hayColision(tablero, tipo, filaTablero, colTablero, ancho))
                    return false;
            }
        }
    }

    return true;
}
void colocarPieza(void* tablero, TipoTablero tipo,Pieza pieza,int fila,int columna,unsigned short alto,unsigned short ancho)
{

    if(!puedeColocarPieza(tablero, tipo, pieza, fila, columna, alto, ancho))
        return;

    for(int i = 0; i < TAM_PIEZA; i++)
    {
        for(int j = 0; j < TAM_PIEZA; j++)
        {
            if(pieza.forma[i][j] == 1)
            {
                int filaTablero = fila + i;
                int colTablero = columna + j;

                switch(tipo)
                {
                case CHAR:
                {
                    char* t = static_cast<char*>(tablero);
                    t[filaTablero] |= (1 << (ancho - 1 - colTablero));
                    break;
                }

                case SHORT:
                {
                    short* t = static_cast<short*>(tablero);
                    t[filaTablero] |= (1 << (ancho - 1 - colTablero));
                    break;
                }

                case INT:
                {
                    int* t = static_cast<int*>(tablero);
                    t[filaTablero] |= (1 << (ancho - 1 - colTablero));
                    break;
                }

                case LONG64:
                {
                    long long* t = static_cast<long long*>(tablero);
                    t[filaTablero] |= (1LL << (ancho - 1 - colTablero));
                    break;
                }
                }
            }
        }
    }
}
