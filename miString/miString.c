#include "miString.h"
#include <stddef.h>

int miStrlen(const char* cad)
{
    int cont = 0;
    const char* puntero = cad;

    while(*puntero)
    {
        cont++;
        puntero++;
    }

    return cont;
}

int miStrcmp(const char* cad1, const char* cad2)
{
    int dif;
    const char* p1 = cad1;
    const char* p2 = cad2;

    while(*p1 && *p2)
    {
        dif = *p1 - *p2;

        if(dif != 0)
            return dif;

        p1++;
        p2++;
    }

    if(miStrlen(cad1) < miStrlen(cad2))
        return -1;

    if(miStrlen(cad1) > miStrlen(cad2))
        return 1;

    return 0;
}

int miStrcmpi(const char* cad1, const char* cad2)
{
    int dif;
    const char* p1 = cad1;
    const char* p2 = cad2;

    while(*p1 && *p2)
    {
        dif = aMayuscula(*p1) - aMayuscula(*p2);

        if(dif != 0)
            return dif;

        p1++;
        p2++;
    }

    if(miStrlen(cad1) < miStrlen(cad2))
        return -1;

    if(miStrlen(cad1) > miStrlen(cad2))
        return 1;

    return 0;
}

char* miStrcpy(char* cadDest, const char* cadOrig)
{
    char* dirInicio = cadDest;

    while(*cadOrig != '\0')
    {
        *cadDest = *cadOrig;
        cadOrig++;
        cadDest++;
    }

    *cadDest = '\0';

    return dirInicio;
}

char* miStrncpy(char* cadDest, const char* cadOrig, size_t n)
{
    if(n == 0)
    {
        return cadDest;
    }

    char* dirInicio = cadDest;
    char* dirMax = cadDest + n - 1;

    while(*cadOrig != '\0' && cadDest < dirMax)
    {
        *cadDest = *cadOrig;
        cadOrig++;
        cadDest++;
    }

    *cadDest = '\0';

    return dirInicio;
}

char* miStrstr(const char* cad, const char* subCad)
{
    const char* dir = NULL;
    bool encontrada = false;
    const char* inicioSubCad = subCad;

    while(*subCad && *cad)
    {
        if(*subCad == *cad)
        {
            if(!encontrada)
            {
                encontrada = true;
                dir = cad;
            }
            subCad++;
            cad++;
        }
        else
        {
            cad++;
            encontrada = false;
            subCad = inicioSubCad;
            dir = NULL;
        }
    }

    if(*subCad == '\0')
    {
        return (char*)dir;
    }

    return NULL;
}

char* miStrchr(const char* cad, char c)
{
    while(*cad)
    {
        if(*cad == c)
        {
            return (char*)cad;
        }
        cad++;
    }

    return NULL;
}

char* miStrcat(char* cad1, const char* cad2)
{
    char* finCadDes = cad1 + miStrlen(cad1);

    while(*cad2)
    {
        *finCadDes = *cad2;
        finCadDes++;
        cad2++;
    }

    *finCadDes = '\0';

    return cad1;
}

char* miStrncat(char* cad1, const char* cad2, size_t n)
{
    char* finCadDes = cad1 + miStrlen(cad1);
    char* i;

    for(i = finCadDes; i <= finCadDes + n; i++)
    {
        *i = *cad2;
        cad2++;
    }

    *i = '\0';

    return cad1;
}

bool esLetra(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c == 165 || c == 164) || (c >= 160 && c <= 163) || (c == 130) || (c == 181 || c == 144 || c == 214 || c == 224 || c == 233);
}
