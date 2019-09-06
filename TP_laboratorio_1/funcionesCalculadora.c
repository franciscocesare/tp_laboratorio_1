#include <stdio.h>
#include <stdlib.h>
#include "funcionesCalculadora.h"

/** \brief realiza la suma de dos enteros ingresados
 * \param primer entero ingresado por usuario
 * \param segundo entero ingresado por usuario
 * \return resultado de la operacion suma
 */

int add (int A, int B)
{
    int result;
    result=A+B;
    return result;
}
/** \brief realiza la resta de dos enteros ingresados
 * \param primer entero ingresado por usuario
 * \param segundo entero ingresado por usuario
 * \return resultado de la operacion resta
 */
int substract (int A, int B)
{
    int result;
    result=A-B;
    return result;
}
/** \brief realiza la multiplicacion de dos enteros ingresados
 * \param primer entero ingresado por usuario
 * \param segundo entero ingresado por usuario
 * \return resultado de la operacion multiplicacion
 */
int multiply(int A, int B)
{
    int result;
    result=A*B;
    return result;
}
/** \brief realiza la division entre dos enteros ingresados
 * \param primer entero ingresado por usuario
 * \param segundo entero ingresado por usuario
 * \return resultado de la operacion division, casteado por si resultado es con decimal
 */

float divide (int A, int B)
{
    float result;
    result = (float) A/B;
    return result;
}
/** \brief realiza el factorial de un numero ingresado
 * \param entero ingresado por usuario
 * \param var int "b" para calcular factorial
 * \param var int fact inicializada en 1
 * \return resultado factorial del numero, luego de un bucle For
 */
int factorial (int A)
{
    int b;
    int fact=1;
    for (b = A; b > 1; b--)
    {
        fact = fact * b;
    }
    return fact;
}
