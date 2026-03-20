#ifndef JUEGO_H
#define JUEGO_H

#include "validaciones.h"

void  inicioJuego(unsigned short *alto, unsigned short *ancho);
void dibujarTablero(void *tablero, TipoTablero tipotablero, const unsigned short *alto, const unsigned short *ancho);
void prepararNuevaPieza(int& px, int& py, int& tipoPieza, int anchoTablero);
void moverPieza(char tecla, int& px, int& py);
void fijarPiezaEnTablero(void *tablero, TipoTablero tipo, int px, int py, int idPieza);
void rotarPiezas(void*& tablero, const unsigned short *alto, const unsigned short *ancho, TipoTablero tipotablero, const int idPieza, int px, int py);


#endif // JUEGO_H


