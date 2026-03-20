#ifndef TABLERO_H
#define TABLERO_H

#include "validaciones.h"

void inicializarTableroEnceros(void *& tablero, TipoTablero&  tipotablero, const unsigned short* alto);
void moverCursor(const unsigned short y, const unsigned short x);
void dibujarTablero(const unsigned short *alto, void *tablero, TipoTablero tipotablero, int px, int py, int idPieza);
#endif // TABLERO_H
