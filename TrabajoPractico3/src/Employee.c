#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"
#include "LinkedList.h"



Employee* employee_new(){

	Employee* nuevoEmpleado=(Employee*)malloc(sizeof(Employee));
	return nuevoEmpleado;
}




Employee* employee_newParametrosStr(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){

	Employee* nuevoEmpleado = employee_new();

	if (nuevoEmpleado != NULL && idStr != NULL && nombreStr!= NULL
			&& horasTrabajadasStr != NULL && sueldoStr != NULL) {
		if (!(employee_setId(nuevoEmpleado, atoi(idStr))
				&& employee_setNombre(nuevoEmpleado, nombreStr)
				&& employee_setHorasTrabajadas(nuevoEmpleado, atoi(horasTrabajadasStr))
				&& employee_setSueldo(nuevoEmpleado, atoi(sueldoStr)))) {

			free(nuevoEmpleado);
			nuevoEmpleado = NULL;
		}

	}

	return nuevoEmpleado;

}



Employee* employee_newParametrosNoStr(int id,char* nombre,int horasTrabajadas, int sueldo){

	Employee* nuevoEmpleado = employee_new();

		if (nuevoEmpleado != NULL && nombre!= NULL) {
			if (!(employee_setId(nuevoEmpleado, id)
					&& employee_setNombre(nuevoEmpleado,nombre)
					&& employee_setHorasTrabajadas(nuevoEmpleado,horasTrabajadas)
					&& employee_setSueldo(nuevoEmpleado,sueldo))) {

				free(nuevoEmpleado);
				nuevoEmpleado = NULL;
			}

		}

		return nuevoEmpleado;

}







int employee_setId(Employee* this,int id){

	int retorno=0;

		if(this!=NULL && id>=0){
			this->id=id;
			retorno=1;
		}

		return retorno;
}



int employee_setNombre(Employee* this,char* nombre){

	int retorno=0;
		if(this!=NULL && nombre!=NULL && strlen(nombre)>0 && strlen(nombre)<128){
			strcpy(this->nombre,nombre);
			retorno=1;
		}

		return retorno;
}



int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){

	int retorno = 0;
	if (this != NULL && horasTrabajadas>=0) {
		this-> horasTrabajadas = horasTrabajadas;
		retorno = 1;
	}

	return retorno;
}


int employee_setSueldo(Employee* this,int sueldo){

	int retorno = 0;
	if (this != NULL && sueldo >= 0) {
		this-> sueldo = sueldo;
		retorno = 1;
	}

	return retorno;
}





int employee_getId(Employee* this,int* id){

	int retorno=0;
	if(this!=NULL && id!=NULL){

		*id=this ->id;
		retorno=1;
	}

	return retorno;
}



int employee_getNombre(Employee* this,char* nombre){

	int retorno=0;
	if(this!=NULL && nombre!=NULL){

		strcpy(nombre, this->nombre);
		retorno=1;
	}

	return retorno;
}


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){

	int retorno=0;
		if(this!=NULL && horasTrabajadas!=NULL){

			*horasTrabajadas=this->horasTrabajadas;
			retorno=1;
		}

		return retorno;
}


int employee_getSueldo(Employee* this,int* sueldo){

	int retorno=0;
		if(this!=NULL && sueldo!=NULL){

			*sueldo=this->sueldo;
			retorno=1;
		}

		return retorno;
}



void employee_delete(Employee* this){

	if (this != NULL) {
		free(this);
		this=NULL;
	}

}



int employee_findEmployeeById(LinkedList* pArrayListEmployee, int* id){

	int retorno=-1;
	Employee* auxEmpleado;
	int len;
	int auxId;
	len=ll_len(pArrayListEmployee);




	if(pArrayListEmployee!=NULL && id!=NULL){

		for(int i=0; i<len; i++){
			auxEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
			employee_getId(auxEmpleado,&auxId);

			if(auxEmpleado!=NULL && auxId==*id)
			 {
			     retorno=i;
			     break;
			 }
		}
	}

	return retorno;
}



int employee_compararPorSueldo(void*emp1,void* emp2)
{
    int retorno = 0;

    Employee* empA = NULL;
    Employee* empB = NULL;


    if(emp1 != NULL && emp2 != NULL)
    {
        empA = (Employee*) emp1;
        empB = (Employee*) emp2;


        if(empA->sueldo > empB->sueldo)
        {
            retorno = 1;
        }
        else
        {
            if(empA->sueldo == empB->sueldo)
            {
                retorno = 0;
            }else
            {
                 retorno = -1;
            }
        }
    }

    return retorno;
}



int employee_compararPorHorasTrabajadas(void*emp1,void* emp2)
{
    int retorno = 0;

    Employee* empA = NULL;
    Employee* empB = NULL;


    if(emp1 != NULL && emp2 != NULL)
    {
        empA = (Employee*) emp1;
        empB = (Employee*) emp2;


        if(empA->horasTrabajadas > empB->horasTrabajadas)
        {
            retorno = 1;
        }
        else
        {
            if(empA->horasTrabajadas == empB->horasTrabajadas)
            {
                retorno = 0;
            }else
            {
                 retorno = -1;
            }
        }
    }

    return retorno;
}


int employee_compararPorId(void*emp1,void* emp2)
{
    int retorno = 0;

    Employee* empA = NULL;
    Employee* empB = NULL;


    if(emp1 != NULL && emp2 != NULL)
    {
        empA = (Employee*) emp1;
        empB = (Employee*) emp2;


        if(empA->id > empB->id)
        {
            retorno = 1;
        }
        else
        {

           retorno = -1;

        }
    }

    return retorno;
}

int employee_compararPorNombre(void*emp1,void* emp2){

	int retorno = 0;
	Employee* empA = NULL;
	Employee* empB = NULL;

	if(emp1 != NULL && emp2 !=NULL)
	{
	   empA = (Employee*) emp1;
	   empB = (Employee*) emp2;

	        if(strcmp(empA->nombre,empB->nombre)>0)
	        {
	            retorno = 1;
	        }
	        else
	        {
	            if(strcmp(empA->nombre,empB->nombre)== 0)
	            {
	                retorno = 0;
	            }else
	            {
	                retorno = -1;
	            }
	        }
	    }

	    return retorno;
}


int employee_generarId(int* id)
{
    int retorno=0;
    FILE* f;

    if(id!=NULL)
    {
        *id=1001;
        f=fopen("backupID.bin","rb");
        if(f!=NULL)
        {
            fread(id,sizeof(int),1,f);
            retorno=1;

            fclose(f);
        }
    }

    return retorno;
}

int employee_reestablecerId(int id)
{
    int retorno=0;
    FILE* f;

    id++;

    f=fopen("backupID.bin","wb");
    if(f!=NULL)
    {
        fwrite(&id,sizeof(int),1,f);
        retorno=1;
        fclose(f);
    }

    return retorno;
}

