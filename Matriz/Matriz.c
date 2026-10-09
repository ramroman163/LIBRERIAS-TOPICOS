#include "Matriz.h"
#include <stdio.h>
#include <stdlib.h> //malloc y free


void** crearMatriz(size_t tamElem, int filas, int columnas)
{
    void** mat = malloc(sizeof(void*) * filas);

    if(!mat)
    {
        return NULL;
    }

    void** ult = mat + (filas - 1);
    // puntero doble por ser un puntero que apunta a otro puntero
    for(void** i = mat; i <= ult; i++)
    {
        *i = malloc(sizeof(tamElem) * columnas);

        if(!*i)
        {
            destruirMatriz(mat, i - mat);
            return NULL;
        }
    }

    return mat;
}

void cargarMatriz(int filas, int columnas, int** mat)
{
    int dato = 1;

    for(int i = 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            mat[i][j] = dato++;
        }
    }

}

void mostrarMatriz(int filas, int columnas, int** mat)
{

    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            printf("[%03d]", mat[i][j]);
        }
        putchar('\n');
    }

}

int sumaDiagPrincipal(int orden, int** mat)
{
    int suma = 0;

    for(int i = 0; i < orden; i++)
    {
        suma += mat[i][i];
    }

    return suma;
}

int sumaDiagSec(int orden, int** mat)
{
    int suma = 0;

    for(int i = 0, j = orden-1; i < orden; i++, j--)
    {
        suma += mat[i][j];
    }

    return suma;

}

int sumaTriagInfDP(int orden, int** mat)
{
    int suma = 0;

    for(int i = 1; i < orden; i++)
    {
        for(int j = 0; j < i; j++)
        {
            suma += mat[i][j];
        }
    }

    return suma;

}

int sumaTriagSupDS(int orden, int** mat)
{
    int suma = 0;
    int limI = orden -2;

    for(int i = 0, limJ = limI; i <= limI; i++, limJ--)
    {
        for(int j = 0; j <= limJ; j++)
        {
            suma += mat[i][j];
        }
    }

    return suma;
}

void destruirMatriz(void** mat, int filas)
{
    void** ult = mat + (filas - 1);

    for(void** i = mat; i <= ult; i++)
    {
        free(*i);
    }

    free(mat);
}

void recorrerMatrizEspiral(int filas, int columnas, int** mat)
{
	int desdeAlto, desdeLargo, hastaLargo, hastaAlto;

	desdeLargo = 0;
	hastaLargo = columnas-1;
	desdeAlto = 0;
	hastaAlto = filas-1;

	while(desdeAlto <= hastaAlto && desdeLargo <= hastaLargo)
	{
		// Hacia derecha
		for(int i = desdeLargo; i <= hastaLargo; i++)
		{
			printf("[%d]", mat[desdeAlto][i]);
		}

		desdeAlto++;

		// Hacia abajo
		for(int j = desdeAlto; j <= hastaAlto; j++)
		{
			printf("[%d]", mat[j][hastaLargo]);
		}

		hastaLargo--;

		// Hacia izquierda
		if (desdeAlto <= hastaAlto)
		{
			for(int i = hastaLargo; i >= desdeLargo; i--)
			{
				printf("[%d]", mat[hastaAlto][i]);
			}
		    hastaAlto--;
		}


		// Hacia arriba
		if(desdeLargo <= hastaLargo)
		{
			for(int j = hastaAlto; j >= desdeAlto; j--)
			{
				printf("[%d]", mat[j][desdeLargo]);
			}

			desdeLargo++;
		}

	}
}

int sumarTriagSup(int filas, int columnas, int** mat)
{
    if(filas != columnas)
    {
        puts("NO ES CUADRADA!!");
        // explotar la ejecucion
    }

    int hasta = filas / 2; // (filas - 1) / 2
    int acum = 0;

    if(filas % 2 == 0)
    {
        hasta--;
    }


    for(int i = 0; i < hasta; i++)
    {
        int limitCol = columnas - i - 1;
        for(int j = i+1; j < limitCol; j++)
        {
            acum += mat[i][j];
        }
    }

    return acum;
}

int sumarTriagInf(int filas, int columnas, int** mat)
{
    int desde = (filas / 2) + 1;
    int acum = 0;

    for(int i = desde; i < filas; i++)
    {
        for(int j = columnas - i; j < i; j++)
        {
            acum += mat[i][j];
        }
    }

    return acum;
}
