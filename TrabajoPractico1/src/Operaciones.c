#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Menu.h"
#include "Operaciones.h"

/// brief  Suma entre los valores de los dos parametros
/// @param int num1 Primer numero ingresado por el usuario
/// @param int num2 Segundo numero ingresado por el usuario
/// @return int Resultado de la suma
int sumar(int num1, int num2) {

	int resultado;
	resultado = num1+num2;

	return resultado;
}


/// brief  Resta entre los valores de los dos parametros
/// @param int num1 Primer numero ingresado por el usuario
/// @param int num2 Segundo numero ingresado por el usuario
/// @return int Resultado de la resta
int restar(int num1, int num2) {

	int resultado;
	resultado = num1-num2;

	return resultado;
}


/// brief  Division entre los valores de los dos parametros
/// @param int num1  Primer numero ingresado por el usuario
/// @param int num2  Segundo numero ingresado por el usuario
/// @return float Resultado de la division
float dividir(int num1, int num2) {

	float resultado;
	resultado = (float) num1 / num2;

	return resultado;

}

/// brief  Multiplicacion entre los valores de los dos parametros
/// @param int num1 Primer numero ingresado por el usuario
/// @param int num2 Segundo numero ingresado por el usuario
/// @return int Resultado de la multiplicacion
int multiplicar(int num1,int num2)
{
    int resultado;
    resultado=num1*num2;

    return resultado;
}


//// brief  Factoreo del valor del parametro
/// @param int num Numero ingresado por el usuario
/// @return unsigned long int Resultado del factoreo
unsigned long int factorizar(int num) {

	unsigned long int resultado = 1;

	for (int i = 1; i <= num; i++) {
		resultado *= i;
	}

	return resultado;
}
