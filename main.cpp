#include <iostream>
#include "validaciones.h"
#include "juego.h"

using namespace std;

int main()
{
    //variables globales
    TipoTablero tipotablero;

    unsigned short alto;
    unsigned short ancho;
    void* tablero = nullptr; // sin tipo (para optimizar con el entero)

    Pieza piezas[7];

    inicioJuego(&alto, &ancho);
    validarTipoTablero(tablero, &ancho, &alto , tipotablero);
    inicializarTableroEnceros(tablero, tipotablero, &alto);

    cargarPiezas(piezas);

    cout << "\nTABLERO INICIAL\n";
    dibujarTablero(tablero, tipotablero, &alto, &ancho);

    cout << "\nPieza de prueba:\n";
    mostrarPieza(piezas[2]);

    if(tablero == nullptr) {
        cout << "ERROR: tablero no inicializado!\n";
    }

    //NOTA: verificacion de que si se guarden la cantidad de bits de acuerdo al dato

    for (short i = 0; i < alto; i++) {
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
    }

    return 0;
}
