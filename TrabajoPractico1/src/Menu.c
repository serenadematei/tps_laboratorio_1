#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Menu.h"
#include "Operaciones.h"
#include "Get.h"

////brief Menu de opciones que se muestran al usuario.
/// @param int bandera1 Bandera que permite saber si el primer numero fue o no ingresado.
/// @param int bandera2 Bandera que permite saber si el segundo numero fue o no ingresado.
/// @param int num1 Primer numero ingresado por el usuario.
/// @param int num2 Segundo numero ingresado por el usuario.
/// @return int opcion ingresada por el usuario.
int menu(int bandera1, int bandera2, int num1, int num2) {

	int opcion;

	printf("            ***** MENU DE OPCIONES *****\n");

	printf("1. Ingresar 1er operando.");
	if (bandera1) {
		printf(" A = %d\n", num1);
	} else {
		printf(" A = x\n");
	}

	printf("2. Ingresar 2do operando.");
	if (bandera2) {
		printf(" B = %d\n", num2);
	} else {
		printf(" B = y\n");
	}

	printf("3. Calcular todas las operaciones.\n");
	printf("\t a)Calcular la suma (A+B)\n");
	printf("\t b)Calcular la resta (A-B)\n");
	printf("\t c)Calcular la division (A/B)\n");
	printf("\t d)Calcular la multiplicacion (A*B)\n");
	printf("\t e)Calcular el factorial (A!)\n");

	printf("4. Informar resultados.\n");
	printf("5. Salir.\n");

	opcion=pedirEntero("Ingrese opcion:");

	return opcion;
}

////brief Ingreso de numeros por parte del usuario
/// @param int* operando  puntero al valor ingresado por el usuario
/// @return 0 si el puntero es igual a NULL, 1 si salio bien
int ingresarOperando(int *operando) {

	int todoOk = 0;
	int numeroIngresado;

	if (operando != NULL) {

		numeroIngresado=pedirEntero("Ingrese un numero:");
        *operando = numeroIngresado;

		todoOk = 1;
	}

	return todoOk;

}

////brief Informe de los resultados de las operaciones al usuario
/// @param int num1 Primer numero ingresado por el usuario
/// @param int num2 Segundo numero ingresado por el usuario
/// @param suma Resultado de la operacion suma
/// @param resta Resultado de la operacion resta
/// @param multiplicacion Resultado de la operacion multiplicacion
/// @param division Resultado de la operacion division
/// @param factorial1 Resultado del factorial de num1
/// @param factorial2 Resultado del factorial de num2
void informarResultados(int num1, int num2, int suma, int resta,
		int multiplicacion, float division, unsigned long int factorial1,
		unsigned long int factorial2) {

	printf("\n*****************RESULTADOS*****************\n\n\n\n");
	printf("a) El resultado de %d + %d es: %d \n", num1, num2, suma);
	printf("b) El resultado de %d - %d es: %d \n", num1, num2, resta);
	printf("c) El resultado de %d * %d es: %d \n", num1, num2, multiplicacion);

	if (num2 != 0) {
		printf("d) El resultado de %d / %d es: %.2f \n", num1, num2, division);
	} else {
		printf("d) No es posible dividir por cero\n");
	}

	if(num1>=0){
	   printf("e) El factorial de %d es: %ld \n", num1,factorial1);
	}
	if(num2>=0){
	  printf("f) El factorial de %d es: %ld \n", num2,factorial2);
	}



}

////brief Pide la confirmacion del usuario sobre si desea finalizar o no el programa
/// @param char* pSalida puntero a la opcion ingresada por el usuario
/// @return 0 si el puntero es igual a NULL, 1 si salio bien
char verificarSalida(char *pSalida) {
	int todoOk = 0;
	char opcion;

	if (pSalida != NULL) {

		fflush(stdin);
		utn_getCaracter(&opcion,"Confirma salida? (s/n):","Opcion invalida.\n",'s','n',10);

		*pSalida = opcion;
		todoOk = 1;
	}

	return todoOk;

}

