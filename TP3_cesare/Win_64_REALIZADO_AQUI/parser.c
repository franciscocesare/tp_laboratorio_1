#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee){
    char aux_id[10];
    char aux_nombre[128];
    char aux_horasTrabajadas[10];
    char aux_sueldo[10];

    int charge;

    do{
        charge=fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", aux_id, aux_nombre, aux_horasTrabajadas, aux_sueldo);
        if(charge!=4){
            printf("Error");
        }else{
            Employee* pEmpleado=employee_new();

            pEmpleado->id=atoi(aux_id);
            strcpy(pEmpleado->nombre,aux_nombre);
            pEmpleado->horasTrabajadas=atoi(aux_horasTrabajadas);
            pEmpleado->sueldo=atoi(aux_sueldo);
            ll_add(pArrayListEmployee, pEmpleado);
        }
    }while(!feof(pFile));
    fclose(pFile);

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
     char aux_id[10];
    char aux_nombre[128];
    char aux_horasTrabajadas[10];
    char aux_sueldo[10];

    int charge;

    do{
        charge=fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", aux_id, aux_nombre, aux_horasTrabajadas, aux_sueldo);
        if(charge!=4){
            printf("Error");
        }else{
            Employee* pEmpleado=employee_new();

            pEmpleado->id=atoi(aux_id);
            strcpy(pEmpleado->nombre,aux_nombre);
            pEmpleado->horasTrabajadas=atoi(aux_horasTrabajadas);
            pEmpleado->sueldo=atoi(aux_sueldo);
            ll_add(pArrayListEmployee, pEmpleado);
        }
    }while(!feof(pFile));
    fclose(pFile);


    return 1;
}
