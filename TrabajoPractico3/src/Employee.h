#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;


/** \brief Reserva lugar en la memoria dinamica para un empleado
 * \return Employee* Return puntero al nuevo empleado
 */
Employee* employee_new();


/** \brief Reserva lugar en la memoria dinamica para un empleado y asigna sus campos con los valores pasados por parametro
 * \param char* id
 * \param char* nombre
 * \param char* horasTrabajadas
 *  \param char* sueldo
 * \return int Return NULL si error / puntero al nuevo empleado si Ok
 *
 */
Employee* employee_newParametrosStr(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);


/** \brief Reserva lugar en la memoria dinamica para un empleado y asigna sus campos con los valores pasados por parametro
 * \param char* id
 * \param char* nombre
 * \param char* horasTrabajadas
 *  \param char* sueldo
 * \return int Return NULL si error / puntero al nuevo empleado si Ok
 *
 */
Employee* employee_newParametrosNoStr(int id,char* nombre,int horasTrabajadas, int sueldo);



/**
** \brief Libera el espacio reservado para ese empleado en la memoria dinamica y lo hace apuntar a null
 * \param Employee* puntero al empleado que sera borrado
 * \return void
*/
void employee_delete();



/** \brief Setter del campo ID
 *
 * \param Employee* puntero al empleado al cual se le cargara el ID
 * \param int ID que se cargara
 * \return int 1 si todo salio bien, 0 si hubo un error
 *
 */
int employee_setId(Employee* this,int id);



/** \brief Getter del campo ID
 * \param Employee* puntero al empleado del cual se leera el campo ID
 * \param int* puntero que quedara cargado con lo que se lee en el campo ID del empleado
 * \return int 1 si todo salio bien, 0 si hubo un error
 *
 */
int employee_getId(Employee* this,int* id);



/** \brief Setter del campo Nombre
 *
 * \param Employee* puntero al empleado al cual se le cargara el nombre
 * \param char* nombre que se cargara
 * \return int 1 si todo salio bien, 0 si hubo un error
 *
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief Getter del campo Nombre
 * \param Employee* puntero al empleado del cual se leera el campo Nombre
 * \param int* puntero que quedara cargado con lo que se lee en el campo Nombre del empleado
 * \return int 1 si todo salio bien, 0 si hubo un error
 *
 */
int employee_getNombre(Employee* this,char* nombre);


/** \brief Setter del campo HorasTrabajadas
 *
 * \param Employee* puntero al empleado al cual se le cargara las horas trabajadas
 * \param int horas trabajadas que se cargaran
 * \return int 1 si todo salio bien, 0 si hubo un error
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);


/** \brief Getter del campo  HorasTrabajadas
 * \param Employee* puntero al empleado del cual se leera el campo HorasTrabajadas
 * \param int* puntero que quedara cargado con lo que se lee en el campo  HorasTrabajadas del empleado
 * \return int 1 si todo salio bien, 0 si hubo un error
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);



/** \brief Setter del campo Sueldo
 * \param Employee* puntero al empleado al cual se le cargara el sueldo
 * \param int sueldo que se cargara
 * \return int 1 si todo salio bien, 0 si hubo un error
 *
 */
int employee_setSueldo(Employee* this,int sueldo);


/** \brief Getter del campo Sueldo
 * \param Employee* puntero al empleado del cual se leera el sueldo
 * \param int* puntero que quedara cargado con lo que se lee en el campo sueldo del empleado
 * \return int 1 si todo salio bien, 0 si hubo un error
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);



/** \brief Recorre el archivo en busca del ultimo id para generar el siguiente
 *
 * \param int* id puntero donde cargare el id
 * \return  0 si error, 1 si todo ok
 *
 */
int employee_generarId(int* id);

/** \brief Carga el proximo id en un archivo
 *
 * \param int id
 * \return 0 si error, 1 si todo ok
 *
 */
int employee_reestablecerId(int id);




/** \brief Compara dos empleados segun sus sueldos
 *
 * \param  void* a puntero a uno de los empleados a comparar (emp1)
 * \param  void* b puntero a otro de los empleados a comparar (emp2)
 * \return int 1 si el sueldo del emp1 es mayor a el del emp2, -1 si viceversa, y 0 si son iguales
 *
 */
int employee_compararPorSueldo(void*emp1,void* emp2);




/** \brief Compara dos empleados segun sus nombres
 *
 * \param  void* a puntero a uno de los empleados a comparar (emp1)
 * \param  void* b puntero a otro de los empleados a comparar (emp2)
 * \return int 1 si el nombre del emp1 esta antes en el diccionario que el del emp2, -1 si viceversa, y 0 si son iguales
 *
 */
int employee_compararPorNombre(void*emp1,void* emp2);




/** \brief Compara dos empleados segun sus horas trabajadas
 *
 * \param  void* a puntero a uno de los empleados a comparar (emp1)
 * \param  void* b puntero a otro de los empleados a comparar (emp2)
 * \return int 1 si la cantidad de horas trabajas del emp1 es mayor a la del emp2, -1 si viceversa, y 0 si son iguales
 *
 */
int employee_compararPorHorasTrabajadas(void*emp1,void* emp2);


/** \brief Compara dos empleados segun su campo ID
 *
 * \param  void* a puntero a uno de los empleados a comparar  (emp1)
 * \param  void* b puntero a otro de los empleados a comparar  (emp2)
 * \return int 1 si el ID emp1 es mayor a el del emp2, -1 si viceversa, y 0 si son iguales
 *
 */
int employee_compararPorId(void*emp1,void* emp2);

/** \brief Recorre la lista de empleados en busca de un empleado cuyo id
 *  coincida con el id que la funcion recibe por parametro
 * \param  LinkedList* puntero a la lista de empleados
 * \param int* puntero a ID
 * \return int -1 si hubo un error, y si todo salio bien retorna el indice del empleado buscado
 *
 */
int employee_findEmployeeById(LinkedList* pArrayListEmployee, int* id);

#endif // employee_H_INCLUDED
