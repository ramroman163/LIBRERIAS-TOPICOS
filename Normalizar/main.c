#include <stdio.h>
#include <stdlib.h>
#include "../SecPal/SecPal.h"

char* normalizar(char* cadNormalizada, const char* cadANormalizar);

int main()
{
    char cadANormalizar[] = "#$%cAdEnA$#%^^&*dE#%^&eJemPLo";
    char cadNormalizada[101];

    normalizar(cadNormalizada, cadANormalizar);

    printf("[%s]", cadNormalizada);

    return 0;
}

char* normalizar(char* cadNormalizada, const char* cadANormalizar)
{
    SecPal secLect, secEscr;

    secPalCrear(&secLect, (char*)cadANormalizar);
    secPalCrear(&secEscr, cadNormalizada);

    Palabra pal;

    secPalLeer(&secLect, &pal);
    while(!secPalFin(&secLect))
    {
        palabraATitulo(&pal);
        secPalEscribir(&secEscr, &pal);
        if(secPalLeer(&secLect, &pal))
        {
            secPalEscribirCaracter(&secEscr, ' ');
        }
        //palabraMostrar(&pal);
        //putchar(' ');
    }

    secPalCerrar(&secEscr);

    return cadNormalizada;
}

