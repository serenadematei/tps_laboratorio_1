#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "menu.h"
#include "Get.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{

	setbuf(stdout,NULL);
    int option;
    int flagCsv=0;
    int flagBin=0;


    LinkedList* listaEmpleados = ll_newLinkedList();
    if(listaEmpleados==NULL){
    	printf("Ocurrio un problema al crear el LinkedList\n");
    	exit(1);
    }




    do{

    	option=menu();
        switch(option)
        {
            case 1:
            	if(flagCsv || flagBin){

            		printf("Los empleados ya fueron cargados.\n");

            	}
            	else
            	{
            		if(controller_loadFromText("data.csv",listaEmpleados)){

            		  printf("Empleados cargados desde el archivo de texto con exito.\n");
            		  flagCsv=1;

            		 }
            	     else
            		 {
            		   printf("Problemas al cargar los empleados desde el archivo de texto.\n");
            		 }


            	}

                system("pause");
                break;
            case 2:
            	 if(flagCsv||flagBin)
            	 {
            	    printf("\nLos empleados ya fueron cargados\n\n");
            	 }
            	 else
            	 {
            		 if (controller_loadFromBinary("data.bin", listaEmpleados)) {

            			 printf("Empleados cargados desde el archivo binario con exito.\n");
            			 flagBin = 1;
            		 }
            		 else
            		 {
            			printf("Problemas al cargar los empleados desde el archivo binario.\n");
            		  }

            	 }
            	 system("pause");
			    break;
            case 3:
            	if(!flagCsv && !flagBin)
            	{
            	   printf("Antes de dar de alta, se deben cargar los empleados desde un archivo\n");
            	}
               else
            	{

            		if(controller_addEmployee(listaEmpleados))
            		  {
            		    printf("Empleado dado de alta con exito.\n");
            		  }
            		  else
            		  {
            		     printf("Ocurrio un problema al dar de alta.\n");
            		  }

               }
            	system("pause");
            	break;
            case 4:
            	if(flagCsv||flagBin)
            	{
            		controller_editEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("Deben cargarse los empleados desde un archivo antes de modificarlos.\n");
            	}
            	system("pause");
            	break;
            case 5:
            	if(!flagCsv && !flagBin)
            	{
            	    printf("Antes de dar de baja, se deben cargar los empleados desde un archivo\n");
            	}
            	else
            	{
            		if(controller_removeEmployee(listaEmpleados))
            		  {
            		     printf("Empleado dado de baja con exito\n");
            		  }
            		else
            		  {
            		     printf("Ocurrio un problema al dar de baja.\n");
            		  }

            	}

            	system("pause");
            	break;
            case 6:
                  if(flagCsv||flagBin)
                  {
                     controller_ListEmployee(listaEmpleados);
                  }
                  else
                 {
                    printf("Deben cargarse los empleados desde un archivo antes de listarlos.\n");
                 }

                 system("pause");
                 break;
            case 7:
            	if(flagCsv||flagBin)
            	{
            	    controller_sortEmployee(listaEmpleados);
            	}
            	else
            	{
            	    printf("Deben cargarse los empleados desde un archivo antes de ordenarlos.\n");
            	}
            	system("pause");
            	break;


            case 8:
            	if(!flagCsv && !flagBin){
            		printf("Se deben cargar los datos de los empleados antes de guardarlos en el archivo.\n");
            	}
            	else
            	{
            		if(controller_saveAsText("data.csv",listaEmpleados))
            		 {
            		      printf("Empleados guardados en el archivo de texto con exito.\n");
            		 }
            		 else
            		 {
            		     printf("Problema al guardar los datos de los empleados en archivo de texto.\n");
            		 }
            	}
            	system("pause");
            	break;
            case 9:
			    if(!flagCsv && !flagBin){
				     printf("Se deben cargar los datos de los empleados antes de guardarlos en el archivo.\n");
			    }
			    else
			    {
				      if (controller_saveAsBinary("data.bin",listaEmpleados)) {
					       printf("Empleados guardados en el archivo binario con exito.\n");
				      }
				      else
				      {
					     printf("Problema al guardar los datos de los empleados en archivo binario.\n");
				      }
			}
			system("pause");
			break;
            case 10:
            	break;
            default:
            	printf("Ingrese una opcion del 1 al 10.\n\n");
            	break;
        }
    }while(option != 10);


    return 0;
}

