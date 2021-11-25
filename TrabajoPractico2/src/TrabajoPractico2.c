/*
 ============================================================================
 Name        : TrabajoPractico2.c
 Author      : Serena Dematei
 Description : ABM employees
 ============================================================================
 */

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


#define LEN 1000


int main(void) {

	setbuf(stdout, NULL);

	char exit='n';


	int id=2000;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int index;
	int auxId;
	int flag=0;


    Employee list[LEN];//= {{2000,"Carlos","Deluca",54000,500,0},{2001,"Esteban","Fauri",59000,503,0},{2003,"Roxana","Vignau",19000,501,0},
    		//{2004,"Sonia","Lopez",14400,502,0},{2005,"Rosa","Andrade",89000,500,0},{2006,"Ana","Andrade",78000,505,0}};

	initEmployees(list,LEN);

	    	do {

	    		switch(menu()){
	    		case 1:
	    			if(searchFreeSpace(list,LEN)==-1){
	    				printf("\nError: No space for a new employee\n");
	    			}
	    			else
	    			{
	    				uploadEmployeeData(name,lastName,&salary,&sector);
	    				if(!addEmployee(list,LEN,id,name,lastName,salary,sector)){

	    					printf("\nEmployee added successfully.\n");
	    					id++;   //autoincremental ID
	    					flag=1;

	    				  }
	    			}
	    			system("pause");
	    			break;

	    		case 2:
                    if(flag)
                    {
                    	modifyEmployees(list,LEN);
                    }
                    else
                    {
                    	printf("First an employee must be entered\n");
                    }
	    			break;

	    		case 3:
			     if (flag) {
				      printEmployees(list, LEN);
				      printf("Enter ID of the employee to be removed: ");
				      scanf("%d", &auxId);

				      index = findEmployeeById(list, LEN, auxId);

				      if (index == -1) {
					   printf("Error: Employee not found.\n");
					   system("pause");
				       } else {
					   removeEmployee(list, LEN, auxId);
				       }

				        system("pause");
			     }
			     else
			     {
			    	 printf("First an employee must be entered\n");
			     }

	    			break;

	    		case 4:
	    			if(flag){
	    			   report(list,LEN);
	    			}
	    			else
	    			{
	    				printf("First an employee must be entered\n");
	    			}

	    			system("pause");
	    			break;


			case 5:
				   checkExit(&exit);
				   break;
	    		}
	    	}while(exit=='n');



	return EXIT_SUCCESS;
}


