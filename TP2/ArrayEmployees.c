#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

int menu()
{
    int num;

    printf("1 - Altas\n");
    printf("2 - Modificar\n");
    printf("3 - Baja\n");
    printf("4 - Informar\n");
    printf("5 - Salir\n\n");

    printf("Ingrese una opcion: ");
    scanf("%d", &num);

    return num;
}

char menuDatos()
{
    char caracter;

    printf("\na - Name\n");
    printf("b - Last name\n");
    printf("c - Salary\n");
    printf("d - Sector\n\n");

    printf("Ingrese una opcion: ");
    fflush(stdin);
    scanf("%c", &caracter);

    return caracter;
}

void selectOption(Employee list[], int len, int num)
{
    float total = totalSalaryEmployee(list, len);
    float promedio = averageSalary(list, len);
    int i;
    int band = 0;
    int quantity = quantityExceedAverageSalary(list, len, promedio);

    switch(num)
    {
        case 1:
            arrayEmployee(list, len);
            break;
        case 2:
        case 3:
            for(i = 0; i < len; i++)
            {
                if(list[i].isEmpty == 0)
                {
                    band = 1;
                }
            }
            if(band == 1)
            {
               modificationAndRemove(list, len, num);
            }
            else
            {
                printf("\nNo hay empleados cargados.\n");
            }
            break;
        case 4:
            for(i = 0; i < len; i++)
            {
                if(list[i].isEmpty == 0)
                {
                    band = 1;
                }
            }
            if(band == 1)
            {
                printf("\nLa cantidad de empleados que superan el salario promedio son: %d", quantity);
                exceedAverageSalary(list, len, promedio);
                printf("\nEl total de salario de todos los empleados es: %.2f\n", total);
                printf("\nEl promedio de salario de todos los empleados es: %.2f\n", promedio);
                printf("\nEmpleados ordenados por apellido y sector.");
                sortEmployees(list, len);
                printEmployees(list, len);
            }
            else
            {
                printf("\nNo hay empleados cargados.\n");
            }
            break;
        case 5:
            break;
        default:
            printf("Incorrecto. Vuelva a elegir una opcion.");
    }
    system("pause");
    system("cls");
}

int initEmployees(Employee list[], int len)
{
    int i;
    int empty = -1;
    for(i = 0; i < len; i++)
    {
        list[i].isEmpty = empty;
    }

    return 0;
}

