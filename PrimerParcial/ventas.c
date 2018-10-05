
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "clientes.h"
#include "ventas.h"


/**
* \brief    Evalua si es un nombre valido
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 1, si no 0
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
* \brief    Evalua si es un nombre valido
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 1, si no 0
*/


int altaVenta(Ventas* list, int len)
{
int i;
int retorno =-1;
char auxAfiches[50];
char auxNombreAfiche[50];
char auxZonaPegarAfiche[50];
char AuxIdCliente[50];


  if(list != NULL && len > 0 )
            {
                for(i=0;i<len;i++)
                {

                            if(list[i].isEmptyVentas== 0
                             &&
                             utn_getEntero(auxAfiches,50,"\n Ingrese cantidad de afiches \n","\n Error, ingrese una cantidad valida\n", 2)==0
                             &&
                             utn_getNombre(auxNombreAfiche,50,"\n Ingrese Nombre del afiche \n","\n Error,datos Invalidos\n", 2)==0
                             &&
                             utn_getNombre(auxZonaPegarAfiche,50,"\n Ingrese zona donde pegar el afiche \nCABA\nZona SUr \nZona Oeste \n", "\n Error, ingrese una zona valida", 2)==0
                             )
                            {
                                list[i].IdVentas = i;
                                strncpy(list[i].afiches, auxAfiches, 50);
                                strncpy(list[i].nombreAfiche, auxNombreAfiche, 50);
                                strncpy(list[i]. zonaPegarAfiche, auxZonaPegarAfiche, 50);
                                list[i].isEmptyVentas =  1;
                                retorno = 0;





                             }
                }
            }
return retorno;
}




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


int imprimirVentas(Ventas* pBuffer,int limite)
{
    int i;
    int auxIdVenta;

    if (pBuffer != NULL && limite >0  )
    {
        for (i = 0; i< limite; i++)
        {
            if (pBuffer[i].isEmptyVentas == 0)
            {
                printf("ID %d\n", pBuffer[i].iD);
                printf("Afiches %s\n", pBuffer[i].afiches);
                printf("Cuit %s\n", pBuffer[i].nombreAfiche);
                printf("Zona pegar Afiches  %d\n", pBuffer[i].zonaPegarAfiche);
                printf("ID cliente %d\n", pBuffer[i].IdVentas);
                printf("---------------------------------\n");
            }
        }
    }
    return 0;
}


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
            printf("\n Desea modificar : \n 1-Nombre del Afiche: \n 2-Zona de Pegado Afiche:  4 Salir:  \n");
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
                if (utn_getNombre( auxZonaPegarAfiche,50, "\n Ingrese Zona Pegado Afiche: \n","\Zona  invalida!\n", 2) == 0)
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
