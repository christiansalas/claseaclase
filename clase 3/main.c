#include <stdio.h>
#include <stdlib.h>


//tac es el espacio de memoria donde se almacenan las variables de las funciones.

/*
int edad;
int* pEdad;apunta
edad = 5;
pedad = &edad;   el ampersand da la direcciond memoria
*pEdad = 8; modifico el valor de la edad una vez que obtengo la direccion de edad ;
printf ("%d", edad );
printf ("%d",*pEdad);*/

 //fabricar validad la edad reciber dos paremetros y devuelve v y f y la utilizamos entreo ede la primera


int PedirEdad();
int validarEdad(int edad, int minimo ,  int maximo );




int main()
{
    int edad ;
    int esValidaLaEdad;

    edad= PedirEdad();




    printf("la edad ingresada des  %d",edad);

    return 0;
}


  int PedirEdad()

   {
    int edad;
    printf("Ingrese su edad : ");
    scanf("%d",&edad);

    edad= validarEdad(edad,1 ,100);
    return edad;

    }




    int validarEdad(int edad, int minimo, int maximo)

    {
    int contadorIntentos= 0;

    while(edad < minimo || edad > maximo  )
     {
     printf("Error,la edad ingresada no es valida!!, Ingrese nuevamente  d/");
     scanf("%d",&edad);

     }
        return   edad;
    }













