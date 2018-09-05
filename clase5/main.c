#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define CANTIDAD 10
//son variables del sistema

int retornarTotal(int listado[],int tamanio);
int retornarPromedio(int listado[],int tamanio);
void cargarListado (int listado[],int tamanio);
void mostrarInformacionDelArray(listado,tamanio);

int main()

{
          int listadoDeNotas[CANTIDAD];


          cargarListado(listadoDeNotas,CANTIDAD);
          mostrarListado(listadoDeNotas,CANTIDAD);
          mostrarInformacionDelArray(listadoDeNotas,CANTIDAD);









          return 0;


}

int retornarTotal(int listado[],int tamanio)
{
int sumaNotas= 0;
int i;


             for (i=0;i<tamanio;i++)
             {
             sumaNotas=sumaNotas+listado[i];
             }
            return sumaNotas;


}
void cargarListado(int listado[],int tamanio)

{

int i;
int numeroIngresado;
 for (i=0;i<tamanio;i++)
            {
                printf("\n Ingrese nota  ");
             scanf("%d",&numeroIngresado);

             listado[i]=numeroIngresado;


            }

}

int retornarPromedio(int listado[],int tamanio)
{
int suma ;
int promedio;
suma = retornarTotal(listado,tamanio);
promedio = suma/promedio;
return promedio;


}

int retornarMenor(int listado[],int tamanio)
{

int i;
int menor;
             for (i=0;i<tamanio;i++)
             {
                if(i==0 || listado[i]< menor)
                 {
                 menor =listado[i];

                 }

             }
             return  menor;

}

int retornarMayor(int listado [],int tamanio)
{

int i;
int mayor;

             for (i=0;i<tamanio;i++)
             {
             if(i==0 || listado[i]>mayor)
             {
             mayor =listado[i];

             }
             }
             return mayor;



}
  void mostrarInformacionDelArray(int listado[],int tamanio)

  {
 int numeroMenor;
 int numeroMayor;
 int promedio;
int lista;
 int total;


 numeroMenor=retornarMenor(int listado[],int tamanio);
 numeroMayor=retornarMayor(int listado[],int tamanio);
 promedio=retornarPromedio(int listado[],int tamanio);
 lista =cargarListado(int listado[],int tamanio);
total = retornarTotal(int listado[],int tamanio);

  printf("el total es  : %d\n",numeroMenor);
  printf("el numero menor es  : %d\n",numeroMenor);
  printf("el promedio es : %d\n",promedio);
  printf("el listado es : %d\n",listado);
  printf("el listado es : %d\n",total);




  }

