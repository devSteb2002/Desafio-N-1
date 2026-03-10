#include "juego.h"
#include <iostream>
#include "validaciones.h"

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
