#ifndef MISTRING_H_INCLUDED
#define MISTRING_H_INCLUDED
#include <stdbool.h>
#include <stddef.h>

//#define esLetra(c) (((c) >= 'A' && (c) <= 'Z') || ((c) >= 'a' && (c) <= 'z'))

#define aMayuscula(c) (((c) >= 'a' && (c) <= 'z')? (c) - ('a' - 'A') : (c))

#define aMinuscula(c) (((c) >= 'A' && (c) <= 'Z')? (c) + ('a' - 'A') : (c))

#define esDigito(c) ((c) >= '0' && (c) <= '9')

int miStrlen(const char* cad);
int miStrcmp(const char* cad1, const char* cad2);
int miStrcmpi(const char* cad1, const char* cad2);
char* miStrcpy(char* cadDest, const char* cadOrig);
char* miStrncpy(char* cadDest, const char* cadOrig, size_t n);
char* miStrstr(const char* cad, const char* subCad);
char* miStrchr(const char* cad, char c);
char* miStrcat(char* cad1, const char* cad2);
char* miStrncat(char* cad1, const char* cad2, size_t n);

bool esLetra(char c);

#endif // MISTRING_H_INCLUDED
