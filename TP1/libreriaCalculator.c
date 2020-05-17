#include <stdio.h>
#include <stdlib.h>

float pedirNumero(char mje[])
{
    float numero;

    printf("%s", mje);
    fflush(stdin);
    scanf("%f", &numero);

    return numero;
}

int menu(float numUno, float numDos)
{
    int opcion;

    printf("1 - 1er operando: %.2f", numUno);
    printf("\n2 - 2do operando: %.2f", numDos);
    printf("\n3 - Calcular todas las operaciones");
    printf("\n4 - Informar resultados");
    printf("\n5 - Salir\n");

    printf("\nElija una opcion:");
    scanf("%d", &opcion);


    return opcion;
}

float suma(float numeroUno,float numeroDos)
{
    float suma;

    suma = numeroUno + numeroDos;

    return suma;
}

float resta(float numeroUno,float numeroDos)
{
    float resta;

    resta = numeroUno - numeroDos;

    return resta;
}

float division(float numeroUno,float numeroDos)
{
    float division;

    division = numeroUno / numeroDos;

    return division;
}

float multiplicacion(float numeroUno,float numeroDos)
{
    float multiplicacion;

    multiplicacion = numeroUno * numeroDos;

    return multiplicacion;
}

int factorial(float numero)
{
    int resultado;
    resultado = 1;

    int i;
    for(i = numero;i > 0;i--)
    {
        resultado *= i;
    }

    return resultado;
}

void factorialValidado( float numeroUno, float numeroDos,int factorialUno, int factorialDos)
{
    if(numeroUno > 0 && numeroDos > 0)
    {
        printf("\nEl factorial de %d es: %d y el factorial de %d es: %d\n\n\n", (int)numeroUno, factorialUno, (int)numeroDos, factorialDos);
    }
    else if(numeroUno < 0 && numeroDos < 0)
    {
        printf("\nEl factorial de %d es: Numero invalido y el factorial de %d es: Numero invalido\n\n\n",(int)numeroUno,(int)numeroDos);
    }
    else if(numeroUno < 0)
    {
        printf("\nEl factorial de %d es: Numero invalido y el factorial de %d es: %d\n\n\n",(int)numeroUno,(int)numeroDos, factorialDos);
    }
    else
    {
        printf("\nEl factorial de %d es: %d y el factorial de %d es: Numero invalido \n\n\n", (int)numeroUno, factorialUno, (int)numeroDos);
    }
}


