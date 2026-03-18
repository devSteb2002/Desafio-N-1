#include <iostream>
#include <windows.h>
#include "juego.h"
#include "tablero.h"

using namespace std;

int main()
{
    TipoTablero tipotablero;
    bool juegoActivo = true;
    unsigned short alto;
    unsigned short ancho;
    void* tablero = nullptr; 

    
    const short* pPieza = nullptr; 
    int filaActual = 0;
    int colActual = 2; 

    inicioJuego(&alto, &ancho);
    validarTipoTablero(tablero, &ancho, &alto , tipotablero);
    
    
    pPieza = obtenerReferenciaPieza(0); 
    

    system("cls");

    while (juegoActivo){
        moverCursor(0,0);

        
        inicializarTableroEnceros(tablero, tipotablero, &alto);

 
        caerPieza(&filaActual);
        
        
        if (filaActual >= (alto - 4)) filaActual = 0; 

        proyectarPieza(tablero, tipotablero, pPieza, filaActual, colActual);

        
        dibujarTablero(&alto, tablero, tipotablero);

        Sleep(200); 
    }

    if(tablero == nullptr) {
        cout << "ERROR: tablero no inicializado!\n";
    }

    return 0;
}
