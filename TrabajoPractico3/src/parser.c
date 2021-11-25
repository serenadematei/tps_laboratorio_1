#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=0;

	Employee* auxEmpleado=NULL;
	char encabezado[200];
	char buffer[4][20];
	int cant;

    if(pFile!=NULL && pArrayListEmployee!=NULL){

    	fscanf(pFile,"%s",encabezado); //lectura fantasma del encabezado

    	do{

    		cant = fscanf(pFile,"%[^,], %[^,], %[^,], %[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

    		if(cant<4){
    		   break;
    		 }

    		auxEmpleado= employee_newParametrosStr(buffer[0],buffer[1],buffer[2],buffer[3]);
    		ll_add(pArrayListEmployee, auxEmpleado);

    		auxEmpleado=NULL;


    	}while(!feof(pFile));

    	retorno=1;
    }

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=0;
	int cant;
	Employee* auxEmpleado=NULL;

	if(pFile!=NULL && pArrayListEmployee!=NULL){

		fread(auxEmpleado,sizeof(Employee),1,pFile);//lectura fantasma del encabezado
		while(!feof(pFile))
		{

		   auxEmpleado=employee_new();
		   if(auxEmpleado!=NULL)
		    {
		        cant=fread(auxEmpleado,sizeof(Employee),1,pFile); //cargo un empleado desde el archivo
		        if(cant==1)    //si no llego al final del archivo
		        {
		            ll_add(pArrayListEmployee,auxEmpleado);
		            auxEmpleado=NULL;
		            retorno=1;
		        }
		        else//si no pudo cargar al empleado o si llego al final del archivo
		        {
		          employee_delete(auxEmpleado);
		          break;

		        }
		    }

		 }

	}
    return retorno;
}
