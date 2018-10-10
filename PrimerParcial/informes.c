
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "clientes.h"
#include "ventas.h"
#include "informes.h"



int informar_mostrarVentaPorEstado(Ventas *listVentas, int len)
{

    int retorno = -1;
    int i;
    int acumuladorCABA = 0;
    int acumuladorZonaSur = 0;
    int acumuladorZonaNorte = 0;
    if(listVentas!= NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(listVentas[i].isEmptyVentas== 1 && strcmp(listVentas[i].zonaPegarAfiche,"CABA"== 0))
                {
                acumuladorCABA++;
                retorno= 0;

                }
            if(listVentas[i].isEmptyVentas== 1 && strcmp(listVentas[i].zonaPegarAfiche,"ZonaNorte"== 0))

                {
                acumuladorZonaNorte++ ;
                retorno = 0;
                }
            if(listVentas[i].isEmptyVentas== 1 && strcmp(listVentas[i].zonaPegarAfiche,"ZonaSur"== 0))
                    {
                    acumuladorZonaSur++;
                    retorno = 0;

                    }
                    break;

        }

    }
            if (acumuladorCABA>acumuladorZonaSur && acumuladorZonaSur <acumuladorZonaNorte)
                    {
                    printf("\n La zona con menos ventas es : ZonaSur");

                    }
            if(acumuladorCABA<acumuladorZonaSur && acumuladorCABA <acumuladorZonaNorte)
                    {

                               printf("\n La zona con menos ventas es : CABA");
                    }
            if(acumuladorZonaNorte<acumuladorZonaSur && acumuladorCABA >acumuladorZonaNorte)
                    {

                    printf("\n La zona con menos ventas es : CABA");

                    }





    return retorno;
}


int Informar_VentasOrdenadasPorZona(Ventas *listventas, int len , int zona)
{

int i;
int retorno = -1;

if(listventas != NULL &&  len > 0)
{

        for (i=0;i<len;i++)
                {
                if(listventas[i].isEmptyVentas == 1 && strcmp(listventas[i].zonaPegarAfiche ,zona)==0)
                {
                    printf("\nIdcliente: %d \nAfiches: %d \nImagen: %s\nIDVenta: %d\n",
                    listventas[i].IdCliente, listventas[i].afiches, listventas[i].nombreAfiche,listventas[i].IdVentas);

                    if(strcmp(listventas[i].zonaPegarAfiche,"CABA")==0 )
                        {
                            printf("Zona: CABA\n");
                        }
                     if(strcmp(listventas[i].zonaPegarAfiche,"ZonaSur")==0 )
                        {
                            printf("Zona: Zona Sur\n");
                        }
                    if(strcmp(listventas[i].zonaPegarAfiche,"ZonaOeste")==0 )
                        {
                            printf("Zona: Zona Oeste\n");
                        }

                }
                        retorno = 0;
                }
            return retorno;

}




}

/*int Informar_clientesConMasVentas(Clientes *listClientes,int limiteClientes,Ventas * listVentas,int limiteVentas )
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


return retorno;

 }*/
 void array_swap (int* elementoA, int* elementoB)
{
    int auxiliar;
    auxiliar = *elementoA;
    *elementoA = *elementoB;
    *elementoB = auxiliar;
}


