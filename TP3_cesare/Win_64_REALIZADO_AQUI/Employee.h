#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/*
Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
void employee_delete();

int employee_setId(Employee* thisIs,int id);/// tip: hacer un setId que soporte un char (para todos las funcines que reciben int y float)
int employee_getId(Employee* thisIs,int* id);

int employee_setNombre(Employee* thisIs,char* nombre);
int employee_getNombre(Employee* thisIs,char* nombre);

int employee_setHorasTrabajadas(Employee* thisIs,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* thisIs,int* horasTrabajadas);

int employee_setSueldo(Employee* thisIs,int sueldo);
int employee_getSueldo(Employee* thisIs,int* sueldo);

int employee_sort(void* pEmployee1, void* pEmployee2); /// para decirle a ll_sort cuándo hacer el swap
                /// paso los pEmployee como void porque ll_sort recibe void
*/
#endif // employee_H_INCLUDED
Employee* employee_new(); /// malloc: construimos espacio para el sizeof de ese empleado
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);
int employee_delete();

int employee_setId(Employee* this, char* value); /// tip: hacer un setId que soporte un char (para todos las funcines que reciben int y float)
int employee_getId(Employee* this, int* value);

int employee_setNombre(Employee* this, char* value);
int employee_getNombre(Employee* this, char* value);

int employee_setHorasTrabajadas(Employee* this, char* value);
int employee_getHorasTrabajadas(Employee* this, char* value);

int employee_setSueldo(Employee* this, char* value);
int employee_getSueldo(Employee* this, int* value);

int employee_sort(void* pEmployee1, void* pEmployee2); /// para decirle a ll_sort cuándo hacer el swap
                /// paso los pEmployee como void porque ll_sort recibe void
