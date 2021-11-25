#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Get.h"
#include "parser.h"
#include "Controller.h"
#include "menu.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=0;
    FILE* pFile;

	if(path!=NULL && pArrayListEmployee!=NULL){

		pFile= fopen(path,"r");

		if(pFile != NULL){

		  if(parser_EmployeeFromText(pFile,pArrayListEmployee))
			{
			  retorno=1;
			}

			fclose(pFile);

		}
		else
		{
			printf("Ocurrio un problema al intentar abrir el archivo de texto.\n");
			exit(1);
		}


	}
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{

	int retorno=0;
	FILE* pFile;


	if(path!=NULL && pArrayListEmployee!=NULL){


		pFile= fopen(path,"rb");
		if(pFile!=NULL){

           if(parser_EmployeeFromBinary(pFile,pArrayListEmployee)){

					    retorno=1;


		     }
           fclose(pFile);
		}


	}



    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=0;
	Employee* auxEmpleado=NULL;


	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	if(pArrayListEmployee!=NULL){


		printf("\n\n      ALTA EMPLEADO    \n");


		employee_generarId(&id);
		employee_reestablecerId(id);
		utn_getNombre(nombre,"Ingrese nombre: ","Nombre invalido.\n",128,10);
		horasTrabajadas= getOnlyInt("Ingrese horas trabajadas: ","Opcion invalida.\n");
		sueldo= getOnlyInt("Ingrese sueldo: ","Opcion invalida.\n");



		if( !(employee_setId(auxEmpleado,id) &&
		   employee_setNombre(auxEmpleado,nombre) &&
		   employee_setHorasTrabajadas(auxEmpleado,horasTrabajadas) &&
		   employee_setSueldo(auxEmpleado,sueldo))){



			auxEmpleado=employee_newParametrosNoStr(id,nombre,horasTrabajadas,sueldo);


			ll_add(pArrayListEmployee, auxEmpleado);


			auxEmpleado=NULL;
			retorno=1;
		}


	}

    return retorno;
}






/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{

	int retorno= 0;

	Employee* auxEmpleado;
	int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

	int opcion;
	int indice;

	int flagNombre = 1;
	int flagHoras= 1;
	int flagSueldo = 1;


	if (pArrayListEmployee!=NULL) {

		printf("\n\n      MODIFICAR EMPLEADOS    \n");

		controller_ListEmployee(pArrayListEmployee);

		id=getOnlyInt("Ingrese ID del empleado a ser modificado:","Opcion invalida.\n");
		indice=employee_findEmployeeById(pArrayListEmployee,&id);
		auxEmpleado=ll_get(pArrayListEmployee,indice);


			if (auxEmpleado == NULL ) {
				printf("Error: Empleado no encontrado.\n");
				system("pause");
			} else {


				printf("\nEmpleado encontrado:\n");
				printf("ID     Nombre    Horas trabajadas   Sueldo\n");
                controller_ListOneEmployee(auxEmpleado);

				do {
					opcion = menuModificaciones();
					switch (opcion) {
					case 1:
						flagNombre = utn_getNombre(nombre,"Ingrese nuevo nombre:", "Error.\n", 128, 10);
						break;
					case 2:
						horasTrabajadas=getOnlyInt("Ingrese nueva cantidad de horas trabajadas:","Opcion invalida.\n");
						flagHoras =0;
	                    break;
					case 3:
						sueldo=getOnlyInt("Ingrese nuevo sueldo:","Opcion invalida.\n");
						flagSueldo =0;
	                    break;
					case 4:
						printf("\nCambios cancelados. Volviendo al menu principal...\n");
						system("pause");
						break;
					case 5:
						if (!flagNombre){
							employee_setNombre(auxEmpleado,nombre);
						}

						if (!flagHoras) {
							employee_setHorasTrabajadas(auxEmpleado,horasTrabajadas);
						}
						if (!flagSueldo) {
							employee_setSueldo(auxEmpleado,sueldo);
						}

						printf("\nEmpleado modificado con exito. Volviendo al menu principal...\n");
						system("pause");
						break;

					}

				} while ( opcion!=4 && opcion!=5);

				retorno=1;
			}

		}



    return retorno;

}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{

	int retorno=0;

	Employee* auxEmpleado;

	int id;
	int indice;
	char opcion;

	if(pArrayListEmployee!=NULL){


		printf("\n\n      BAJA EMPLEADO    \n");
		controller_ListEmployee(pArrayListEmployee);
		id=getOnlyInt("Ingrese ID del empleado que desea dar de baja:","Opcion invalida.\n");
		indice=employee_findEmployeeById(pArrayListEmployee,&id);


		if(indice==-1){

			printf("No existe empleado con el id %d\n",id);
		}
		else
		{
			auxEmpleado=(Employee*)ll_get(pArrayListEmployee,indice);

			printf("\n\nID       Nombre    Horas Trabajas    Sueldo\n ");
			controller_ListOneEmployee(auxEmpleado);
			getCharDosOpciones(&opcion,"\nConfirma la baja de este empleado? s/n:","Opcion invalida.\n",'s','n');

			if(opcion=='s'){

				ll_remove(pArrayListEmployee,indice);
				auxEmpleado=NULL;
				retorno=1;
			}
			else
			{
				printf("Baja cancelada.\n");
				system("pause");
			}
		}



	}

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=0;
	int tam;

	if(pArrayListEmployee!=NULL){

	tam= ll_len(pArrayListEmployee);
	printf("\n");
	for(int i=0; i<tam; i++){
		controller_ListOneEmployee((Employee*)ll_get(pArrayListEmployee,i));
	}
	    printf("\n\n");
	    retorno=1;
	}

   return retorno;

}



