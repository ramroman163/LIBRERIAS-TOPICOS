#include <stdio.h>
#include <stdlib.h>
#include "../miString/miString.h"
#include "../SecPal/SecPal.h"

#define TAM_VEC_PAL 1000

int contarPalabrasTexto(char* texto);
void hallarPalMasLarga(char* texto, Palabra* masLarga);
int cantidadRepesPalabra(char* texto, Palabra* palABuscar);
Palabra* buscarPalVec(const Palabra* palVec, size_t n, const Palabra* pal);
void hallarRepeticionPalabras(char* texto, Palabra* palVec, int* apariciones, size_t n);

int main()
{
    char texto[] = "business Hola mi amoorrrr te amo mucho amoorrrr. business Te quiero para toda mi vida amoorrrr quiero quiero amoorrrr.";
    int cantPalabras = contarPalabrasTexto(texto);

    puts("El largo del texto es: ");
    printf("%d", miStrlen(texto));
    puts("\nLa cantidad de palabras del texto es: ");
    printf("%d", cantPalabras);

    Palabra masLarga;

    hallarPalMasLarga(texto, &masLarga);

    printf("\nLa palabra mas larga es: %s", masLarga.vPal);

    int repes;

    repes = cantidadRepesPalabra(texto, &masLarga);

    printf("\nLa palabra [%s] se repite [%d] veces!", masLarga.vPal, repes);

    Palabra palVec[TAM_VEC_PAL];
    int apariciones[TAM_VEC_PAL] = {0};

    hallarRepeticionPalabras(texto, palVec, apariciones, (size_t)TAM_VEC_PAL);

    // Ordenamiento por aparicion

    for(int i = 0; i < cantPalabras; i++)
    {
        for(int j = 0; j < cantPalabras-1; j++)
        {
            if(apariciones[j] < apariciones[j+1])
            {
                int aux = apariciones[j];
                apariciones[j] = apariciones[j+1];
                apariciones[j+1] = aux;

                Palabra paux = palVec[j];
                palVec[j] = palVec[j+1];
                palVec[j+1] = paux;
            }
        }
    }

    puts("\nPALABRAS CON SU REPETICION: ");

    for(int i = 0; i < cantPalabras; i++)
    {
        if(apariciones[i] >= 1)
            printf("\n[%s] - [%d]", palVec[i].vPal, apariciones[i]);
    }

    puts("\n");


    return 0;
}

/*

-resolver la de normalizar de manera tradicional (sin el tda y modificando la misma cadena si es como el de la guia)
-resolver las funciones de string.h y ctype.h (to upper, to lower, is alpha, is digit)
-contar la cantidad de palabras que tiene un texto
-encontrar la palabra mas larga (pero le parece inutil)
-otra, hacer la palabra mas larga y cuantas veces se repite (primero se da la secuencia de encontrar la mas larga y desp la de contar cuantas veces se repite)
-otra, la palabra que mas se repite en un texto
-ultimo, el ranking de las n palabras, ordenado de mayor a menor, que mas se repiten

*/


/*
leer caracteres alfabeticos hasta encontrar un espacio.
si encuentro uno, sigo leyendo hasta encontrar un caracter no alfabetico.
ahí incremento mi contador.
*/

// Contar cantidad de palabras de un texto

int contarPalabrasTexto(char* texto)
{
    int cont = 0;
    SecPal secLect;

    secPalCrear(&secLect, texto);

    Palabra pal;

    secPalLeer(&secLect, &pal);

    while(!secPalFin(&secLect))
    {
        cont++;
        secPalLeer(&secLect, &pal);
    }

    return cont;
}

// Encontrar la palabra mas larga del texto

void hallarPalMasLarga(char* texto, Palabra* masLarga)
{
    SecPal secLect;

    secPalCrear(&secLect, texto);

    bool primLect = true;

    Palabra miPalabra;
    Palabra* pal = &miPalabra;

    secPalLeer(&secLect, pal);

    while(!secPalFin(&secLect))
    {

        if(primLect || (miStrlen(pal->vPal) >= miStrlen(masLarga->vPal)))
        {
            primLect = false;
            miStrcpy(masLarga->vPal, pal->vPal);
        }

        secPalLeer(&secLect, pal);
    }

    secPalCerrar(&secLect);
}

// Encontrar cuantas veces se repite una palabra

int cantidadRepesPalabra(char* texto, Palabra* palABuscar)
{
    SecPal secLect;

    int cantRepes = 0;

    Palabra palAux;
    Palabra* pal = &palAux;

    secPalCrear(&secLect, texto);

    secPalLeer(&secLect, pal);

    while(!secPalFin(&secLect))
    {
        if(!miStrcmp(palABuscar->vPal, pal->vPal))
        {
            cantRepes++;
        }

        secPalLeer(&secLect, pal);
    }

    secPalCerrar(&secLect);

    return cantRepes;
}


/*
vector palabras
vector apariciones
recorro texto. busco palabra en mi vector.
si está, incremento en 1 apariciones
si no está, la escribo en una pos y seteo en 0 su cant de apariciones.
al final ordeno vector palabras y apariciones en funcion de apariciones.
*/

// Hallar palabra o n palabras que mas aparecen en un texto ordenadas de may a men

void hallarRepeticionPalabras(char* texto, Palabra* palVec, int* apariciones, size_t n)
{
    SecPal secLect;

    int pos = 0;

    Palabra palAux;
    Palabra* pal = &palAux;
    Palabra* dirPos;
    Palabra* dirInicial = palVec;

    secPalCrear(&secLect, texto);

    secPalLeer(&secLect, pal);

    while(!secPalFin(&secLect))
    {
        dirPos = buscarPalVec(palVec, n, pal);

        if(dirPos == NULL)
        {
            // lo correcto sería usar un tdavector, pero, muy largo y son las 12
            // si no lo lei antes, lo creo en ambos vectores
            *(palVec + pos) = *pal;
            *(apariciones + pos) = 1;
            pos++;
        }
        else
        {
            int posParalela = dirPos - dirInicial;
            (*(apariciones + posParalela))++;
        }

        secPalLeer(&secLect, pal);
    }

    secPalCerrar(&secLect);
}

Palabra* buscarPalVec(const Palabra* palVec, size_t n, const Palabra* palABuscar)
{
    Palabra* dirPos = NULL;
    const Palabra* dirFin = palVec + n - 1;

    while(dirPos == NULL && palVec <= dirFin)
    {
        if(!miStrcmp(palVec->vPal, palABuscar->vPal))
        {
            dirPos = (Palabra*)palVec;
        }

        palVec++;
    }

    return dirPos;
}

