#include "juego.h"
#include <iostream>

using namespace std;

void  inicioJuego(unsigned short *alto, unsigned short *ancho){

    cout << "==========================================" << endl;
    cout << " TETRIS (nuevo juego)                                                                  " << endl;
    cout << "==========================================" << endl;

    do {
        // validacion del alto del tablero
        //Nota: esta validacion se esta haciendo hasta un maximo de 64
        //porque 64 es la maxima capacidad de bits que puede tener un entero
        //ademas un tablero de tetris de mas de 64 filas y columnas es excesivo
         cout << "Ingrese el alto del tablero: ";
         cin >> *alto;
         if (validacionNumeroIngresado(alto, true)) break;

    } while (true);

    do {
        // validacion del ancho del tablero
        cout << "Ingrese el ancho del tablero: ";
        cin >> *ancho;
      if (validacionNumeroIngresado(ancho)) break;

    } while (true);
}

void prepararNuevaPieza(int& px, int& py, int& tipoPieza, int anchoTablero) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 6);

    tipoPieza = dis(gen); 
    py = 0;               
    px = (anchoTablero - 4) / 2; 
}
void moverPieza(char tecla, int& px, int& py) {
    if (tecla == 'a' || tecla == 'A') {
        px++; // Izquierda
    } 
    else if (tecla == 'd' || tecla == 'D') {
        px--; // Derecha
    } 
    else if (tecla == 's' || tecla == 'S') {
        py++; // Bajar
    }
}
void fijarPiezaEnTablero(void* tablero, TipoTablero tipo, int px, int py, int idPieza) {
    
    const short* bitsPieza = obtenerDatosPieza(idPieza);
    
    if (bitsPieza == nullptr) return;

    for (int i = 0; i < 4; i++) {
        
        int filaDestino = py + i;
        
        
        unsigned long long filaDesplazada = (unsigned long long)(*(bitsPieza + i)) << px;

       
        if (tipo == CHAR_) {
            *((char*)tablero + filaDestino) |= (char)filaDesplazada;
        } 
        else if (tipo == SHORT_) {
            *((short*)tablero + filaDestino) |= (short)filaDesplazada;
        } 
        else if (tipo == INT_) {
            *((int*)tablero + filaDestino) |= (int)filaDesplazada;
        } 
        else if (tipo == LONG64_) {
            *((long long*)tablero + filaDestino) |= (long long)filaDesplazada;
        }
    }
}





