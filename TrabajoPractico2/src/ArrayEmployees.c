
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


int initEmployees(Employee* list, int len)
{
	int retorno=-1;

	 if(list != NULL && len>0){

		   for(int i=0; i<len; i++){
			   list[i].isEmpty=1;
			   retorno=0;
		   }
	   }

	return retorno;
}





int uploadEmployeeData(char name[],char lastname[],float* salary,int* sector){

	int itsOk= -1;
	char auxName[51];
	char auxLastName[51];
	int auxSector;
	float auxSalary;



	if(name!=NULL && lastname!=NULL && salary!=NULL && sector!=NULL){


		printf("\n\n\n************ ADD EMPLOYEE ************ \n");
		utn_getNombre(auxName,"Enter name: ","Error.\n",51,10);
		utn_getNombre(auxLastName,"Enter last name: ","Error.\n",51,10);
		utn_getNumero(&auxSector,"Enter sector  (1-3):","Error.\n",1,3,10);
		utn_getNumeroFlotante(&auxSalary,"Enter salary:","Error.\n",1,999999,10);




		strcpy(name,auxName);
		strcpy(lastname,auxLastName);
		*sector=auxSector;
		*salary=auxSalary;



		itsOk=0;

	}

	return itsOk;
}



int addEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector)
{
    int itsOk=-1;
    int index;
    Employee newEmployee;

	if(name!=NULL && lastName!=NULL && len>0){
		index=searchFreeSpace(list,len);



			newEmployee.id=id;
			newEmployee.salary=salary;
			newEmployee.sector=sector;
			strcpy(newEmployee.name,name);
			strcpy(newEmployee.lastName,lastName);
			newEmployee.isEmpty=0;


			list[index]=newEmployee;
			itsOk=0;



	}
	return itsOk;
}



int searchFreeSpace(Employee* list, int len){

	int index=-1;
	if(list!=NULL && len>0){

		for(int i=0; i<len; i++){
			if(list[i].isEmpty){
				index=i;
				break;
			}
		}
	}

	return index;
}



int printEmployees(Employee* list, int length)
{
    int itsOk=-1;

    if(list!=NULL && length>0){
    	printf("\n\nID             NAME           LASTNAME      SALARY      SECTOR\n");
    	    for(int i=0; i<length; i++){
    	    	if(!list[i].isEmpty){
    	    		printOneEmployee(list[i]);
    	    		itsOk=0;
    	    	}
    	    }
    }

	return itsOk;
}



void printOneEmployee(Employee oneEmployee){


		printf("%4d       %10s      %10s        %.2f      %4d\n", oneEmployee.id,
				oneEmployee.name, oneEmployee.lastName, oneEmployee.salary,
				oneEmployee.sector);


}




int findEmployeeById(Employee* list, int len,int id)
{
    int index=-1;
    if(list!=NULL && len>0){
    	for(int i=0; i<len;i++){
    		if(!list[i].isEmpty && list[i].id==id){
    			index=i;
    			break;
    		}
    	}
    }

    return index;

}





int modifyEmployees(Employee *list, int len) {

	int itsOk = -1;

	Employee oneEmployee;
	int id;
	int index;
	int option;

	int flagName = 1;
	int flagLastName = 1;
	int flagSalary = 1;
	int flagSector = 1;

	if (list != NULL && len > 0) {
		printf(" **** EMPLOYEE MODIFICATION ****");
		printEmployees(list, len);
		printf("Enter ID of the employee to be modified:");
		scanf("%d", &id);

		index = findEmployeeById(list, len, id);
		if (index == -1) {
			printf("Error: Employee not found.\n");
			system("pause");
		} else {


			printf("\nEmployee found:\n");
			printf("ID             NAME           LASTNAME      SALARY   SECTOR\n");

			printOneEmployee(list[index]);

			do {
				option = menuModifications();
				switch (option) {
				case 1:
					flagName = utn_getNombre(oneEmployee.name,"Enter new name:", "Error.\n", 51, 10);
					break;
				case 2:
					flagLastName = utn_getNombre(oneEmployee.lastName,"Enter new last name:", "Error.\n", 51, 10);
                    break;
				case 3:
					flagSalary = utn_getNumeroFlotante(&oneEmployee.salary,"Enter new salary: ", "Error.\n", 1, 999999, 10);
                    break;
				case 4:
				flagSector = utn_getNumero(&oneEmployee.sector,"Enter new sector(1-3): ", "Error.\n", 1,3, 10);
					break;
				case 5:
					printf("\nChanges cancelled. Getting back to main menu...\n");
					system("pause");
					break;
				case 6:
					if (!flagName){
						strcpy(list[index].name, oneEmployee.name);
					}
					if (!flagLastName) {
						strcpy(list[index].lastName, oneEmployee.lastName);
					}
					if (!flagSalary) {
						list[index].salary = oneEmployee.salary;
					}
					if (!flagSector) {
						list[index].sector = oneEmployee.sector;
					}

					printf("\nEmployee has been modified successfully. Getting back to main menu...\n");
					system("pause");
					break;
				}

			} while ( option!=5 && option!=6);

			itsOk=0;
		}

	}

	   return itsOk;
}




