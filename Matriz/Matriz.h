#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

#include <stddef.h>

void** crearMatriz(size_t tamElem, int filas, int columnas);
void destruirMatriz(void** mat, int filas);

void cargarMatriz(int filas, int columnas, int** mat);
void mostrarMatriz(int filas, int columnas, int** mat);
int sumaDiagPrincipal(int orden, int** mat);
int sumaDiagSec(int orden, int** mat);
int sumaTriagInfDP(int orden, int** mat);
int sumaTriagSupDS(int orden, int** mat);
void recorrerMatrizEspiral(int filas, int columnas, int** mat);
int sumarTriagSup(int filas, int columnas, int** mat);
int sumarTriagInf(int filas, int columnas, int** mat);


#endif // MATRIZ_H_INCLUDED
