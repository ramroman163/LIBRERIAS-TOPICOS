#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Vector/Vector.h"

#define CANT_ELEM_A_INS 10

void verificarCodRetInsertar(int cod, int elem, int pos);

int main()
{
    system("color af");
    Vector miVec;

    if(!vectorCrear(&miVec))
    {
        puts("Sin memoria");
        return SIN_MEM;
    }

    srand(time(NULL));
    int codRet = TODO_OK;
    int elem;
    int pos;

    for(int i = 0; codRet != SIN_MEM && i < CANT_ELEM_A_INS; i++)
    {
        //system("color 5e");
        elem = rand();
        pos = rand() % 5;
        //system("color e5");
        codRet = vectorOrdInsertar(&miVec, elem);
        verificarCodRetInsertar(codRet, elem, pos);
    }

    if(codRet == SIN_MEM)
    {
        return SIN_MEM;
    }

    int elemABuscar = 12345;

    pos = vectorOrdBuscar(&miVec, elemABuscar);

    if(pos == -1)
    {
        printf("Elemento %d no encontrado.\n", elemABuscar);
    }
    else
    {
        printf("Elemento %d encontrado en pos %d.\n", elemABuscar, pos);
    }

    codRet = vectorOrdInsertar(&miVec, elemABuscar);
    verificarCodRetInsertar(codRet, elemABuscar, pos);

    if(codRet == SIN_MEM)
    {
        return SIN_MEM;
    }

    vectorMostrar(&miVec);

    pos = vectorOrdBuscar(&miVec, elemABuscar);

    if(pos == -1)
    {
        printf("Elemento %d no encontrado.\n", elemABuscar);
    }
    else
    {
        printf("Elemento %d encontrado en pos %d.\n", elemABuscar, pos);
    }

    vectorOrdEliminar(&miVec, elemABuscar);

//    puts("Después de eliminar:");
//    vectorMostrar(&miVec);

    while(vectorCE(&miVec) > 0)
    {
        vectorEliminarDePos(&miVec, 0);
    }

    vectorDestruir(&miVec);

    return 0;
}


void verificarCodRetInsertar(int cod, int elem, int pos)
{
    switch(cod)
    {
    case TODO_OK:
        //printf("Elemento %d insertado.\n", elem);
        break;

    case LLENO:
        printf("Elemento %d no insertado. Motivo: Vector lleno.\n", elem);
        break;

    case DUPLICADO:
        printf("Elemento %d no insertado. Motivo: Duplicado.\n", elem);
        break;

    case POS_INV:
        printf("Elemento %d no insertado. Motivo: Posición %d inválida.\n", elem, pos);
        break;

    case SIN_MEM:
        printf("Elemento %d no insertado. Motivo: Sin memoria. \n", elem);
        break;

    default:
        printf("Código %d desconocido.\n", cod);
    }
}
