

#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;



#endif // ARRAYEMPLOYEES_H_INCLUDED

void initEmployee(Employee vec[], int tam);
int findFree(Employee vec[], int tam);
int addEmployee(Employee vec[], int tam,int idEmployee);
Employee newEmployee(int id, char name[],char lastName[], float salary, int sector);
void showEmployee(Employee x);
void printEmployees(Employee vec[], int tam);
int findEmployee(int id, Employee vec[], int tam);
int modifyEmployee(Employee vec[], int tam);
void sortEmployeesByLastName(Employee vec[], int tam);
int removeEmployee(Employee vec[], int tam);
int validsEmployees (Employee vec[], int tam);
int menu();
int menuReports();
void totalEmployees(Employee vec[], int len);
