#include <iostream>
#include "validaciones.h"
#include "juego.h"

using namespace std;

int main()
{
    //variabales globales
    TipoTablero  tipotablero;

    unsigned short alto;
    unsigned short ancho;
    void* tablero = nullptr; // sin tipo (para optimizar con el entero)

    inicioJuego(&alto, &ancho);
    validarTipoTablero(tablero, &ancho, &alto , tipotablero);

    cout << tipotablero << endl;

    if(tablero == nullptr) {
        cout << "ERROR: tablero no inicializado!\n";

    }
    for (short i = 0; i < alto; i++) {
        switch(tipotablero) {
        case CHAR: {
            cout << "es char " << endl;

        }

        }
    }

    return 0;
}
