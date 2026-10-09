#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <stddef.h>
#include <stdbool.h>

#define CAP_INI 8

#define TODO_OK 0
#define LLENO 1
#define DUPLICADO 2
#define POS_INV 3
#define SIN_MEM 4

#define FACTOR_INCR 1.5 // > 1
#define FACTOR_OCUP 0.25 // < 1
#define FACTOR_DECR 0.5 // < 1 && > FACTOR_OCUP


typedef struct
{
    int *vec;
    size_t ce;
    size_t cap;
}
Vector;

bool vectorCrear(Vector* v); // malloc
int vectorOrdInsertar(Vector* v, int elem); // realloc
int vectorInsertarAlFinal(Vector* v, int elem); // realloc
int vectorInsertarEnPos(Vector* v, int elem, int pos); // reallloc
int vectorOrdBuscar(const Vector* v, int elem);
int vectorDesordBuscar(const Vector* v, int elem);
size_t vectorCE(const Vector* v);
bool vectorOrdEliminar(Vector* v, int elem); // realloc
bool vectorDesordEliminar(Vector* v, int elem); // realloc
bool vectorEliminarDePos(Vector* v, int pos); // realloc
void vectorOrdenar(Vector* v);
void vectorMostrar(const Vector* v);
void vectorVaciar(Vector* v); // realloc
void vectorDestruir(Vector* v); // free

#endif // VECTOR_H_INCLUDED
