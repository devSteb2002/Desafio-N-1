#ifndef VALIDACIONES_H
#define VALIDACIONES_H

enum TipoTablero { CHAR_, SHORT_, INT_, LONG64_ };

bool  esEntero();
bool  esMultDeOcho(const unsigned short* numero);
bool  excedeLimite(const unsigned short* numero);
bool validacionNumeroIngresado(const unsigned short *numero, bool esAlto = false);
void validarTipoTablero(void *& tablero, const unsigned short *ancho, const unsigned short *alto,  TipoTablero&  tipotablero);
bool esTeclaValida(char tecla);
bool esPosicionValida(int px, int py, int anchoPieza, int altoPieza, TipoTablero tipo, const unsigned short* altoTablero);
bool hayColision(void* tablero, TipoTablero tipo, int px, int py, const short* piezaActual, const unsigned short* altoTablero, const unsigned short* anchoTablero);
void eliminarMemoria(void *& tablero, TipoTablero&  tipotablero);


#endif // VALIDACIONES_H
