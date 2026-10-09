#include <stdio.h>
#include "Fecha.h"


bool esFechaValida(int dia, int mes, int anio);
int cantDiasMes(int mes, int anio);
bool esBisiesto(int anio);
int cantDiasAnio(int anio);


// Primitivas

bool fechaSet(Fecha* f, int dia, int mes, int anio)
{
    if(!esFechaValida(dia, mes, anio))
    {
        return false;
    }

    f->dia = dia;
    f->mes = mes;
    f->anio = anio;

    return true;
}


void fechaGet(const Fecha* f, int* dia, int* mes, int* anio)
{
    *dia = f->dia;
    *mes = f->mes;
    *anio = f->anio;
}


Fecha fechaSumarDias(const Fecha* f, int dias)
{
    Fecha fSum = *f;
    fSum.dia += dias;
    int diasMes;

    while(fSum.dia > (diasMes = cantDiasMes(fSum.mes, fSum.anio)))
    {
        fSum.dia -= diasMes;
        fSum.mes++;

        if(fSum.mes > 12)
        {
            fSum.mes = 1;
            fSum.anio++;
        }
    }

    return fSum;
}


Fecha fechaRestarDias(const Fecha* f, int dias)
{
    Fecha fRes = *f;
    fRes.dia -= dias;

    while(fRes.dia <= 0)
    {
        fRes.mes--;

        if(fRes.mes < 1)
        {
            fRes.mes = 12;
            fRes.anio--;
        }

        fRes.dia += cantDiasMes(fRes.mes, fRes.anio);
    }

    return fRes;
}

int fechaDiaDelAnio(const Fecha* f)
{
    int dias = 0, i;

    for(i = 1 ; i < f->mes ; i++)
    {
        dias+= cantDiasMes(i, f->anio);
    }

    dias+= f->dia;

    return dias;
}

int fechaCmp(const Fecha* f1, const Fecha* f2)
{
    int diferencia = f2->anio - f1->anio;

    if(diferencia != 0)
        return diferencia; // + f2 es mayor, - f1 es mayor

    diferencia = f2->mes - f1->mes;

    if(diferencia != 0)
        return diferencia;

    return f2->dia - f1->dia;

}

int fechaDiferencia(const Fecha* f1, const Fecha* f2)
{
    int diferencia = 0, comp = fechaCmp(f1,f2), anio_mayor, anio_menor, dias_mayor, dias_menor;
    
    if(comp == 0)
        return diferencia; // fechas iguales
    
    if(comp > 0)
    {
        anio_mayor = f2->anio;
        dias_mayor = fechaDiaDelAnio(f2);
        anio_menor = f1->anio;
        dias_menor = fechaDiaDelAnio(f1);
    }

    if(comp < 0)
    {
        anio_mayor = f1->anio;
        dias_mayor = fechaDiaDelAnio(f1);
        anio_menor = f2->anio;
        dias_menor = fechaDiaDelAnio(f2);
    }

    if(anio_mayor == anio_menor)
        return dias_mayor - dias_menor; // fechas distintas del mismo año

    diferencia += dias_mayor;
    diferencia += (cantDiasAnio(anio_menor)) - dias_menor; // diferencia de dias en los años extremos 

    while((anio_mayor - anio_menor) > 1) // de haberlo, sumo los dias de los años intermedios
    {
        anio_mayor--;
        diferencia += cantDiasAnio(anio_mayor);
    }

    return diferencia;
}

int fechaDiaDeLaSemana(const Fecha* f) // numeros del 0 al 6, empezando con el domingo
{
    int dia_semana;
    Fecha referencia; // el 1/1 de los años multiplos de 400 caen sabado, el siguiente domingo es el 2/1 de ese año

    referencia.dia = 2;
    referencia.mes = 1;
    referencia.anio = (f->anio) - 1;

    while((referencia.anio % 400) != 0) // busco el año multiplo de 400 inmediatamente anterior
    {
        referencia.anio--;
    }

    dia_semana = (fechaDiferencia(&referencia, f)) % 7;

    return dia_semana;
}

Fecha fechaDeDiaDelAnio(int diaDelAnio, int anio)
{
    Fecha fecha;
    int mes = 1, diasMes;

    while(diaDelAnio > (diasMes = cantDiasMes(mes, anio))) //le resto meses completos hasta que solo queden los dias de la fecha
    {
        diaDelAnio -= diasMes;
        mes++;
    }

    fecha.anio = anio;
    fecha.mes = mes;
    fecha.dia = diaDelAnio;

    return fecha;
}


// No Primitivas

void ingresarFecha(Fecha* f)
{
    int dia, mes, anio;

    puts("Ingrese una fecha (D/M/A):");
    scanf("%d/%d/%d", &dia, &mes, &anio);

    while(!fechaSet(f, dia, mes, anio))
    {
        puts("Fecha inválida. Ingresela de nuevo (D/M/A):");
        scanf("%d/%d/%d", &dia, &mes, &anio);
    }
}


void mostrarFecha(const Fecha* f)
{
    int dia, mes, anio;
    fechaGet(f, &dia, &mes, &anio);
    printf("%02d/%02d/%04d", dia, mes, anio);
}


bool esFechaValida(int dia, int mes, int anio)
{
    if(anio < 1601)
    {
        return false;
    }

    if(mes < 1 || mes > 12)
    {
        return false;
    }

    if(dia < 1 || dia > cantDiasMes(mes, anio))
    {
        return false;
    }

    return true;
}


int cantDiasMes(int mes, int anio)
{
    int diasMes[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(mes == 2 && esBisiesto(anio))
    {
        return 29;
    }

    return diasMes[mes];
}


bool esBisiesto(int anio)
{
    return anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0);
}

int cantDiasAnio(int anio)
{
    if(esBisiesto(anio))
        return 366;
    else
        return 365;
}
