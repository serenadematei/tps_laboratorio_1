//TP3
#include "Get.h"
#include "menu.h"


int menu(){

	int opcion;

	        printf("            **** MENU DE OPCIONES ****\n");
			printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
			printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
			printf("3. Alta de empleado\n");
			printf("4. Modificar datos de empleado\n");
			printf("5. Baja de empleado\n");
			printf("6. Listar empleados\n");
			printf("7. Ordenar empleados\n");
			printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
			printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
			printf("10. Salir\n");
			opcion=getOnlyInt("Ingrese opcion (1-10):","Opcion invalida.\n");


	return opcion;
}


int menuModificaciones(){

	int opcion;

	printf("\n\n  ***MENU MODIFICACIONES***\n");
	printf("1-\tModificar nombre\n");
	printf("2-\tModificar horas trabajadas\n");
	printf("3-\tModificar sueldo\n");
	printf("4-\tCancelar cambios y salir\n");
	printf("5-\tGuardar cambios y salir\n");


	utn_getNumero(&opcion,"Enter option:","Error.\n",1,6,10);
	return opcion;

}

int menuOrdenamiento(){

	int opcion;


	printf("\n\n  ***MENU ORDENAMIENTO DE EMPLEADOS***\n");
	printf("1-\tOrdenar por nombre\n");
	printf("2-\tOrdenar por horas trabajadas\n");
	printf("3-\tOrdenar por sueldo\n");
	printf("4-\tOrdenar por ID\n");
	printf("5-\tVolver al menu principal\n");


	opcion=getOnlyInt("Ingrese opcion (1-5):","Opcion invalida.\n");


	return opcion;

}
