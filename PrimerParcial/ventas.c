
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "clientes.h"
#include "ventas.h"
#include "informes.h"



/**
* \brief  inicializa el array de ventas poniendo en 0 todo los campos.

*/
int inicializarVentas(Ventas* pBuffer,int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        pBuffer[i].isEmptyVentas= 0;
    }
    return 0;
}

/**
* \brief    se da de alta una venta
* \param list Es la cadena que evaluamos
* \param len Es el tamano maximo del string
* \return En caso de exito retorna 0, si no -1
*/


int altaVenta(Ventas* list, int len, int id)
{
int i;
int retorno =-1;
int auxAfiches;
char auxNombreAfiche[50];
char auxZonaPegarAfiche[50];


  if(list != NULL && len > 0 )
            {
                for(i=0;i<len;i++)
                {
                            if(list[i].isEmptyVentas== 0
                                 &&
                                 utn_getEntero(&auxAfiches,50,"\n Ingrese cantidad de afiches \n","\n Error, ingrese una cantidad valida\n", 2)==0
                                 &&
                                 utn_getNombre(auxNombreAfiche,50,"\n Ingrese Nombre del afiche \n","\n Error,datos Invalidos\n", 2)==0
                                 &&
                                 utn_getNombre(auxZonaPegarAfiche,50,"\n Ingrese zona donde pegar el afiche \nCABA\nZona SUr \nZona Oeste \n", "\n Error, ingrese una zona valida", 2)==0
                               )
                                    {
                                        list[i].IdVentas = getNextId();
                                        list[i].afiches = auxAfiches;
                                        strncpy(list[i].nombreAfiche, auxNombreAfiche, 50);
                                        strncpy(list[i]. zonaPegarAfiche, auxZonaPegarAfiche, 50);
                                        list[i].isEmptyVentas =  1;
                                        strncpy(list[i].estadoVenta,"a cobrar", 50);
                                        list[i].IdCliente= id;
                                        retorno = 0;
                                        break;

                                     }
                }

            }
          /*  printf("Id de ventas :%d\n",list[i].IdVentas);
            printf("Cantidad de afiches : %d \n",list[i].afiches);
            printf("estado venta :%s\n",list[i].estadoVenta);
            printf("NOmbre afiche: %s\n",list[i].nombreAfiche);
            printf("ZOna afiche: %s\n",list[i].zonaPegarAfiche);*/





return retorno;
}

/**
* \brief    Toma la cadena y evalua si es un entero en caso de exito lo transforma a entero
* \param pEntero Recibe el numero ingresado en caso de exito
* \param limite Es el tamano maximo de cifras
* \param mensaje Es el mensaje que se muestra al usuario antes de introducir datos
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param reintentos Veces que el usuario podra volver a introducir el dato
* \return En caso de exito retorna 0, si no -1
*/



int utn_getEntero(  int *pEntero, int limite, char *mensaje,
                    char *mensajeError, int reintentos)

{


    int retorno=-1;
    char bufferEntero[4096];
    if( pEntero != NULL && limite > 0 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( getString(bufferEntero, limite) == 0 &&
                isValidEntero(bufferEntero, limite))
            {
                *pEntero = atoi(bufferEntero);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }while(reintentos>=0);
    }
    return retorno;
}

/**
* \brief    imprime los datos de las ventas
* \param list  es el array a reccorrer
* \param limite Es el tamano maximo del array
*/

void imprimirVentas(Ventas * list,int limite)
{
    int i;

    if (list != NULL && limite >0  )
    {
        for (i = 0; i< limite; i++)
        {
            if (list[i].isEmptyVentas == 1)
            {
            printf("Id de ventas :%d\n",list[i].IdVentas);
            printf("Cantidad de afiches : %d \n",list[i].afiches);
            printf("estado venta :%s\n",list[i].estadoVenta);
            printf("NOmbre afiche: %s\n",list[i].nombreAfiche);
            printf("ZOna afiche: %s\n",list[i].zonaPegarAfiche);
            printf("\n-----------------------------\n");

            }
        }
    }
}

/**
* \brief    modifica los datos de las  ventas
* \param list  es el array a reccorrer
* \param limite Es el tamano maximo del array
* \param id es el id ingresado
* \return En caso de exito retorna 0, si no -1
*/