int searchFree(Employee list[], int len)
{
    int i;
    int indice = -2;

    for(i = 0; i < len; i++)
    {
        if(list[i].isEmpty == -1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

Employee addEmployee()
{
    Employee datos;
    char auxNum[51];

    printf("Name: ");
    fflush(stdin);
    gets(datos.name);
    while(validationLetter(datos.name) == 0)
    {
        printf("Solo puede ingresar letras. Vuelva a intentarlo.\n");
        printf("Name: ");
        gets(datos.name);
    }

    printf("Last Name: ");
    gets(datos.lastName);
    while(validationLetter(datos.lastName) == 0)
    {
        printf("Solo puede ingresar letras. Vuelva a intentarlo.\n");
        printf("Last Name: ");
        gets(datos.lastName);
    }

    printf("Salary: ");
    gets(auxNum);
    while(validationNumber(auxNum) == 0)
    {
        printf("Solo puede ingresar numeros. Vuelva a ingresarlo.\n");
        printf("Salary: ");
        gets(auxNum);
    }
    datos.salary = atof(auxNum);

    printf("Sector: ");
    gets(auxNum);
    while(validationNumber(auxNum) == 0)
    {
        printf("Solo puede ingresar numeros. Vuelva a ingresarlo.\n");
        printf("Sector: ");
        gets(auxNum);
    }
    datos.sector = atoi(auxNum);

    datos.isEmpty = 0;

    return datos;
}

int arrayEmployee(Employee list[], int len)
{
    int indice = searchFree(list, len);

    if(indice != -2)
    {
        list[indice] = addEmployee();
        list[indice].id = indice+1;
    }
    else
    {
        printf("\nEsta toda la lista ocupada.\n");
    }

    return 0;
}

int printEmployees(Employee list[], int len)
{
    int i;

    printf("\n%10s %20s %20s %10s %10s\n\n", "ID", "NAME", "LASTNAME", "SALARY", "SECTOR");

    for(i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            printf("%10d %20s %20s %10.2f %10d\n", list[i].id,
                                               list[i].name,
                                               list[i].lastName,
                                               list[i].salary,
                                               list[i].sector);
        }
    }
    return 0;
}

void showAnEmployee(Employee list)
{
    if(list.isEmpty == 0)
    {
        printf("%10d %20s %20s %10.2f %10d\n", list.id,
                                           list.name,
                                           list.lastName,
                                           list.salary,
                                           list.sector);
    }
}

int removeEmployee(Employee list[], int len, int id)
{
    int i;
    int band = 0;

    for(i = 0; i < len; i++)
    {
        if(id == list[i].id)
        {
            band = 1;
            break;
        }
    }
    if(band == 1)
    {
        list[i].isEmpty = -1;
        printf("\nSe ha borrado correctamente el ID %d\n", id);
    }
    else
    {
        printf("\nEl ID ingresado no existe.\n");
    }
    return -1;
}

void modificationEmployee(Employee list[], int len, int id)
{
    int i;
    char menuDat;
    int band = 0;

    for(i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 0 && id == list[i].id)
        {
            band = 1;
            break;
        }
    }
    if(band == 1)
    {
        menuDat = menuDatos();

        switch(menuDat)
        {
            case 'a':
                printf("Name: ");
                fflush(stdin);
                gets(list[i].name);
                break;
            case 'b':
                printf("Last Name: ");
                fflush(stdin);
                gets(list[i].lastName);
                break;
            case 'c':
                printf("Salary: ");
                scanf("%f", &list[i].salary);
                break;
            case 'd':
                printf("Sector: ");
                scanf("%d", &list[i].sector);
                break;
        }
        printf("\nEl cambio se ha realizado con exito!\n");
    }
    else
    {
        printf("\nEl ID ingresado no existe.\n");
    }

    system("pause");
    system("cls");

    printf("\n%10s %20s %20s %10s %10s\n\n", "ID", "NAME", "LASTNAME", "SALARY", "SECTOR");
    for(i = 0; i < len; i++)
    {
        if(list[i].id == id)
        {
            showAnEmployee(list[i]);
        }
    }
}

int modificationAndRemove(Employee list[], int len, int num)
{

    int id;
    int i;
    int band = 0;
    char ingreso;

    for(i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            band = 1;
        }
    }
    if(band == 1)
    {
        printEmployees(list, len);
        printf("\nIngrese ID:");
        scanf("%d", &id);
        system("cls");
    }
    else
    {
        printf("\nNo hay empleados cargados.\n");
    }

    for(i = 0; i < len; i++)
    {
        if(list[i].id == id && list[i].isEmpty == 0)
        {
            printf("\n%10s %20s %20s %10s %10s\n\n", "ID", "NAME", "LASTNAME", "SALARY", "SECTOR");
            showAnEmployee(list[i]);

            printf("\nSeguro que desea realizar la operacion? Ingrese s/n: ");
            fflush(stdin);
            scanf("%c", &ingreso);
        }
    }
    while(ingreso != 's' && ingreso !='n')
    {
        printf("Incorrecto. Ingrese s/n: ");
        fflush(stdin);
        scanf("%c", &ingreso);
    }

    if(list[i].isEmpty == -1)
    {
        printf("El ID ingresado no existe.\n");
    }

    if(num == 2)
    {
        while(ingreso == 's')
        {
            modificationEmployee(list, len, id);
            break;
        }

    }
    else if(num == 3)
    {
        while(ingreso == 's')
        {
            removeEmployee(list, len, id);
            break;
        }

    }
    return id;
}

void sortEmployees(Employee list[], int len)
{
    int i;
    int j;
    Employee auxEmployee;

    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(strcmp(list[i].lastName,list[j].lastName) > 0)
            {
               auxEmployee  =  list[i];
               list[i] = list[j];
               list[j] = auxEmployee;
            }
            else if(strcmp(list[i].lastName,list[j].lastName) == 0)
            {
                if(list[i].sector < list[j].sector)
                {
                    auxEmployee  =  list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                }
            }
        }
    }
}

float totalSalaryEmployee(Employee list[], int len)
{
    int i;
    float total = 0;

    for(i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            total = total + list[i].salary;
        }
    }
    return total;
}

float averageSalary(Employee list[], int len)
{
    float total = totalSalaryEmployee(list, len);
    float promedio = 0;
    int cont = 0;
    int i;

    for(i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            cont++;
        }
    }

    promedio = total / cont;

    return promedio;
}

void exceedAverageSalary(Employee list[], int len, float average)
{
    int i;

    printf("\n%10s %20s %20s %10s %10s\n\n", "ID", "NAME", "LASTNAME", "SALARY", "SECTOR");

    for(i = 0; i < len; i++)
    {
        if(list[i].salary > average)
        {
            showAnEmployee(list[i]);
        }
    }
}

int validationLetter(char text[])
{
    int i ;
    for(i=0;text[i]!= '\0';i++)
    {
        if((text[i] <  'a' || text [i] > 'z') && (text[i] < 'A' || text[i] > 'Z'))
        {
            return 0;
        }
    }
    return 1;
}

int validationNumber(char num[])
{
    int i ;
    for(i=0; num[i]!= '\0'; i++)
    {
        if(num[i] <  '0' || num [i] > '9')
        {
            return 0;
        }
    }
    return 1;
}

int quantityExceedAverageSalary(Employee list[], int len, float average)
{
    int i;
    int cont = 0;

    for(i = 0; i < len; i++)
    {
        if(list[i].salary > average)
        {
            cont++;
        }
    }
    return cont;
}
