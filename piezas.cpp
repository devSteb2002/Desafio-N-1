#include"piezas.h"


const short FIGURAS[7][4] = {
    {
        0b1,
        0b1,    // Figura: Palo (I)
        0b1,
        0b1
    },
    {
        0b11,   // Figura: Cuadrado (O)
        0b11,
        0,
        0
    },
    {
        0b111,  // Figura: T
        0b010,
        0b010,
        0
    },
    {
        0b011,  // Figura: S
        0b110,
        0,
        0
    },
    {
        0b110,  // Figura: Z
        0b011,
        0,
        0
    },
    {
        0b010,  // Figura: J
        0b010,
        0b110,
        0
    },
    {
        0b010,  // Figura: L
        0b010,
        0b011,
        0
    }
};

const short* obtenerDatosPieza(int indice) {
    if (indice >= 0 && indice < 7) {
        return *(FIGURAS + indice); 
    }
    return nullptr;
}
