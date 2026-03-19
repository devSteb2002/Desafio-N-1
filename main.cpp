#include <iostream>
#include <windows.h>
#include "juego.h"
#include "tablero.h"

using namespace std;

int main(){
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



    if(tablero == nullptr) {
        cout << "ERROR: tablero no inicializado!\n";
    }







    return 0;
}
