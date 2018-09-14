#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define bufferString 4096
#include <ctype.h>



#define CANTIDAD_EMPLEADOS 6


struct sEmpleados
{
char nombre[50];
char apellido[50];
float salario[50];



};


typedef struct sEmpleados Empleado;




int main()
{
    char nombres[CANTIDAD_EMPLEADOS][50]={"AAA","CCC","BBB"};
    char apellidos[CANTIDAD_EMPLEADOS][50]={"AAA","CCC","BBB"};
    char dni [CANTIDAD_EMPLEADOS][50]={"AAA","CCC","BBB"};
    int i;

    for(i=0;i < CANTIDAD_EMPLEADOS;i++)
    {
        utn_getNombre(nombres[i],50,"\nNombre","\nError",2);


    }
     for(i=0;i < CANTIDAD_EMPLEADOS;i++)
    {
        printf("%s \n",nombres[i]);

    }

    return 0;
}






