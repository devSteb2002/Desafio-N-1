#include <iostream>
#include <windows.h>
#include "juego.h"
#include "tablero.h"

using namespace std;

int main()
{
    //variables globales
    TipoTablero tipotablero;


    bool juegoActivo = true;
    unsigned short alto;
    unsigned short ancho;
    void* tablero = nullptr; // sin tipo (para optimizar con el entero)


    inicioJuego(&alto, &ancho);
    validarTipoTablero(tablero, &ancho, &alto , tipotablero);
    inicializarTableroEnceros(tablero, tipotablero, &alto);

    system("cls");

    while (juegoActivo){
        moverCursor(0,0);
        dibujarTablero(&alto, tablero, tipotablero);




        break;

    }




    //cout << "\nTABLERO INICIAL\n";
   // dibujarTablero(tablero, tipotablero, &alto, &ancho);



    if(tablero == nullptr) {
        cout << "ERROR: tablero no inicializado!\n";
    }

    //NOTA: verificacion de que si se guarden la cantidad de bits de acuerdo al dato

   /* for (short i = 0; i < alto; i++) {
        switch(tipotablero) {

        case CHAR: {
            cout << "es char " << endl;
            char *filas = static_cast<char*>(tablero);
            cout << sizeof(filas[i]) * 8 << endl;
            break;
        }

        case SHORT:{
            short * filas = static_cast<short*>(tablero);
            cout << sizeof(filas[i]) * 8 << endl;
            break;
        }

        case INT:
            break;

        case LONG64:
            break;
        }
   } */


    return 0;
}
