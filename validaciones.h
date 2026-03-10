#ifndef VALIDACIONES_H
#define VALIDACIONES_H

enum TipoTablero { CHAR, SHORT, INT, LONG64 };

bool  esEntero();
bool  esMultDeOcho(const unsigned short* numero);
bool  excedeLimite(const unsigned short* numero);
bool validacionNumeroIngresado(const unsigned short *numero);
void validarTipoTablero(void *& tablero, const unsigned short *ancho, const unsigned short *alto,  TipoTablero&  tipotablero);

#endif // VALIDACIONES_H
