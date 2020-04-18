#include <stdlib.h>

/** \brief - Muestra un listado de opciones con el numero ingresado.
 *
 * \param numUno float - Primer numero ingresado.
 * \param numDos float - Segundo numero ingresado.
 * \return int - Retorna la opcion elegida del menu.
 *
 */
int menu(float numUno, float numDos);

/** \brief - Pide al usuario que ingrese un numero con un mensaje que puede variar.
 *
 * \param mje[] char - Mensaje elejido para la tarea a realizar.
 * \return float - Retorna el numero ingresado por el usuario.
 *
 */
float pedirNumero(char mje[]);

/** \brief - Realiza la suma de dos numeros.
 *
 * \param numeroUno float - Primer numero.
 * \param numeroDos float - Segundo numero.
 * \return float - Retorna la suma de los numeros.
 *
 */
float suma(float numeroUno,float numeroDos);

/** \brief - Realiza la resta de dos numeros.
 *
 * \param numeroUno float - Primer numero.
 * \param numeroDos float - Segundo numero.
 * \return float - Retorna la resta de los numeros.
 *
 */
float resta(float numeroUno,float numeroDos);

/** \brief - Realiza la division de dos numeros
 *
 * \param numeroUno float - Primer numero.
 * \param numeroDos float - Segundo numero
 * \return float - Retorna la division de los numeros.
 *
 */
float division(float numeroUno,float numeroDos);

/** \brief - Realiza la multiplicacion de dos numeros
 *
 * \param numeroUno float - Primer numero.
 * \param numeroDos float - Segundo numero.
 * \return float - Retorna la multiplicacion de los numeros.
 *
 */
float multiplicacion(float numeroUno,float numeroDos);

/** \brief - Realiza el factorial de un numero
 *
 * \param numero float - Numero ingresado.
 * \return long long int - Retorna el resultado del factorial de dicho numero.
 *
 */
int factorial(float numero);

void factorialValidado( float numeroUno, float numeroDos,int factorialUno, int factorialDos);
