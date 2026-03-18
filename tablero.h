#ifndef TABLERO_H
#define TABLERO_H

#include "validaciones.h"

void inicializarTableroEnceros(void *& tablero, TipoTablero&  tipotablero, const unsigned short* alto);
void moverCursor(const unsigned short y, const unsigned short x);
void dibujarTablero(const unsigned short *alto, void *& tablero, TipoTablero&  tipotablero);
void generarPiezaAleatoria(const unsigned short *alto, void *& tablero);

#endif // TABLERO_H
