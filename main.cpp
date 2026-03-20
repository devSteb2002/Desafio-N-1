#include <iostream>
#include <windows.h>
#include "juego.h"
#include "tablero.h"
#include "validaciones.h" 
#include "piezas.h"

using namespace std;

int main(){
    //variables globales
    TipoTablero tipotablero;


    bool juegoActivo = true;
    unsigned short alto;
    unsigned short ancho;
    void* tablero = nullptr; // sin tipo (para optimizar con el entero)


    int px, py, idPieza;
    char tecla;



    inicioJuego(&alto, &ancho);
    validarTipoTablero(tablero, &ancho, &alto , tipotablero);
    inicializarTableroEnceros(tablero, tipotablero, &alto);
    generarPiezaAleatoria(&alto, tablero, tipotablero);

    system("cls");
    prepararNuevaPieza(px, py, idPieza, ancho);




    while (juegoActivo){
        moverCursor(0, 0);
        dibujarTablero(&alto, tablero, tipotablero, px, py, idPieza);

        cout << "\n(A/D) Mover, (S) Bajar, (Q) Salir: ";
        cin >> tecla;

        if (tecla == 'q' || tecla == 'Q') {
            juegoActivo = false;
        } 
        else if (tecla == 'd' || tecla == 'D') {
            // A = IZQUIERDA (px - 1)
            if (!hayColision(tablero, tipotablero, px - 1, py, obtenerDatosPieza(idPieza), &alto, &ancho)) {
                px--;
            }
        }
        else if (tecla == 'a' || tecla == 'A') {
            // D = DERECHA (px + 1)
            if (!hayColision(tablero, tipotablero, px + 1, py, obtenerDatosPieza(idPieza), &alto, &ancho)) {
                px++;
            }
        }
        else if (tecla == 's' || tecla == 'S') {
            // S = ABAJO (py + 1)
            if (!hayColision(tablero, tipotablero, px, py + 1, obtenerDatosPieza(idPieza), &alto, &ancho)) {
                py++;
            } else {
                fijarPiezaEnTablero(tablero, tipotablero, px, py, idPieza);
                prepararNuevaPieza(px, py, idPieza, ancho);
            }
        }




    return 0;
}
