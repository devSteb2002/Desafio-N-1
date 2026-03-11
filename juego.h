#ifndef JUEGO_H
#define JUEGO_H

#include "validaciones.h"
void  inicioJuego(unsigned short *alto, unsigned short *ancho);
void inicializarTableroEnceros(void *& tablero, TipoTablero&  tipotablero, const unsigned short *alto);

const int TAM_PIEZA = 4;


struct Pieza {
    char forma[TAM_PIEZA][TAM_PIEZA];
};


void cargarPiezas(Pieza piezas[7]);
void mostrarPieza(Pieza &p);

#endif // JUEGO_H