int removeEmployee(Employee* list, int len, int id)
{
	int itsOk=-1;
	int index;
	char option;

	if(list!=NULL && len>0){

	index=findEmployeeById(list,len,id);
	printf("\nEmployee found:\n");
	printf("ID             NAME           LASTNAME      SALARY   SECTOR\n");
    printOneEmployee(list[index]);


    utn_getCaracter(&option,"Are you sure you want to remove this employee? (y/n):","Error.\n",'y','n',10);
            if(option=='y'){
            	list[index].isEmpty=1;
            	printf("The employee has been removed successfully\n");
            	itsOk=0;
            }
            else
            {
            	printf("\nThe process of removing employee has been canceled. Getting back to main menu...\n ");
            	system("pause");
            }
	}

    return itsOk;
}



int totalOfEmployees(Employee *list, int len) {

	int counterEmployees=0;

	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (!list[i].isEmpty) {
				counterEmployees++;
			}
		}
	}

	return counterEmployees;
}


int totalOfSalaries(Employee* list, int len){

	float total=0;

	if (list != NULL && len > 0) {
			for (int i = 0; i < len; i++) {
				if (!list[i].isEmpty) {
					total += list[i].salary;
				}
			}
		}

	return total;
}




float calculateAverage(float salaries, int employeesQuantity){

	float average;

    if (employeesQuantity > 0) {
		average = salaries / employeesQuantity;
	}


	return average;
}





int salaryHigherThanAverage(Employee* list, int len,float average){

	int counter=0;

	if(list!=NULL && len>0){
		for(int i=0; i<len; i++){
			if(!list[i].isEmpty && list[i].salary>average){
				 counter++;  //quantity of salaries than are higher than average salary
				}
			}
	}

	return counter;
}



void printTotalAndAverageSalary(Employee* list, int len){

	float total;
	float average;
	int counterEmployees;
	int counterSalaries;

	counterEmployees= totalOfEmployees(list,len);
	total=totalOfSalaries(list,len);
	average=calculateAverage(total, counterEmployees);

	counterSalaries=salaryHigherThanAverage(list,len,average);

	printf("\n Total amount of salaries: %.2f\n", total);
	printf(" Average salary: %.2f\n", average);
	printf(" Number of employees exceeding the average salary: %d\n",
			counterSalaries);

}



int report(Employee *list, int len) {

	int itsOk = -1;
	char option;
	int order;

	if (list != NULL && len > 0) {


		do {
			option = subMenuReport(list, len);
			switch (option) {
			case 'a':
				utn_getNumero(&order,"Enter [1] for ascending order or [2] for descending order: ","Error.\n", 1, 2, 10);
				sortEmployees(list, len, order);
				printEmployees(list, len);
				break;
			case 'b':
				printTotalAndAverageSalary(list, len);
				break;
			case 'c':
				break;

				itsOk = 0;
			}
		} while (option != 'c');

	}

	return itsOk;
}




int sortEmployees(Employee* list, int len, int order)
{
	int itsOk=-1;

     if(list!=NULL && len>0){

    	 for(int i=0; i<len-1; i++){
    		 for(int j=i+1; j<len; j++){

    			 if (!list[i].isEmpty && !list[j].isEmpty) {
					switch (order) {
					case 2: //descending order
						if( strcmp(list[i].lastName, list[j].lastName) == -1 ||
						  (!strcmp(list[i].lastName, list[j].lastName) && (list[i].sector > list[j].sector))) {

							swap(list,len,i,j);

						}

						break;
					case 1: //ascending order
						if (strcmp(list[i].lastName, list[j].lastName) == 1 || (!strcmp(list[i].lastName, list[j].lastName)
								&& (list[i].sector < list[j].sector))) {

							swap(list,len,i,j);
						}

						break;
						itsOk = 0;
					}
    			 }

    		 }
    	 }

     }

	return itsOk;
}




int swap(Employee* list, int len,int indexI, int indexJ){

	int itsOk=-1;
	Employee auxEmployee;


    if(list!=NULL && len>0){

    	auxEmployee = list[indexI];
    	list[indexI] = list[indexJ];
    	list[indexJ] = auxEmployee;
        itsOk=0;
    }


    return itsOk;
}

