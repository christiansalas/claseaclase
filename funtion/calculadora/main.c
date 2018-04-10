#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int RtaScanf;
    int a,b,z;
    char primero[30];
    char segundo[30];
    int flag1=0;
    int flag2=0;


    strcpy(primero, "1- Ingresar 1er operando (A=");
    strcpy(segundo, "2- Ingresar 2do operando (B=");

    while(seguir == 's')
    {
        //printf("inicia otra vuelta");
        //strcpy(aux,primero);
        if (flag1 != 1){
            //strcat(aux,"x)");
            printf("%sx)\n", primero);
        }
        else{
            //printf("paso por aca");
            //strcat(aux,"puto");
            //strcat(aux,")");
            printf("%s%d)\n", primero,a);
            //printf("salio de aca");
        }



        //strcpy(aux,segundo);
        if (flag2 != 1){
            //strcat(aux,"x)");
            printf("%sx)\n", segundo);
        }
        else{
            //strcat(aux,(char *)b);
            //strcat(aux,")");
            printf("%s%d)\n", segundo,b);
        }


        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                    printf("Ingrese el primer numero : ");
                    RtaScanf = scanf("%d", &a);
                    if (RtaScanf != 1){
                        printf("Error. El número ingresado no es válido.\n");
                    }
                    else{
                        flag1=1;
                    }
                    //printf("cargo el primer numero");
                    break;
            case 2:
                    printf("Ingrese el segundo numero : ");
                    RtaScanf = scanf("%d",&b);
                    if (RtaScanf != 1){
                        printf("Error. El número ingresado no es válido.\n");
                    }
                    else{
                        flag2=1;
                    }
                break;



            case 3:
                    if (flag1 != 1 || flag2 != 1){
                        printf("Error. Falta ingresar algun operando.\n");
                    }
                    else{
                        z = suma(a,b);
                        printf("el resultado es %d\n",z);
                    }

                break;
            case 4:
                     z = resta(a,b);
                    printf("El resultado es : %d\n",z);

                break;
            case 5:
                if (b==0)
                {
                    printf("Error. no se puede dividir por 0\n");
                }
                else{
                    z = division(a,b);
                    printf("La division es : %d\n", z);
                }
                break;
            case 6:

                    z = producto(a,b);
                    printf("El producto es : %d\n",z);
                    break;
            case 7:

                if (flag1 != 1)
                {
                    printf("Error, debe ingresar el primer operando \n");
                }else
                {
                    if (a > 0){
                    z = factorial(a);
                    printf("El factorial es : %d\n",z);
                    }else
                    {
                        printf("Error, no es posible calcular el factorial de un numero menor o igual que 0 \n");
                    }
                }
                break;
            case 8:
                if (flag1 != 1 || flag2 != 1)
                {
                    printf("Error, Falta ingresar algun operando");
                }else
                {
                    calcularTodo(a,b);
                }

                break;
            case 9:
                seguir = 'n';
                break;
            default:
                printf("Opcion no valida\n");

        }

//printf("otra vuelta");

    }
return 0;
}
