#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "conio.h"
#include "ctype.h"

/** \brief Menu options of employees array
*
* \param options in switch
* \return int - option
*
*/
int menu()
{
    int opcion;

    system("cls");
    printf("****** ABM Empleades *******\n\n");
    printf("1-Alta Empleade\n");
    printf("2-Baja Empleade\n");
    printf("3-Modificar Empleade \n");
    printf("4-Informes Empleades\n");
    printf("5-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param vec employee
 * \param tam int
 * \param id int
 * \return int Return todoOk if Ok
 */

int addEmployee(Employee vec[], int tam, int idEmployee)
{

    int todoOk = 0;
    int index;
    char name[51];
    char auxName[51];
    char lastName[51];
    char auxLastName[51];
    float salary;
    int sector;

    system("cls");

    printf("*****Alta Empleade*****\n\n");

    index = findFree(vec, tam); ///a ver si hay lugar libre, lo guarda en index 1 si hay, -1 sino

    if( index == -1)
    {
        printf("\nEl Sistema Esta Completo\n\n");
    }
    else
    {
        vec[index].id = idEmployee;
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(auxName);
        while (strlen (auxName) >50)///condicion de dato invalido, para que lo siga pidiendo
        {
            printf("Error Nombre muy largo, ingrese el nombre: ");
            fflush(stdin);
            gets(auxName);
        }
        strcpy (name, auxName); ///si el dato es valido, lo copio en nombre!



        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(auxLastName);
        while (strlen (auxLastName) >50)///condicion de dato invalido, para que lo siga pidiendo
        {
            printf("Error apellido muy largo, ingrese el Apellido: ");
            fflush(stdin);
            gets(auxLastName);
        }
        strcpy (lastName, auxLastName);
        printf("Ingrese salario: ");
        scanf("%f", &salary);

        printf("Ingrese sector, sectores de 1 al 5: ");
        fflush(stdin);
        scanf("%d", &sector);
        while (sector<0 || sector>5)
        {
            printf("Sector invalido, intentelo nuevamente: ");
            scanf("%d", &sector);
        }

        vec[index] = newEmployee(idEmployee, name, lastName, salary, sector);
        todoOk = 1;
        printf("\nSe ha realizado el alta del empleade\n\n");

    }
    return todoOk;
}

Employee newEmployee(

    int idEmployee,
    char name[],
    char lastName[],
    float salary,
    int sector)
{

    Employee al;
    al.id = idEmployee;
    strcpy( al.name, name);
    strcpy( al.lastName, lastName);
    al.sector = sector;
    al.salary = salary;
    al.isEmpty = 0;

    return al;
}

void showEmployee(Employee x)
{
    printf(" %d  %10s   %10s    %d    %3.2f \n",
           x.id,
           x.lastName,
           x.name,
           x.sector,
           x.salary);
}

/** \brief print the content of employees array
*
* \param vec Employee[]
* \param tam int
* \return array printed
*
*/
void printEmployees(Employee vec[], int tam)
{

    int flag = 0;
    system("cls");

    printf(" ID   APELLIDO    NOMBRE    SECTOR      SALARIO\n\n");

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            showEmployee(vec[i]);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay empleades que mostrar\n");
    }

    printf("\n\n");
}

/** \brief Sort the elements in the array of employees, the argument order
indicate  DOWN order
*
* \param vec Employee []
* \param tam int
* \return elements sorted in Down order
*
*/

void sortEmployeesByLastName(Employee vec[], int tam)
{
    Employee auxEmployeeSector;

    for(int i= 0; i < tam-1 ; i++)
    {
        for(int j= i+1; j <tam; j++)
        {
            if(strcmp(vec[i].lastName, vec[j].lastName)>0 || vec [i].sector > vec [j].sector)
            {
                auxEmployeeSector = vec[i];
                vec[i] = vec[j];
                vec[j] = auxEmployeeSector;
            }
        }
    }

}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param vec Employee[]
* \param tam int
* \return int Return todoOk is ok
*
*/
int removeEmployee(Employee vec[], int tam)
{
    int todoOk = 0;
    int id;
    int index;
    char confirma;
    system("cls");
    printf("***** Baja Empleade *****\n\n");
    printf("Ingrese id: ");
    scanf("%d", &id);

    index = findEmployee(id, vec, tam);

    if( index == -1)
    {
        printf("No existe un empleade con ese ID\n\n");

    }
    else
    {

        showEmployee(vec[index]);

        printf("\nConfirma baja?");
        fflush(stdin);
        scanf("%c", &confirma);

        if( confirma == 's')
        {
            vec[index].isEmpty = 1;
            todoOk = 1;
            printf("Baja de empleade exitosa!\n");
        }
        else
        {
            printf("\nNo se realizo la baja correspondiente ");
        }
    }

    return todoOk;
}
int modifyEmployee(Employee vec[], int tam)
{

    int todoOk = 0;
    int id;
    int index;
    system("cls");
    printf("\n***** Modificar Empleade *****\n\n");
    printf("Ingrese id del empleade: ");
    scanf("%d", &id);
    int opcion;

    index = findEmployee(id, vec, tam);

    if( index == -1)
    {
        printf("No existe un empleade con ese id\n\n");

    }
    else
    {
        printf(" ID     APELLIDO       NOMBRE  SECTOR  SALARIO\n\n");
        showEmployee(vec[index]);

        printf("\n\n***QUE DESEA MODIFICAR DEL EMPLEADE***\n\n");
        printf("1- Modificar nombre\n");
        printf("2- Modificar apellido\n");
        printf("3- Modificar salario\n");
        printf("4- Modificar sector\n");
        printf("5- Salir\n\n");
        printf("Ingrese opcion: \n");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            printf("Ingrese nombre nuevo: ");
            fflush(stdin);
            scanf("%s", vec[index].name);
            break;

        case 2:
            printf("Ingrese nuevo apellido : ");
            fflush(stdin);
            scanf("%s", vec[index].lastName);
            break;

        case 3:
            printf("Ingrese nuevo salario: ");
            scanf("%f", &vec[index].salary);
            break;

        case 4:
            printf("Ingrese nuevo sector: ");
            scanf("%d", &vec[index].sector);
            while (vec[index].sector<0 || vec[index].sector>5)
            {
                printf("Sector invalido, intentelo nuevamente: ");
                scanf("%d", &vec[index].sector);
            }

            break;

        case 5:
            printf("Se ha cancelado la modificacion ");
            break;

        }
    }
    return todoOk;
}

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in 1 in all
 * position of the array
 * \param vec[i] Employee
 * \param tam int Array length
 */
