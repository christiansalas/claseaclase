
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "clientes.h"
#include "ventas.h"
#define CANTIDAD_CLIENTES 100
#define CANTIDAD_VENTAS 1000




int main()
{
int opcion;
int flag = 0 ;
int i,auxiliarID,auxIdVenta;


Clientes arrayClientes[CANTIDAD_CLIENTES];
Ventas arrayVentas [CANTIDAD_VENTAS];




inicializarCliente(arrayClientes, CANTIDAD_CLIENTES);
inicializarVentas(arrayVentas,CANTIDAD_VENTAS);

do{
    menu(&opcion);
    switch (opcion)
        {
            case 1:
                if (altaCliente(arrayClientes,CANTIDAD_CLIENTES)== 0)
                    {
                        printf("\n Cliente cargado Exitosamente!\n");
                        flag = 1;
                            break;
                    }
                    break;

            case 2:
                 for (i=0;i<CANTIDAD_CLIENTES; i++)
                    {
                       if( arrayClientes[i].isEmpty == 1 )
                           {
                               flag =1;
                               break;
                           }
                    }
                        if(flag == 0)
                           {
                                printf("\n Error, no hay clientes cargados!!\n");
                                break;
                           }
                        fflush(stdin);

                        if ( flag == 1 && utn_getEntero(&auxiliarID, CANTIDAD_CLIENTES, "Ingrese id\n","No es un id valido \n", 3) == 0 &&
                                ModificarclientePorId( arrayClientes, CANTIDAD_CLIENTES, auxiliarID) == 0)
                            {
                                printf("Empleado Modificado\n");
                                flag = 0;
                                break;
                            }
                            break;
                case 3:

                 for (i=0;i<CANTIDAD_CLIENTES; i++)
                        {
                           if( arrayClientes[i].isEmpty == 1 )
                               {
                                   flag =1;
                                   break;
                               }
                        }
                        if(flag == 0)
                           {
                                printf("\n Error, no hay clientes cargados!!\n");
                                break;
                           }
                if( flag == 1 && utn_getEntero(&auxiliarID,CANTIDAD_CLIENTES,"\n Ingrese ID:\n","\n Error ingrese solo numeros \n",2)==0
                    && borrarCliente(arrayClientes,CANTIDAD_CLIENTES,auxiliarID)==0)
                            {

                                    printf("\n Cliente Borrado con exito!! \n");
                                    flag = 0;
                                      break;
                            }
                            break;

                case 4:
                for (i=0;i<CANTIDAD_CLIENTES; i++)
                        {
                           if( arrayClientes[i].isEmpty == 1 )
                               {
                                   flag =1;
                                   break;
                               }
                        }
                        if(flag == 0)
                           {
                                printf("\n Error, no hay clientes cargados!!\n");
                                break;
                           }
                        if  ( utn_getEntero(&auxiliarID,CANTIDAD_CLIENTES,"Ingrese id \n","Error, reingrese \n",2)==0 &&
                           arrayClientes[auxiliarID].isEmpty== 1 && altaVenta(arrayVentas,CANTIDAD_VENTAS,auxiliarID)==0)
                                {
                                    printf("la venta se ah completa con exito!!\n");
                                    break;
                                }
                            else
                                {
                                    printf("\n El id Ingresado no Existe!! \n");
                                }
                          break;

                case 5:

                 for (i=0;i<CANTIDAD_CLIENTES; i++)
                        {
                            if( arrayClientes[i].isEmpty == 1 )
                               {
                                   flag =1;
                                   break;
                               }
                        }
                        if(flag == 0)
                           {
                                printf("\n Error, no hay clientes cargados!!\n");
                                break;
                           }

                         imprimirVentas(arrayVentas,CANTIDAD_VENTAS);
                              if ( flag == 1 && utn_getEntero(&auxiliarID, CANTIDAD_CLIENTES, "Ingrese id\n","No es un id valido \n", 3) == 0 &&
                                ModificarVentasPorId(arrayVentas,CANTIDAD_VENTAS,auxiliarID) == 0)
                                    {
                                        printf("se modifico correctamente\n");
                                        flag = 0;
                                        break;
                                    }
                    break;

                case 6:

                 for (i=0;i<CANTIDAD_CLIENTES; i++)
                        {
                           if( arrayClientes[i].isEmpty == 1 )
                               {
                                   flag =1;
                                   break;
                               }
                        }
                        if(flag == 0)
                           {
                                printf("\n Error, no hay clientes cargados!!\n");
                                break;
                           }
                              imprimirVentas(arrayVentas,CANTIDAD_VENTAS);

                           if(utn_getEntero(&auxIdVenta,CANTIDAD_VENTAS,"\n Ingrese Id de VEnta \n","\nError Ingrese un Id Valido \n",2)== 0 &&

                                imprimirVentaDeCliente(arrayVentas,arrayClientes,CANTIDAD_VENTAS,CANTIDAD_CLIENTES,auxIdVenta)== 0)
                                    {
                                        printf("\n se Cambio el estado de la venta!!");
                                        break;
                                    }
                                break;

                case 7:
                    for (i=0;i<CANTIDAD_CLIENTES; i++)
                        {
                           if( arrayClientes[i].isEmpty == 1 )
                               {
                                   flag =1;
                                   break;
                               }
                        }
                        if(flag == 0)
                           {
                                printf("\n Error, no hay clientes cargados!!\n");
                                break;
                           }
                            ImprimirClientes(arrayClientes,CANTIDAD_CLIENTES,arrayVentas,CANTIDAD_VENTAS );
                    break;

                case 8:
                printf("\nCerrando...\n");
                break;
            }


}while(opcion!=12);





    return 0;
}
