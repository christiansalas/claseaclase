#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

/*
1)  Definir un tipo de dato que represente un producto.
    El producto tiene un nombre, una descripcion y un precio

2)  Definir un array de 200 productos, indicar de alguna manera
    que la info de cada item no esta cargada.

3)  Realizar una funcion que reciba el array, un indice, y le
    permita al usuario cargar los datos en el item de la posicion especificada por el indice.

4)  Realizar una funcion que reciba el array y un indice e imprima
    los datos del item de la posicion especificada por el indice.

5)  Realizar una funcion que me devuelva el indice de un item vacio (sin cargar).


3) Realizar un programa con un menu de dos opciones:
    a) Cargar un producto
    b) Imprimir lista productos


4)  Agregar al tipo de dato el campo ID que represente un identificador unico.
    Modificar el codigo anterior para que el ID se genere automaticamente. Se debera cargar el ID automaticamente al cargar un producto, y se debera imprimir al imprimir la lista.

5)  Realizar una funcion que reciba el array y un ID, y me devuelva el indice
    del item con dicho ID.

6)  Realizar una funcion que reciba el array, un indice, y le permita al usuario
    modificar los campos nombre y precio del item del array en la posicion especificada por el indice.


7)  Agregar una opcion en el menu. "Editar producto" que pida al usuario el ID del
    mismo y le permita cambiar el nombre y el precio.

8)  Agregar una opcion en el menu "Borrar producto" que pida al usuario el ID del
    mismo.

*/
int main()
{

int opcion =-1;
char seguir = 'S';
int espacioLibre;
int iD;


    eProducto producto[200];
    producto_init(producto,200,1);
    //producto_alta(producto,200,0);
   // producto_imprimir(producto,200);

    //printf("Posicion libre: %i",producto_indiceLibre(producto,200));

do{
  // printf("\n");
    printf("\n 1- ALta\n 2- Imprimir \n 3- Buscar Por Id \n Opcion\n");
    scanf("%d",&opcion);

            switch(opcion)
            {

                    case 1 :
                    system("clear");
                    espacioLibre =producto_indiceLibre(producto,200);
                    producto_alta(producto,200,espacioLibre);
                    break;

                    case 2 :
                    system("clear");
                    producto_imprimir(producto,200);
                    break;

                    case 3:
                    printf ("\nIngrese un id \n");
                    scanf("%d",&id);

            producto_indiceId(producto, 200 , iD);


                    default:
                    seguir = 'n';
                    break;
            }

            }while (seguir =='S');*/




}