void initEmployee(Employee vec[], int tam)///inicia el array, pone todas las posicciones en 1. VACIO
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

/** \brief find an free index in the Employee Array, returns the index position in array.
 *
 * \param list Employee []
 * \param tam int
 * \return Return free index position
 *
 */

int findFree(Employee vec[], int tam)
{
    int index = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            index = i;
            break;
        }
    }
    return index;
}
/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param id int
 * \param list Employee []
 * \param tam int
 * \return Return employee index position
 *
 */

int findEmployee(int id, Employee vec[], int tam)
{
    int index = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].id == id && vec[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

/** \brief SubMenu options of reports employees array
*
* \param options in switch reports
* \return int - option
*
*/
int menuReports()
{
    int opcion;

    system("cls");
    printf("*** Menu de informes Empleades ***\n\n");
    printf("\n1-Empleades ordenados alfabeticamente por Apellido y Sector\n");
    printf("\n2-Total y promedio de los salarios, y cuantos empleades superan el salario promedio\n");
    printf("\n3-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
/** \brief valid an Employee is add in the index i position array.
 *
 * \param list Employee []
 * \param tam int
 * \return Return flag employee is added
 *
 */
int validsEmployees (Employee vec[], int tam)
{
    int flagCargado=0;

    for (int i=0; i<tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            flagCargado=1;
            break;
        }
    }

       if( flagCargado == 0)
        {
            printf("\n\n***DEBE CARGAR ALGUN EMPLEADE ANTES***\n\n");
            system("pause");

        }

    return flagCargado;
}
/** \brief reports based on salaries and averages.
 *
 * \param list Employee []
 * \param tam int
 * \return
 *
 */
void totalEmployees(Employee vec[], int tam)
{
    int contadorEmpleados = 0;
    int contadorSalarios = 0;
    float promedio;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].isEmpty == 0){

            contadorEmpleados ++;

        contadorSalarios += vec[i].salary;
        }
    }
    promedio = (float) contadorSalarios / contadorEmpleados;
        printf("\nTOTAL DE SALARIOS: %d\n\n", contadorSalarios);
        printf("EL PROMEDIO DE LOS SUELDOS ES : %.2f\n\n", promedio);

        for (int i=0; i<tam; i++)
        {
            if (vec[i].salary >= promedio)
            {
                printf("Empleades que superan el sueldo promedio: \n");
                showEmployee(vec[i]);
            }
        }

}