int controller_ListOneEmployee(Employee* this){

	int retorno=0;

	int id;
	char nombre[20];
	int horasTrabajadas;
	int sueldo;

	if(this!=NULL
	&& employee_getId(this,&id)
	&& employee_getNombre(this,nombre)
	&& employee_getHorasTrabajadas(this,&horasTrabajadas)
	&& employee_getSueldo(this ,&sueldo)){

		printf("%d      %s    %d    %d\n",
				id,
				nombre,
				horasTrabajadas,
				sueldo);
		retorno=1;
	}

	return retorno;
}



/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno= 0;


	int opcion;
	int criterio;  // 0 Ascendente   1 Descendente


	    if(pArrayListEmployee != NULL)
	    {


	    	do{
	    		 opcion=menuOrdenamiento();

	    		 if(opcion>=1 && opcion<=4){
	    			 utn_getNumero(&criterio,"Ingrese criterio de ordenamiento (0 Ascendente   1 Descendente):","Opcion invalida.\n",0,1,10);
	    			 printf("Ordenando empleados, por favor espere unos segundos...\n");
	    		 }


	    			       switch(opcion)
	    			       {
	    			        case 1:

	    			         ll_sort(pArrayListEmployee,employee_compararPorNombre,criterio);

	    			         break;
	    			         case 2:
	    		               ll_sort(pArrayListEmployee,employee_compararPorHorasTrabajadas,criterio);

	    			         break;
	    			        case 3:
	    			            ll_sort(pArrayListEmployee,employee_compararPorSueldo,criterio);


	    			         break;
	    			        case 4:
	    			            ll_sort(pArrayListEmployee,employee_compararPorId,criterio);
	    		              break;
	    			        case 5:
	    			        	printf("Volviendo al menu principal...\n");
	    			        	break;

	    			        }
	    	}while(opcion!=5);


             retorno=1;

	    }


	    return retorno;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{

	int retorno=0;
    Employee* auxEmpleado;
	FILE* pFile;
	int cant;

	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	if(path!=NULL && pArrayListEmployee!=NULL){

		pFile= fopen(path,"w");
		if (pFile == NULL) {

			printf("No se pudo abrir el archivo\n");
			exit(1);

		}

		fprintf(pFile,"ID,Nombre,Horas Trabajadas,Sueldo\n");

		for(int i=0; i<ll_len(pArrayListEmployee); i++){

			auxEmpleado=ll_get(pArrayListEmployee,i);
			if(auxEmpleado!=NULL &&
					employee_getId(auxEmpleado,&id) &&
					employee_getNombre(auxEmpleado,nombre) &&
					employee_getHorasTrabajadas(auxEmpleado,&horasTrabajadas) &&
					employee_getSueldo(auxEmpleado,&sueldo)){

				cant=fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
				if(cant==4){
					break;
				}
				retorno=1;
			}



		}

		fclose(pFile);
		auxEmpleado=NULL;

	}


    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{

	int retorno=0;
	FILE* pFile;
	Employee* auxEmpleado;

	int cant;

	if(path!=NULL && pArrayListEmployee!=NULL){

		pFile=fopen("path","wb");
		if(pFile==NULL){
			printf("No se pudo abrir el archivo\n");
			exit(1);
		}

		for(int i=0; i<ll_len(pArrayListEmployee) ; i++){

			auxEmpleado=ll_get(pArrayListEmployee,i);
			if(auxEmpleado!=NULL){

				cant=fwrite(auxEmpleado,sizeof(Employee),1,pFile);
				if(cant<1){
					break;
				}
			}

		}



		fclose(pFile);
		auxEmpleado=NULL;
		retorno=1;
	}

    return retorno;
}




