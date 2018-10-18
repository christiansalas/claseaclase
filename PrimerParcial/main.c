
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "clientes.h"
#include "ventas.h"
#define CANTIDAD_CLIENTES 100
#define CANTIDAD_VENTAS 1000
#include "informes.h"



int main()
{
int opcion;

int auxiliarID,auxIdVenta;


Clientes arrayClientes[CANTIDAD_CLIENTES];
Ventas arrayVentas [CANTIDAD_VENTAS];

inicializarCliente(arrayClientes, CANTIDAD_CLIENTES);
inicializarVentas(arrayVentas,CANTIDAD_VENTAS);

clientes_ingresoForzado(arrayClientes,CANTIDAD_CLIENTES,"cristian","salas","20-32111568-4");
clientes_ingresoForzado(arrayClientes,CANTIDAD_CLIENTES,"Lucas","Hourcade","20-29556888-4");
clientes_ingresoForzado(arrayClientes,CANTIDAD_CLIENTES,"Carolina","Hourcade","20-31477895-4");

ventas_ingresoForzado(arrayVentas, CANTIDAD_VENTAS, 0, 40, "imagen.jpg1", "ZONA_OESTE","Cobrada");
ventas_ingresoForzado(arrayVentas, CANTIDAD_VENTAS, 0, 500, "imagen.jpg2", "CABA","A_COBRAR");
ventas_ingresoForzado(arrayVentas, CANTIDAD_VENTAS, 0, 400, "imagen.jpg3", "ZONA_SUR","A_COBRAR");

ventas_ingresoForzado(arrayVentas, CANTIDAD_VENTAS, 1, 80, "imagen.jpg4", "ZONA_OESTE","Cobrada");
ventas_ingresoForzado(arrayVentas, CANTIDAD_VENTAS, 1, 40, "imagen.jpg5", "ZONA_OESTE","Cobrada");
ventas_ingresoForzado(arrayVentas, CANTIDAD_VENTAS, 1, 40, "imagen.jpg6", "ZONA_OESTE","A_COBRAR");

ventas_ingresoForzado(arrayVentas, CANTIDAD_VENTAS, 2, 100, "imagen.jpg7", "ZONA_SUR","Cobrada");
ventas_ingresoForzado(arrayVentas, CANTIDAD_VENTAS, 2, 50, "imagen.jpg8", "ZONA_OESTE","A_COBRAR");
ventas_ingresoForzado(arrayVentas, CANTIDAD_VENTAS, 2, 500, "imagen.jpg9", "CABA","A_COBRAR");






                do
                    {
                        menu(&opcion);
                            switch (opcion)
                                {
                                    case 1:
                                        if (altaCliente(arrayClientes,CANTIDAD_CLIENTES)== 0)
                                        {
                                            printf("\n Cliente cargado Exitosamente!\n");
                                        }
                                        break;

                                    case 2:
                                           fflush(stdin);

                                        if ( ComprobarClienteCargado(arrayClientes,CANTIDAD_CLIENTES)== 1&& utn_getEntero(&auxiliarID, CANTIDAD_CLIENTES, "Ingrese id\n","No es un id valido \n", 3) == 0 &&
                                            ModificarclientePorId( arrayClientes, CANTIDAD_CLIENTES, auxiliarID) == 0)
                                            {
                                                printf("Empleado Modificado\n");
                                                break;
                                            }
                                            break;
                                    case 3:


                                            if( ComprobarClienteCargado(arrayClientes,CANTIDAD_CLIENTES)== 1 && utn_getEntero(&auxiliarID,CANTIDAD_CLIENTES,"\n Ingrese ID:\n","\n Error ingrese solo numeros \n",2)==0
                                            && borrarCliente(arrayClientes,CANTIDAD_CLIENTES,auxiliarID)==0)
                                                {

                                                    printf("\n Cliente Borrado con exito!! \n");
                                                    break;
                                                }

                                                break;

                                    case 4:
                                        if  ( ComprobarClienteCargado(arrayClientes,CANTIDAD_CLIENTES)== 1)
                                        {
                                       if(utn_getEntero(&auxiliarID,CANTIDAD_CLIENTES,"Ingrese id \n","Error, reingrese \n",2)==0 &&
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
                                        }
                                          break;

                                    case 5:

                                          if(ComprobarClienteCargado(arrayClientes,CANTIDAD_CLIENTES)==1)
                                          {
                                                //imprimirVentas(arrayVentas,CANTIDAD_VENTAS);
                                                imprimirVentas(arrayVentas,CANTIDAD_VENTAS);


                                                if ( utn_getEntero(&auxiliarID, CANTIDAD_CLIENTES, "Ingrese id\n","No es un id valido \n", 3) == 0 &&
                                                    ModificarVentasPorId(arrayVentas,CANTIDAD_VENTAS,auxiliarID) == 0)
                                                    {
                                                        printf("se modifico correctamente\n");
                                                        break;
                                                    }
                                            }
                                                    break;

                                    case 6:

                                            if(ComprobarClienteCargado(arrayClientes,CANTIDAD_CLIENTES)==1)
                                            {
                                                imprimirVentas(arrayVentas,CANTIDAD_VENTAS);

                                                if(utn_getEntero(&auxIdVenta,CANTIDAD_VENTAS,"\n Ingrese Id de VEnta \n","\nError Ingrese un Id Valido \n",2)== 0
                                                    &&
                                                        imprimirVentaDeCliente(arrayVentas,arrayClientes,CANTIDAD_VENTAS,CANTIDAD_CLIENTES,auxIdVenta)== 0)
                                                    {
                                                        printf("\n se Cambio el estado de la venta!!");
                                                        break;
                                                    }
                                            }
                                                break;
                                    case 7:
                                            if(ComprobarClienteCargado(arrayClientes,CANTIDAD_CLIENTES)==1)
                                            {
                                                    ImprimirClientes(arrayClientes,CANTIDAD_CLIENTES,arrayVentas,CANTIDAD_VENTAS );
                                                    break;
                                            }
                                                    break;

                                    case 8:
                                if(ComprobarClienteCargado(arrayClientes,CANTIDAD_CLIENTES)==1)
                                    {

                                        informes_ImprimirClientesMenosVentasaCobrar(arrayClientes,CANTIDAD_CLIENTES,arrayVentas,CANTIDAD_VENTAS );
                                             break;
                                    }

                                    break;
                                    case 9:
                                         if(ComprobarClienteCargado(arrayClientes,CANTIDAD_CLIENTES)==1)
                                            {
                                                informes_ImprimirClientesMenosVentasCobradas(arrayClientes,CANTIDAD_CLIENTES,arrayVentas,CANTIDAD_VENTAS );
                                                 break;
                                            }
                                        break;

                                    case 10:
                                           if(ComprobarClienteCargado(arrayClientes,CANTIDAD_CLIENTES)==1)
                                            {
                                               if(   informes_ImprimirClientesMenosVentas(arrayClientes,CANTIDAD_CLIENTES,arrayVentas,CANTIDAD_VENTAS)!=0)
                                               {
                                                printf("\n No se puedo relizar la operacion!! \n");
                                                break;
                                               }
                                            }

                                                break;
                                    case 11:

                                           if(ComprobarClienteCargado(arrayClientes,CANTIDAD_CLIENTES)==1)
                                            {
                                             if(informes_ZonaMasAfichesVendidos(arrayVentas,CANTIDAD_VENTAS, arrayClientes,CANTIDAD_CLIENTES)!=0)
                                                {
                                                    printf("\n No se puedo relizar la operacion!! \n");
                                                    break;
                                                }
                                            }
                                        break;

                                    case 12:
                                            if(ComprobarClienteCargado(arrayClientes,CANTIDAD_CLIENTES)==1)
                                            {
                                           if(informar_clienteConMenosAfiches(arrayVentas,  CANTIDAD_VENTAS, arrayClientes, CANTIDAD_CLIENTES)!=0)
                                               {
                                                printf("\n No se puedo relizar la operacion!! \n");
                                                  break;
                                               }
                                            }
                                        break;
                                    case 13:
                                            if(ComprobarClienteCargado(arrayClientes,CANTIDAD_CLIENTES)==1)
                                            {

                                            if(informes_clientesMasAfichesACobrar(arrayVentas, CANTIDAD_VENTAS,arrayClientes, CANTIDAD_CLIENTES)!=0)
                                                {
                                                    printf("\n No se puedo relizar la operacion!! \n");
                                                    break;
                                                }
                                            }
                                            break;
                                    case 14:
                                         if(ComprobarClienteCargado(arrayClientes,CANTIDAD_CLIENTES)==1)
                                            {
                                              if  (informes_clientesMasQuinientosAfiches(arrayVentas,CANTIDAD_VENTAS,arrayClientes,CANTIDAD_CLIENTES)!=0)
                                              {
                                                  printf("\n No se puedo relizar la operacion!! \n");
                                                break;
                                              }


                                            }
                                                break;
                                    case 15:
                                         if(ComprobarClienteCargado(arrayClientes,CANTIDAD_CLIENTES)==1)
                                         {
                                            if(informes_afichesVendidosPorZona(arrayVentas,CANTIDAD_VENTAS)!= 0)
                                            {
                                                  printf("\n No se puedo relizar la operacion!! \n");
                                                break;
                                            }

                                               break;
                                            }
                                        break;
                                    case 16:
                                          if(ComprobarClienteCargado(arrayClientes,CANTIDAD_CLIENTES)==1)
                                            {
                                                if(informes_cantidadAfichesVendidosPromedio(arrayVentas,CANTIDAD_VENTAS,arrayClientes,CANTIDAD_CLIENTES)!=0)
                                                {
                                                    printf("\n No se puedo relizar la operacion!! \n");
                                                }
                                                  break;
                                            }
                                                break;
                                    case 17:
                                         if(ComprobarClienteCargado(arrayClientes,CANTIDAD_CLIENTES)==1)
                                            {
                                                printf("Entro");
                                                informes_listarVentasOrdenadasPorZona(arrayVentas,CANTIDAD_VENTAS);
                                            }
                                                break;
                                        case 18:

                                        printf("\nCerrando...\n");
                                        break;

                                }


                        }while(opcion!=20);





    return 0;
}
