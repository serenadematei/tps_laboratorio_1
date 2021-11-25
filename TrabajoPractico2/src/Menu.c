
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
#include "ArrayEmployees.h"
#include "Get.h"
#include "Menu.h"


int menu(){

	int option;

	        printf("            ********* EMPLOYEE MANAGEMENT *********\n");
			printf("1-Add employee\n");
			printf("2-Modify employee\n");
			printf("3-Remove employee\n");
			printf("4-Report: \n");
            printf("A)List of employees\n");
            printf("B)Total and average salary\n");

			printf("5-Exit\n");
			printf("Enter option (1-5):");
			scanf("%d",&option);


	return option;
}




int checkExit(char *exit) {
	int itsOk = 0;
	char option;

	if (exit != NULL) {
		utn_getCaracter(&option, "Are you sure you want to exit? (y/n): ",
				"Invalid option.\n", 'y', 'n', 10);
	}

	*exit = option;
	itsOk = 1;

	return itsOk;

}




int menuModifications(){

	int option;

	printf("\n\n  ***MENU MODIFICATIONS***\n");
	printf("1-\tModify name\n");
	printf("2-\tModify last name\n");
	printf("3-\tModify salary\n");
	printf("4-\tModify sector\n");
	printf("5-\tDelete changes and exit\n");
	printf("6-\tSave changes and exit\n");

	utn_getNumero(&option,"Enter option:","Error.\n",1,6,10);
	return option;

}

char subMenuReport(Employee* list, int len){

	char option;

	printf("\n\nA-\tList employees\n");
	printf("B-\tReport total and average salaries\n");
    printf("C-\tReturn to main menu\n");

    option= getChar("Enter option:","Invalid option. Please re-enter:");


	return option;
}



