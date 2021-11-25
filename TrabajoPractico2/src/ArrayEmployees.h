

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_


typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}Employee;

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len);


/** \brief This function loads and validates the employees' data
 *
 * \param name Char array to save employee name
 * \param lastname Char array to save employee last name
 * \param salary float* pointer to variable salary in main menu to save employee salary
 * \param sector int* pointer to variable sector in main menu to save employee sector
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int uploadEmployeeData(char name[],char lastname[],float* salary,int* sector);



/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);



/** \brief this function searches free space into the employees array
 *
 * \param list Employee*
 * \param length int
 * \return employee index position or (-1) if [Invalid length or NULL
pointer received or space not found]
 *
 */
int searchFreeSpace(Employee* list, int len);




/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee* list, int length);



/** \brief print the content of one employee
 * \param Employee one employee of employees array
 *
 */
void printOneEmployee(Employee oneEmployee);




/** \brief find an Employee by Id and returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id);



/** \brief this function modifies an employee data by entering the ID
 *
 * \param list Employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
 */
int modifyEmployees(Employee *list, int len);



/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id);




/** \brief total amount of employees on the list
 *
 * \param list Employee*
 * \param len int
 * \return int quantity of employees
 *
 */
int totalOfEmployees(Employee *list, int len);



/** \brief total amount of salaries of the employees' list
 *
 * \param list Employee*
 * \param len int
 * \return float total of salaries
 *
 */
int totalOfSalaries(Employee* list, int len);



/** \brief this function calculates the average salary of the employees' list salaries
 *
 * \param float the total amount of the employees' salaries
 * \param int employeesQuantity
 * \return float average salary
 *
 */
float calculateAverage(float salaries, int employeesQuantity);




/** \brief this function calculates the quantity of salaries than are higher than average salary
  * \param list Employee*
 * \param len int
 * \return int counter of the quantity of salaries higher than average
 *
 */
int salaryHigherThanAverage(Employee* list, int len,float average);




/** \brief this function print the results of option B on the report
  * \param list Employee*
 * \param len int
 * \return void
 *
 */
void printTotalAndAverageSalary(Employee* list, int len);





/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order);




/** \brief Swap the positions of the array content
 * \param list Employee*
 * \param len int
 * * \param int index 1 to move into the array
 * * \param int index 2 to move into the array
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int swap(Employee* list, int len,int indexI, int indexJ);



/** \brief this function organizes the data to be shown to the user in option 4
 * \param list Employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int report(Employee *list, int len);






#endif /* ARRAYEMPLOYEES_H_ */

