#include "SecPal.h"

#define esLetra(c) (((c) >= 'A' && (c) <= 'Z') || ((c) >= 'a' && (c) <= 'z'))

#define aMayuscula(c) (((c) >= 'a' && (c) <= 'z')? (c) - ('a' - 'A') : (c))

#define aMinuscula(c) (((c) >= 'A' && (c) <= 'Z')? (c) + ('a' - 'A') : (c))

void secPalCrear(SecPal* sec, char* cad)
{
    sec->cursor = cad;
    sec->finSec = false;
}

bool secPalLeer(SecPal* sec, Palabra* pal)
{
    while(*sec->cursor && !esLetra(*sec->cursor))
    {
        sec->cursor++;
    }

    if(!*sec->cursor)
    {
        sec->finSec = true;
        return false;
    }

    char* iPal = pal->vPal;
    while(*sec->cursor && esLetra(*sec->cursor))
    {
        *iPal = *sec->cursor;
        iPal++;
        sec->cursor++;
    }

    *iPal = '\0';

    return true;
}

void secPalEscribir(SecPal* sec, const Palabra* pal)
{
    const char* iPal = pal->vPal;

    while(*iPal)
    {
        *sec->cursor = *iPal;
        sec->cursor++;
        iPal++;
    }
}

void secPalEscribirCaracter(SecPal* sec, char caracter)
{
    *sec->cursor = caracter;
    sec->cursor++;
}

void palabraATitulo(Palabra* pal)
{
    *pal->vPal = aMayuscula(*pal->vPal);
    char* iPal = pal->vPal + 1;

    while(*iPal != '\0')
    {
        *iPal = aMinuscula(*iPal);
        iPal++;
    }
}

bool secPalFin(const SecPal* sec)
{
    return sec->finSec;
}

void secPalCerrar(SecPal* sec)
{
    *sec->cursor = '\0';
}

void palabraMostrar(const Palabra* pal)
{
    printf("%s", pal->vPal);
}

