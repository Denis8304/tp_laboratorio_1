typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}Employee;

/** \brief - Muestra un listado de opciones.
 *
 * \return int - Retorna la opcion elegida.
 *
 */
int menu();

/** \brief - Muestra un listado de opciones para modificar un empleado.
 *
 * \return char - Retorna la opcion elegida por el usuario.
 *
 */
char menuDatos();

/** \brief - Inicializa lista de empleados como vacio.
 *
 * \param list[] Employee - Lista de empleados.
 * \param len int - Largo del array.
 * \return int -
 *
 */
int initEmployees(Employee list[], int len);

/** \brief - Carga un Empleado.
 *
 * \return Employee - Retorna estructura el empleado.
 *
 */
Employee addEmployee();

/** \brief - Carga listado de empleados.
 *
 * \param list[] Employee - Lista de empleados.
 * \param len int - Largo del array.
 * \return int
 *
 */
int arrayEmployee(Employee list[], int len);

/** \brief - Muestra el listado de empleados.
 *
 * \param list[] Employee - Recibe listado de empleados.
 * \param len int - Largo del array.
 * \return int
 *
 */
int printEmployees(Employee list[], int len);

/** \brief - Muestra un solo empleado.
 *
 * \param list Employee - Recibe la estructura de un empleado.
 * \return void
 *
 */
void showAnEmployee(Employee list);

/** \brief - Modica o elimina un empleado.
 *
 * \param list[] Employee - Listado de empleados.
 * \param len int - Largo del array.
 * \param num int - Numero de la opcion para modificar o remover empleado.
 * \return int - Retorna el id ingresado por el usuario.
 *
 */
int modificationAndRemove(Employee list[], int len, int num);

/** \brief - Modifica los datos del empleado.
 *
 * \param list[] Employee - Listado de los empleados.
 * \param len int - Largo del array.
 * \param id int - Id para modificar.
 * \return void
 *
 */
void modificationEmployee(Employee list[], int len, int id);

/** \brief - Busca un lugar libre en un listado.
 *
 * \param list[] Employee - Listado de empleados.
 * \param len int - Largo del listado.
 * \return int - Retorna la posicion del listado libre.
 *
 */
int searchFree(Employee list[], int len);

/** \brief - Switch que ingresa a diferentes opciones del menu.
 *
 * \param list[] Employee - Listado de empleados.
 * \param len int - Largo del array.
 * \param num int - Numero para elegir la opcion deseada.
 * \return void
 *
 */
void selectOption(Employee list[], int len, int num);

/** \brief - Elimina un empleado.
 *
 * \param list[] Employee - Listado de empleados.
 * \param len int - Largo del listado.
 * \param id int - Id del empleado a eliminar.
 * \return int
 *
 */
int removeEmployee(Employee list[], int len, int id);

/** \brief - Ordena los empleados por apellido y por sector.
 *
 * \param list[] Employee - Listado de empleados.
 * \param len int - Largo del lisado.
 * \return void
 *
 */
void sortEmployees(Employee list[], int len);

/** \brief - Salario total de todos los empleados.
 *
 * \param list[] Employee - Lista de empleados.
 * \param len int - Largo de la lista.
 * \return float - Retorna la suma del total del salario de los empleados.
 *
 */
float totalSalaryEmployee(Employee list[], int len);

/** \brief - Promedio total de los empleados.
 *
 * \param list[] Employee - Listado de empleados.
 * \param len int - Largo del listado.
 * \return float - Retorna el promedio del salario total.
 *
 */
float averageSalary(Employee list[], int len);

/** \brief - Muestra listado de los empleados que cobran mas que el promedio.
 *
 * \param list[] Employee - Listado de empleados.
 * \param len int - Largo del listado.
 * \param average float - Promedio total de los empleados.
 * \return void
 *
 */
void exceedAverageSalary(Employee list[], int len, float average);

/** \brief - Valida que el usuario ingrese solo letras.
 *
 * \param text[] char - texto a validar.
 * \return int - Retorna 0 si tiene solo letras y 1 si contiene otro tipo de caracter.
 *
 */
int validationLetter(char text[]);

/** \brief - Valida que el usuario ingrese solo numeros.
 *
 * \param num[] char - Numero a validar.
 * \return int - Retorna 0 si tiene solo numeros y 1 si contiene otro tipo de caracter.
 *
 */
int validationNumber(char num[]);

/** \brief - Cantidad de empleados que cobran mas que el promedio
 *
 * \param list[] Employee - Listado de empleado.
 * \param len int - Largo del listado.
 * \param average float - Salario promedio.
 * \return int - Retorna la cantidad de empleados que cobran sobre el promedio.
 *
 */
int quantityExceedAverageSalary(Employee list[], int len, float average);

