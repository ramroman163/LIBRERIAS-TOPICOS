#ifndef SECPAL_H_INCLUDED
#define SECPAL_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>

#define TAM_PAL 51

typedef struct
{
    char* cursor;
    bool finSec;
}
SecPal;

typedef struct
{
    char vPal[TAM_PAL];
}
Palabra;

void secPalCrear(SecPal* sec, char* cad);
bool secPalLeer(SecPal* sec, Palabra* pal);
void secPalEscribir(SecPal* sec, const Palabra* pal);
void secPalEscribirCaracter(SecPal* sec, char caracter);
void palabraATitulo(Palabra* pal);
bool secPalFin(const SecPal* sec);
void secPalCerrar(SecPal* sec);
void palabraMostrar(const Palabra* pal);

#endif // SECPAL_H_INCLUDED
