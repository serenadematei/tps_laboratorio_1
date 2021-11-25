#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef GET_H_
#define GET_H_

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getCaracter(char *pResultado, char* mensaje, char* mensajeError, char minimo, char maximo,int reintentos );
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getNombre(char* pResultado, char* mensaje, char* mensajeError, int sizeNombre, int reintentos);
int getCharDosOpciones(char* pChar,char message[],char errorMessage[],char option1,char option2);
char getChar(char message[],char errorMessage[]);
int getOnlyInt(char message[],char errorMessage[]);

#endif /* GET_H_ */

//tp3
