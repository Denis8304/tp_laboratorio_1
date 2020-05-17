#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

#define CANT 5

int main()
{
    Employee listEmployees[CANT];
    int option;

    initEmployees(listEmployees, CANT);
    //hardcodeoEmpleados(listEmployees,CANT);

    do{
    option = menu();

    selectOption(listEmployees, CANT, option);

    }while(option != 5);

    return 0;
}
