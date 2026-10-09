#include <stdio.h>
#include "../Fecha/Fecha.h"

void ingresarEnteroPositivo(int* entero);


int main()
{
    Fecha fecha, fechaDias;
    int diadelanio;

    ingresarFecha(&fecha);

    mostrarFecha(&fecha);
    putchar('\n');

    char *semana[] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
    int dia;

    dia = fechaDiaDeLaSemana(&fecha);

    printf("Esta fecha cayo un %s", semana[dia]);
    putchar('\n');

    fechaDias.dia = 25;
    fechaDias.mes = 12;
    fechaDias.anio = fecha.anio;

    if(fechaCmp(&fecha, &fechaDias) < 0)
        fechaDias.anio++;

    printf("Faltan %d dias para Navidad del %d", fechaDiferencia(&fecha, &fechaDias), fechaDias.anio);
    putchar('\n');

    /*int dias;

    ingresarEnteroPositivo(&dias);

    Fecha fSuma = fechaSumarDias(&fecha, dias);
    Fecha fRes = fechaRestarDias(&fecha, dias);

    printf("La suma es: ");
    mostrarFecha(&fSuma);
    putchar('\n');

    printf("La resta es: ");
    mostrarFecha(&fRes);
    putchar('\n'); */

    /*diadelanio = fechaDiaDelAnio(&fecha);

    fechaDias = fechaDeDiaDelAnio(diadelanio, fecha.anio);*/

    /*printf("Dias del anio %d", diadelanio);
    putchar('\n');

    puts("Fecha de dias del anio:");
    putchar('\n');
    
    mostrarFecha(&fechaDias);
    putchar('\n');*/

    return 0;
}


void ingresarEnteroPositivo(int* entero)
{
    puts("Ingrese un entero positivo:");
    scanf("%d", entero);

    while(*entero < 1)
    {
        puts("El entero no es positivo. Ingréselo de nuevo:");
        scanf("%d", entero);
    }
}
