/*
 ============================================================================
 Name        : TrabajoPractico1.c
 Author      : Dematei, Serena
 Description : CALCULADORA
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Menu.h"
#include "Operaciones.h"
#include "Get.h"


int main(void) {

	setbuf(stdout, NULL);

	int num1;
	int num2;

	int suma;
	int resta;
	int multiplicacion;
	float division;
	unsigned long int factorial1;
	unsigned long int factorial2;

	int bandera1 = 0;
	int bandera2 = 0;
	int bandera3 = 0;
	char salir = 'n';

	do {

		switch (menu(bandera1, bandera2, num1, num2)) {

		case 1:
			ingresarOperando(&num1);
			bandera1 = 1;
			break;

		case 2:
			if (bandera1) {
				ingresarOperando(&num2);
				bandera2 = 1;
			} else {

				printf("Primero debe ingresarse el primer operando \n");
				system("Pause");
			}

			break;

		case 3:
			if (!bandera1) {
				printf("Primero deben ingresarse los operandos \n");

			} else if (bandera1 && !bandera2) {
				printf("Primero debe ingresarse el segundo operando \n");

			} else {
				printf("\n\n************CALCULOS RESUELTOS************\n\n\n");
				printf("Ingrese opcion 4 en el menu para ver los resultados\n\n\n");

				suma = sumar(num1, num2);
				resta = restar(num1, num2);
				multiplicacion = multiplicar(num1, num2);
				division = dividir(num1, num2);
				factorial1 = factorizar(num1);
				factorial2 = factorizar(num2);

				bandera3 = 1;




			}
			system("Pause");
			break;

		case 4:
			if (bandera3) {
				informarResultados(num1, num2, suma, resta, multiplicacion,
						division, factorial1, factorial2);

				//reinicio las banderas
				bandera1 = 0;
				bandera2 = 0;
				bandera3 = 0;
			} else if (!bandera3 && bandera1 && bandera2) {
				printf("Se deben realizar los calculos antes de informar los resultados. Ingrese la opcion 3 en el menu.\n\n\n");

			} else if ((!bandera3 && !bandera1 && !bandera2) || (bandera1 && !bandera2 && !bandera3)) {
				printf("Primero debe ingresar los dos operandos y realizar los calculos\n\n\n");
			}

			system("Pause");
			break;

		case 5:
			verificarSalida(&salir);
			break;

		}

	} while (salir == 'n');

	return EXIT_SUCCESS;
}

