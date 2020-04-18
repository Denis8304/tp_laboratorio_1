#include <stdio.h>
#include <stdlib.h>
#include "libreriaCalculator.h"

int main()
{
    float primerDato;
    float segundoDato;
    int opcion;
    float resultadoSuma;
    float resultadoResta;
    float resultadoDivision;
    float resultadomultiplicacion;
    int factorialUno;
    int factorialDos;

    do
    {

        opcion = menu(primerDato,segundoDato);

        system("cls");
        switch(opcion)
        {
            case 1:
                primerDato = pedirNumero("Ingrese primer operando: ");
                break;
            case 2:
                segundoDato = pedirNumero("Ingrese segundo operando: ");
                break;
            case 3:
                resultadoSuma = suma(primerDato, segundoDato);
                resultadoResta = resta(primerDato, segundoDato);
                resultadoDivision = division(primerDato,segundoDato);
                resultadomultiplicacion = multiplicacion(primerDato, segundoDato);
                factorialUno = factorial(primerDato);
                factorialDos = factorial(segundoDato);
                break;
            case 4:
                printf("\nEl resultado de %.2f + %.2f es: %.2f \n", primerDato, segundoDato, resultadoSuma);
                printf("\nEl resultado de %.2f - %.2f es: %.2f \n", primerDato, segundoDato, resultadoResta);
                if(segundoDato == 0)
                 {
                     printf("\nNo se puede dividir por 0.\n");
                 }
                 else
                 {
                     printf("\nEl resultado de %.2f / %.2f es: %.2f \n", primerDato, segundoDato, resultadoDivision);
                 }
                printf("\nEl resultado de %.2f * %.2f es: %.2f \n", primerDato, segundoDato, resultadomultiplicacion);

                factorialValidado(primerDato, segundoDato,factorialUno,factorialDos);

                system("pause");
                system("cls");
                break;
            case 5:
                break;
            default:
                printf("\nDEBE ELEGIR UNA OPCION DEL 1 AL 5.\n\n");
            break;
        }


    }while(opcion != 5);

    return 0;
}
