#ifndef VALIDACIONES_H
#define VALIDACIONES_H

enum TipoTablero { CHAR, SHORT, INT, LONG64 };

bool  esEntero();
bool  esMultDeOcho(const unsigned short* numero);
bool  excedeLimite(const unsigned short* numero);
bool validacionNumeroIngresado(const unsigned short *numero);
void validarTipoTablero(void *& tablero, const unsigned short *ancho, const unsigned short *alto,  TipoTablero&  tipotablero);
bool posicionValida(int fila, int columna, unsigned short alto, unsigned short ancho);

bool hayColision(void* tablero, TipoTablero tipo,int fila,int columna,unsigned short ancho);

#endif // VALIDACIONES_H
