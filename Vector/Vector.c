#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"

bool ampliarVector(Vector* v);
void reducirVector(Vector* v);
bool vectorCrear(Vector* v);
void vectorDestruir(Vector* v);

bool ampliarVector(Vector* v)
{
    size_t nCap = v->cap * FACTOR_INCR;
    int* nVec = realloc(v->vec, nCap * sizeof(int));

    if(!nVec)
    {
        return false;
    }

    printf("Ampliacion de %llu a %llu.\n", v->cap, nCap);

    v->vec = nVec;
    v->cap = nCap;

    return true;
}

void reducirVector(Vector* v)
{
    size_t nCap = v->cap * FACTOR_DECR;

    if(nCap < CAP_INI)
    {
        return;
    }

    v->vec = realloc(v->vec, nCap * sizeof(int));

    printf("Reduccion de %llu a %llu. \n", v->cap, nCap);

    v->cap = nCap;

}

bool vectorCrear(Vector* v)
{
    v->ce = 0;
    v->cap = 0;

    v->vec = malloc(CAP_INI * sizeof(int));

    if(v->vec == NULL)
    {
        return false;
    }

    v->cap = CAP_INI;

    return true;
}


int vectorOrdInsertar(Vector* v, int elem)
{
    if(v->ce == v->cap)
    {
        if(!ampliarVector(v))
        {
            return SIN_MEM;
        }
    }

    int* ult = v->vec + (v->ce - 1);
    // Reemplazar por función buscar binaria.
    int* i = v->vec;
    while(i <= ult && elem >= *i)
    {
        i++;
    }
/*
    if(i <= ult && elem == *i)
    {
        return DUPLICADO;
    }*/

    return vectorInsertarEnPos(v, elem, i - v->vec);
}


int vectorInsertarAlFinal(Vector* v, int elem)
{
    if(v->ce == v->cap)
    {
        if(!ampliarVector(v))
        {
            return SIN_MEM;
        }
    }

    int* dirIns = v->vec + v->ce;
    *dirIns = elem;
    v->ce++;

    return TODO_OK;
}


int vectorInsertarEnPos(Vector* v, int elem, int pos)
{
    if(v->ce == v->cap)
    {
        if(!ampliarVector(v))
        {
            return SIN_MEM;
        }
    }

    if(pos < 0 || pos > v->ce)
    {
        return POS_INV;
    }

    int* dirIns = v->vec + pos;
    int* ult = v->vec + (v->ce - 1);

    for(int* i = ult; i >= dirIns; i--)
    {
        *(i + 1) = *i;
    }

    *dirIns = elem;
    v->ce++;

    return TODO_OK;
}

size_t vectorCE(const Vector* v)
{
    return v->ce;
}


int vectorOrdBuscar(const Vector* v, int elem)
{
    const int* li = v->vec;
    const int* ls = v->vec + (v->ce - 1);
    const int* m;
    bool encontrado = false;
    int comp, pos = -1;

    while(!encontrado && li <= ls)
    {
        m = li + (ls - li) / 2;

        comp = elem - *m;

        if(comp == 0)
        {
            encontrado = true;
            pos = m - v->vec;
        }

        if(comp < 0)
        {
            ls = m - 1;
        }

        if(comp > 0)
        {
            li = m + 1;
        }
    }

    return pos;
}


int vectorDesordBuscar(const Vector* v, int elem);


bool vectorOrdEliminar(Vector* v, int elem)
{
    int pos = vectorOrdBuscar(v, elem);
    return vectorEliminarDePos(v, pos);
}


bool vectorDesordEliminar(Vector* v, int elem);


bool vectorEliminarDePos(Vector* v, int pos)
{
    if(pos < 0 || pos >= v->ce)
    {
        return false;
    }

    int* dirElim = v->vec + pos;
    int* ult = v->vec + (v->ce - 1);

    for(int* i = dirElim; i < ult; i++)
    {
        *i = *(i + 1);
    }

    v->ce--;

    if((float)v->ce / v->cap <= FACTOR_OCUP)
    {
        reducirVector(v);
    }

    return true;
}


void vectorOrdenar(Vector* v);


void vectorMostrar(const Vector* v)
{
    const int* ult = v->vec + (v->ce - 1);

    for(const int* i = v->vec; i <= ult; i++)
    {
        printf("[%05d]\n", *i);
    }
}


void vectorVaciar(Vector* v)
{
    v->ce = 0;
    v->cap = CAP_INI;
    v->vec = realloc(v->vec, CAP_INI * sizeof(int));
}

void vectorDestruir(Vector* v) // free
{
    free(v->vec);
    v->vec = NULL;
    v->ce = v->cap = 0;
}