int ModificarVentasPorId(Ventas* list, int len,int id )
{
    int retorno = -1;
    int opcion;
char auxNombreAfiche[50];
char auxZonaPegarAfiche[50];


    if(list != NULL && len > 0 && id >= 0 && id < len )
    {
        if (list[id].isEmptyVentas == 1)
        {
            printf("\n Desea modificar : \n 1-Nombre del Afiche: \n 2-Zona de Pegado Afiche:  \n 3-Salir:  \n");
            scanf("%d",&opcion);
            switch(opcion)
            {
                case 1:
                    fflush(stdin);
                if (utn_getNombre(auxNombreAfiche, 50, "\n Ingrese nombre del afiche :\n", "Nombre Invalido! \n", 2)==0)
                {
                    strncpy(list[id].nombreAfiche, auxNombreAfiche, 50);
                    printf("\n Se ha modificado el nombre del afiche con exito!!\n");
                    break;
                }
                case 2:
                                        fflush(stdin);
                if (utn_getNombre( auxZonaPegarAfiche,50, "\n Ingrese Zona Pegado Afiche: \n","\n Zona  invalida!\n", 2) == 0)
                {
                    strncpy(list[id].zonaPegarAfiche, auxZonaPegarAfiche, 50);
                    printf("Apellido modicado\n");
                            break;
                }
                case 3:
                fflush(stdin);
                   printf("\n Saliendo!! \n");
                   break;
                default :
                printf("Opcion no valida\n");
            }
            retorno = 0;
        }else
        {
            printf("\nEl id ingresado es inexistente!!\n");
        }
            }
return retorno;
}

int  imprimirVentaDeCliente(Ventas *list,Clientes *listcliente, int lenventa ,int lenclientes,int id)
{
int retorno = -1;
int i,j,opcion;
int auxID;

    if(list != NULL && listcliente != NULL && lenventa >0 && id < lenventa && lenclientes >0 )
    {

            for(i=0;i<lenventa;i++)
            {
                 if(list[i].IdVentas== id)
                    //&& list[id].IdCliente== id)
                        {

                        auxID=list[i].IdVentas;
                        break;
                        }
            }
                             for(j=0;j<lenclientes;j++)
                                    {
                                    if(listcliente[j].idClientes == auxID)
                                        {
                                        printf("\n Nombre : %s\n",listcliente[id].nombre)  ;
                                        printf("\n Apellido : %s\n",listcliente[id].apellido)  ;
                                        printf("\n cuit : %s",listcliente[id].cuit)  ;
                                           break;
                                        }
                                    }



                printf("\n Desea Cambiar el estado de la venta?? \n 1- Si \n 2-NO \n");
                scanf("%d",&opcion);

                if(opcion == 1)
                    {
                       strncpy(list[i].estadoVenta, "Cobrada",50) ;
                       printf("\nSe modifico el estado de la venta!!\n");
                       retorno = 0;
                    }else
                    {
                    printf("\n NO se modificara ningun dato!! \n");
                    }

                retorno = 0;
        }

return  retorno;
}


 int ImprimirClientes(Clientes *listClientes,int limiteClientes,Ventas * listVentas,int limiteVentas )
 {
     int retorno = 0;
     int i,j;
     int contadorEstados =0;
     for (i=0;i< limiteClientes;i++)
     {
            if( listClientes[i].isEmpty == 1)
            {
                printf("\n ID : %d \n",listClientes[i].idClientes);
                printf("\n Nombre : %s \n",listClientes[i].nombre);
                printf("\n apellido : %s \n",listClientes[i].apellido);
                printf("\n Cuit : %s \n",listClientes[i].cuit);
                retorno =0;
                break;

            }
        }

         for(j=0;j<limiteVentas;j++)
         {
            if(listVentas[j].isEmptyVentas == 1 && listVentas[j].IdCliente == listClientes[i].idClientes && strcmp(listVentas[j].estadoVenta,"a cobrar")== 0)
            {

                contadorEstados ++;
                retorno=0;

            }
         }
         printf("\nLa cantidad de ventas a cobrar son : %d\n",contadorEstados);
         printf("\n---------------------\n");


return retorno;

 }
 /**
* \brief    Se utiliza esta funcion para obtener un nuevo id
*           declarando una variable static para el id y suma 1 al anterior
* \return devuelve un id nuevo
*/
static int getNextId()
{
    static int ultimoId=-1;
    ultimoId++;
    return ultimoId;
}


/*int ventas_ingresoForzado(Ventas* pBuffer,int limite,int afiches,char* nombreAfiche,char* zonaPegarAfiche,char* estadoVenta)
{
    int aux;
    ventas_buscarIndiceVacio(pBuffer,limite,&aux);
    strcpy(pBuffer[aux].nombreAfiche,nombreAfiche);
    strcpy(pBuffer[aux].zonaPegarAfiche,zonaPegarAfiche);
    pBuffer[aux].afiches=afiches;
    pBuffer[aux].IdCliente=IdCliente;
    pBuffer[aux].isEmptyVentas=1;
    pBuffer[aux].IdVentas=ventas_obtenerID();
    return 0;
}

static int ventas_buscarIndiceVacio(Ventas* pBuffer,int limite,int*indice)
{
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++){
        if(pBuffer[i].isEmptyVentas==1)
        {
            *indice=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}


int ventas_obtenerID()
{
    static int ID=0;
    return ID++;
}*/




