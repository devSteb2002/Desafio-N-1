#ifndef TABLERO_H
#define TABLERO_H

#include "validaciones.h"

void inicializarTableroEnceros(void *& tablero, TipoTablero&  tipotablero, const unsigned short* alto);
void moverCursor(const unsigned short y, const unsigned short x);
void dibujarTablero(const unsigned short *alto, void *& tablero, TipoTablero&  tipotablero);
void generarPiezaAleatoria(const unsigned short *alto, void *& tablero);
const short* obtenerReferenciaPieza(int id);
void caerPieza(int* fila);
void proyectarPieza(void* tablero, TipoTablero tipo, const short* pieza, int f, int c);

#endif // TABLERO_H
