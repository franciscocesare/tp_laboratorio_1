#include <stdio.h>
#include <stdlib.h>
#include "funcionesCalculadora.h"

int main()
{
    int opcion;
    int x=0;
    int y=0;
    int resultadoSuma;
    int resultadoResta;
    int resultadoMultiplicacion;
    float resultadoDivision;
    int resultadoFactorialA;
    int resultadoFactorialB;
    int flag1=0;
    int flag2=0;
    int flag3=0;


    printf("\n\n<<<BIENVENIDO A LA FUNCION CALCULADORA>>> \n\n");

    do
    {
        printf("\n\n");
        printf("1-Ingrese el primer operando A \n");
        printf("2-Ingrese el segundo operando B \n");
        printf("3-Calcular todas las operaciones \n");
        printf("4-Informar resultados \n");
        printf("5-salir \n\n");
        printf("El valor del operando A ingresado es= %d\n", x );
        printf("El valor del operando B ingresado es= %d\n", y);
        printf("\n ingrese opcion <1-5> \n\n");
        scanf ("%d", &opcion);

        system("cls"); //ultilizado para limpiar pantalla luego de seleccion, realizado en Win10

        if (opcion>5 || opcion == 0)
        {
            printf("\n\n ***ERROR! DEBE INGRESAR UNA OPCION VALIDA DEL MENU*** \n\n \t ***INTENTELO NUEVAMENTE ***\n\n");
            system("pause");
            system("cls");
        }

        switch (opcion)
        {
        case 1:
            printf ("\n ingrese el primer operando A=" );
            scanf("%d", &x);
            flag1=1;
            system("cls");
            break;
        case 2:
            printf("\n ingrese el segundo operando B=");
            scanf ("%d", &y);
            flag2=1;
            system("cls");
            break;
        case 3:
            if (flag1==0 || flag2==0)
            {
                printf("\n ***ERROR. PRIMERO DEBE INGRESAR OPERANDOS DE LA OPCION 1 Y 2.*** \n\n");
            }
            else
            {
                flag3=1;
                resultadoSuma=add(x,y);
                resultadoResta=substract(x,y);

                if (y!=0)
                {
                    resultadoDivision = divide(x,y);
                }
                resultadoMultiplicacion = multiply(x,y);
                resultadoFactorialA=factorial(x);
                resultadoFactorialB=factorial(y);

                system("cls");
                printf("\n\n<<< OPERACIONES REALIZADAS, OPCION 4 PARA VER LOS RESULTADOS >>> \n\n");
            }

            break;

        case 4:

            if (flag3==0)
            {
                system("cls");
                printf("\n ***ERROR. PRIMERO SE DEBEN REALIZAR LAS OPERACIONES DE LA OPCION 3.***\n\n");
            }
            else
            {
                printf ("***LOS RESULTADOS DE LAS OPERACIONES SON: ***\n\n");
                printf ("El resultado de La suma de %d + %d es :%d \n",x,y, resultadoSuma);
                printf ("El resultado de La resta de %d - %d es :%d \n",x,y,resultadoResta);
                if (y!=0)
                {
                    printf ("El resultado de la division de %d / %d es: %.2f \n",x,y, resultadoDivision);
                }
                else
                {
                    printf("ERROR, No se puede dividir por 0 \n");
                }


                printf ("El resultado de la multiplicacion de %d * %d es :%d \n",x,y,resultadoMultiplicacion);
                printf ("El factorial de %d es : %d \n", x, resultadoFactorialA);
                printf ("El factorial de %d es : %d \n\n", y, resultadoFactorialB);
                system("pause");
                system ("cls");

            }
            break;

        case 5:
            printf(">>>GRACIAS POR UTILIZAR LA FUNCION CALCULADORA<<<\n \n \n");
            break;
        }

    }
    while (opcion != 5);



    return 0;
}
