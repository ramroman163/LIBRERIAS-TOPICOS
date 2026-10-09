#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <stdbool.h>


typedef struct
{
    int dia;
    int mes;
    int anio;    
}
Fecha;


// Primitivas

bool fechaSet(Fecha* f, int dia, int mes, int anio);
void fechaGet(const Fecha* f, int* dia, int* mes, int* anio);
Fecha fechaSumarDias(const Fecha* f, int dias);
Fecha fechaRestarDias(const Fecha* f, int dias);
int fechaDiferencia(const Fecha* f1, const Fecha* f2);
int fechaDiaDeLaSemana(const Fecha* f);
int fechaDiaDelAnio(const Fecha* f);
Fecha fechaDeDiaDelAnio(int diaDelAnio, int anio);
int fechaCmp(const Fecha* f1, const Fecha* f2);


// No Primitivas
void ingresarFecha(Fecha* f);
void mostrarFecha(const Fecha* f);


#endif // FECHA_H_INCLUDED
