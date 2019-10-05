#include"ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "conio.h"
#include "ctype.h"

#define TAM 1000


int main()
{
    Employee lista[TAM];
    char salir = 'n';
    int idEmployee=1;

    initEmployee(lista, TAM);


    do
    {
        switch( menu())
        {
        case 1:
            if (addEmployee(lista, TAM, idEmployee))
            {
                idEmployee ++;
            }

            break;

        case 2:
            if ( validsEmployees (lista, TAM)==1)
            {
                removeEmployee(lista, TAM);
            }
            break;

        case 3:
            if ( validsEmployees (lista, TAM)==1)
            {
                modifyEmployee(lista, TAM);
            }
            break;

        case 4:
            if ( validsEmployees(lista, TAM))

            {
                switch (menuReports())
                {
                case 1:
                    printf("empleados ordenados alfabeticamente por Apellido y Sector\n\n");
                    sortEmployeesByLastName(lista, TAM);
                    printEmployees(lista, TAM);
                    break;

                case 2:
                    totalEmployees(lista, TAM);
                    break;
                }

            }
            break;

        case 5:
            printf("Confirma salir del ABM emplades?:");
            fflush(stdin);
            salir = getche();
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(tolower(salir == 'n'));

    return 0;
}


