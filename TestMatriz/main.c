#include <stdio.h>
#include <stdlib.h>
#include "../Matriz/Matriz.h"

#define FILAS 3
#define COLUMNAS 4
#define ORDEN 4

#define TODO_OK 0
#define SIN_MEM 3

int main()
{
    /*
    int matriz[FILAS][COLUMNAS] =
    {
        {1, 2, 3 ,4},
        {5, 6, 7 ,8},
        {9, 10, 11,12},
    };

    int matrizCuad[ORDEN][ORDEN] =
    {
        {1, 2, 3 ,4},
        {5, 6, 7 ,8},
        {9, 10, 11,12},
        {13, 14, 15,16}
    };
    */


    // Forma de declarar un puntero a matriz en heap
    /*
    int (*matrizCuadDin)[ORDEN] = malloc(sizeof(int) * ORDEN * ORDEN);

    if(!matrizCuadDin)
    {
        puts("Sin memoria.");
        return SIN_MEM;
    }*/

    int** matrizCuadDinFilInd = (int**)crearMatriz(sizeof(int), ORDEN, ORDEN);

    if(!matrizCuadDinFilInd)
    {
        puts("Sin memoria.");
        return SIN_MEM;
    }

    cargarMatriz(ORDEN, ORDEN, matrizCuadDinFilInd);

    puts("Matriz cuadrada: ");

    //mostrarMatriz(ORDEN, ORDEN, matrizCuad);

    putchar('\n');

    puts("Matriz normal: ");

    //mostrarMatriz(FILAS, COLUMNAS, matriz);

    putchar('\n');

    //puts("Matriz cuadrada dinamica: ");
    //mostrarMatriz(ORDEN, ORDEN, matrizCuadDin);

    puts("Matriz cuadrada dinamica v2: ");
    mostrarMatriz(ORDEN, ORDEN, matrizCuadDinFilInd);

    putchar('\n');

    int sumaDP = sumaDiagPrincipal(ORDEN, matrizCuadDinFilInd);
    printf("SUMA DP: %d\n", sumaDP);

    int sumaDS = sumaDiagSec(ORDEN, matrizCuadDinFilInd);
    printf("SUMA DS: %d\n", sumaDS);

    int sumaTriInfDP = sumaTriagInfDP(ORDEN, matrizCuadDinFilInd);
    printf("SUMA TRIANGULAR INFERIOR DP: %d\n", sumaTriInfDP);

    int sumaTriSupDS = sumaTriagSupDS(ORDEN, matrizCuadDinFilInd);
    printf("SUMA TRIANGULAR SUPERIOR DS: %d\n", sumaTriSupDS);

    recorrerMatrizEspiral(ORDEN, ORDEN, matrizCuadDinFilInd);

    //free(matrizCuadDin);
    // da warning si es doble si no no
    destruirMatriz((void**)matrizCuadDinFilInd, FILAS);

    return TODO_OK;
}
