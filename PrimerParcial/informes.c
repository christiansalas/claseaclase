
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "clientes.h"
#include "ventas.h"
#include "informes.h"



/**
* \brief Se utiliza esta funcion para mostrar el cliente con menos ventas a cobrar
* \param listVentas Es el array que se recorre
* \param limiteVentas Es el limite de ventas que puede guardar el array
* \param listClientes Es el array que se recorre
* \param limiteClientes Es el limite de clientes que puede guardar el array
* \return El retorno es 0 si se mostraron los datos, si no el retorno es -1.
*/

 int informes_ImprimirClientesMenosVentasaCobrar(Clientes *listClientes,int limiteClientes,Ventas *listVentas,int limiteVentas )
 {
int retorno = -1;
int i,j;
int contadorVentasACOBRAR;
int arrayVentasPorCliente[limiteClientes];
int menorCantidadDeVentas =0;

     if(listClientes != NULL && limiteClientes>0 && listVentas !=NULL && limiteVentas > 0)
     {
            for (i=0;i< limiteClientes;i++)
                {
                    if( listClientes[i].isEmpty == 1)
                        {
                            contadorVentasACOBRAR = 0;
                              for(j=0;j<limiteVentas; j++)
                                {

                                    if( venta_getByIdCliente(&listVentas[j], 1, listClientes[i].idClientes) != 0 &&
                                        strcmp( listVentas[j].estadoVenta,"Cobrada")== 0)
                                                {
                                                    contadorVentasACOBRAR++;
                                                }
                                }
                                    arrayVentasPorCliente[i]=contadorVentasACOBRAR;

                        }
                            if(listClientes[i].isEmpty== 1 && arrayVentasPorCliente[i]>menorCantidadDeVentas)
                                {
                                    menorCantidadDeVentas=arrayVentasPorCliente[i];
                                }
                }
                                for(i=0; i < limiteClientes; i++)
                                {
                                    if(listClientes[i].isEmpty == 1 && menorCantidadDeVentas == arrayVentasPorCliente[i])
                                        {
                                            printf("\nEl cliente con menos cantidad de ventas a cobrar es :\n");
                                            printf("\n ID : %d \n",listClientes[i].idClientes);
                                            printf("\n Nombre : %s \n",listClientes[i].nombre);
                                            printf("\n apellido : %s \n",listClientes[i].apellido);
                                            printf("\n Cuit : %s \n",listClientes[i].cuit);
                                            printf("\n---------------------\n");
                                        }
                                                retorno = 0;
                                }

        }


    return retorno;


}

/**
* \brief Se utiliza esta funcion para mostrar el cliente con  ventas cobradas
* \param listVentas Es el array que se recorre
* \param limiteVentas Es el limite de ventas que puede guardar el array
* \param listClientes Es el array que se recorre
* \param limiteClientes Es el limite de clientes que puede guardar el array
* \return El retorno es 0 si se mostraron los datos, si no el retorno es -1.
*/

 int informes_ImprimirClientesMenosVentasCobradas(Clientes *listClientes,int limiteClientes,Ventas *listVentas,int limiteVentas )
 {
int retorno = -1;
int i,j;
int contadorVentasaCobrar;
int arrayVentasPorCliente[limiteClientes];
int mayorCantidadDeVentas =0;

     if(listClientes != NULL && limiteClientes>0 && listVentas !=NULL && limiteVentas > 0)
     {
            for (i=0;i< limiteClientes;i++)
                {
                    if( listClientes[i].isEmpty == 1)
                        {
                            contadorVentasaCobrar = 0;
                              for(j=0;j<limiteVentas; j++)
                                {

                                    if( venta_getByIdCliente(&listVentas[j], 1, listClientes[i].idClientes) != 0 &&
                                        strcmp( listVentas[j].estadoVenta,"A_COBRAR")== 0)
                                                {

                                                    contadorVentasaCobrar++;
                                                }
                                }
                                    arrayVentasPorCliente[i]=contadorVentasaCobrar;

                        }
                            if(listClientes[i].isEmpty== 1 && arrayVentasPorCliente[i]>mayorCantidadDeVentas)
                                {
                                    mayorCantidadDeVentas=arrayVentasPorCliente[i];
                                }
                }
                                for(i=0; i < limiteClientes; i++)
                                {
                                    if(listClientes[i].isEmpty == 1 && mayorCantidadDeVentas == arrayVentasPorCliente[i])
                                        {
                                            printf("\nEl cliente con menos cantidad de ventas cobradas es :\n");
                                            printf("\n ID : %d \n",listClientes[i].idClientes);
                                            printf("\n Nombre : %s \n",listClientes[i].nombre);
                                            printf("\n apellido : %s \n",listClientes[i].apellido);
                                            printf("\n Cuit : %s \n",listClientes[i].cuit);
                                            printf("\n---------------------\n");
                                        }
                                                retorno = 0;
                                }

        }


    return retorno;


}

/**
* \brief Se utiliza esta funcion para mostrar el cliente con menos ventas
* \param listVentas Es el array que se recorre
* \param limiteVentas Es el limite de ventas que puede guardar el array
* \param listClientes Es el array que se recorre
* \param limiteClientes Es el limite de clientes que puede guardar el array
* \return El retorno es 0 si se mostraron los datos, si no el retorno es -1.
*/

 int informes_ImprimirClientesMenosVentas(Clientes *listClientes,int limiteClientes,Ventas *listVentas,int limiteVentas )
 {
int retorno = -1;
int i,j;
int contadorVentas;
int arrayVentasPorCliente[limiteClientes];
int mayorCantidadVentas =0;
int menorCantidadVentas =0;

     if(listClientes != NULL && limiteClientes>0 && listVentas !=NULL && limiteVentas > 0)
     {
            for (i=0;i< limiteClientes;i++)
                {
                    if( listClientes[i].isEmpty == 1)
                        {
                            contadorVentas = 0;
                            for(j=0;j<limiteVentas; j++)
                            {
                                if( venta_getByIdCliente(&listVentas[j], 1, listClientes[i].idClientes) != 0 && strcmp(listVentas[j].estadoVenta,"A_COBRAR")==0 && strcmp(listVentas[j].estadoVenta,"Cobrada" )== 0);
                                    {
                                        contadorVentas++;
                                    }
                            }
                                arrayVentasPorCliente[i]=contadorVentas;

                        }
                            if(listClientes[i].isEmpty== 1 && arrayVentasPorCliente[i] >mayorCantidadVentas)
                                {
                                    mayorCantidadVentas=arrayVentasPorCliente[i];
                                }
                            if(listClientes[i].isEmpty== 1 && arrayVentasPorCliente[i] < mayorCantidadVentas)
                                {
                                    menorCantidadVentas=arrayVentasPorCliente[i];
                                }

                }

                    for(i=0; i < limiteClientes; i++)
                        {
                            if(listClientes[i].isEmpty == 1 && menorCantidadVentas == arrayVentasPorCliente[i])
                                {
                                    printf("\nEl cliente con menos cantidad de ventas es  :\n");
                                    printf("\n ID : %d \n",listClientes[i].idClientes);
                                    printf("\n Nombre : %s \n",listClientes[i].nombre);
                                    printf("\n apellido : %s \n",listClientes[i].apellido);
                                    printf("\n Cuit : %s \n",listClientes[i].cuit);
                                    printf("\n---------------------\n");
                                }
                                        retorno = 0;
                        }
        }
    return retorno;

}


/**\brief Se utiliza esta funcion para mostrar la zona con mas afiches vendidos
* \param listVentas Es el array que se recorre
* \param limiteVentas Es el limite de ventas que puede guardar el array
* \param listClientes Es el array que se recorre
* \param limiteClientes Es el limite de clientes que puede guardar el array
* \return El retorno es 0 si se mostraron los datos, si no el retorno es -1.
*/
int informes_ZonaMasAfichesVendidos(Ventas* listVentas, int limiteVentas,Clientes* listClientes, int limiteClientes)
{

    int zonaMasAfichesCaba[limiteClientes],zonaCaba;
    int zonaMasAfichesZonaSur[limiteClientes],zonaSur;
    int zonaMasAfichesZonaOeste[limiteClientes],zonaOeste;
    int retorno=-1;
    int i;
    int j;
    int contadorZonaCaba,contadorZonaOeste,contadorZonaSur;
    int mayorCantidadAfiches = 0;

    if(listVentas != NULL && limiteVentas > 0 && listClientes != NULL && limiteClientes > 0)
    {
        for(i=0; i < limiteClientes; i++)
        {
            if(listClientes[i].isEmpty==1)
            {
                contadorZonaSur = 0;
                contadorZonaCaba = 0;
                contadorZonaOeste = 0;
                for(j=0;j<limiteVentas; j++)
                {
                    if( venta_getByIdCliente(&listVentas[j], 1, listClientes[i].idClientes) != 0 && strcmp(listVentas[j].zonaPegarAfiche,"CABA")==0)
                        {
                        contadorZonaCaba=contadorZonaCaba+listVentas[j].afiches;
                        }

                    if( venta_getByIdCliente(&listVentas[j], 1, listClientes[i].idClientes) != 0 && strcmp(listVentas[j].zonaPegarAfiche,"ZONA_OESTE")==0)
                        {
                        contadorZonaOeste=contadorZonaOeste+listVentas[j].afiches;
                        }

                    if( venta_getByIdCliente(&listVentas[j], 1, listClientes[i].idClientes) != 0 && strcmp(listVentas[j].zonaPegarAfiche,"ZONA_SUR")==0)
                        {
                        contadorZonaSur=contadorZonaSur+listVentas[j].afiches;
                        }
                }

                        zonaMasAfichesCaba[i]=contadorZonaCaba;
                        zonaMasAfichesZonaOeste[i]=contadorZonaOeste;
                        zonaMasAfichesZonaSur[i]=contadorZonaSur;

                    if( zonaMasAfichesCaba[i] > zonaCaba)
                        {
                            zonaCaba = zonaMasAfichesCaba[i];
                        }
                     if( zonaMasAfichesZonaOeste[i] > zonaOeste)
                        {
                            zonaOeste = zonaMasAfichesZonaOeste[i];
                        }
                     if( zonaMasAfichesCaba[i] > zonaCaba)
                        {
                            zonaSur = zonaMasAfichesZonaSur[i];
                        }
            }
        }
            if (zonaCaba > zonaSur && zonaCaba > zonaOeste)
                    {
                        printf("La zona con mas afiches: CABA\n");
                    }
                else if (zonaSur > zonaCaba && zonaSur > zonaOeste)
                    {
                        printf("La zona con mas afiches: ZONA SUR\n");
                    }
                else if (zonaOeste > zonaCaba && zonaOeste > zonaSur)
                    {
                        printf("La zona con mas afiches: ZONA Oeste\n");
                    }
        retorno = 0;


    }
    return retorno;
}

/**\brief Se utiliza esta funcion para mostrar la zona con mas afiches vendidos
* \param listVentas Es el array que se recorre
* \param limiteVentas Es el limite de ventas que puede guardar el array
* \param listClientes Es el array que se recorre
* \param limiteClientes Es el limite de clientes que puede guardar el array
* \return El retorno es 0 si se mostraron los datos, si no el retorno es -1.
*/
int informar_clienteConMenosAfiches(Ventas * listVentas, int limiteVentas, Clientes * listClientes, int limiteClientes)
{
    int retorno = -1;
    int i,j, auxID;
    int acumuladorDeAfiches;
    int clienteConMasAfiches[limiteClientes];
    int clientesConMenosAfiches;
    if (listVentas != NULL && limiteVentas > 0 && listClientes != NULL && limiteClientes > 0)
    {
        for (i= 0; i< limiteClientes; i++)
        {
            if(listClientes[i].isEmpty == 1)
            {
                acumuladorDeAfiches = 0;
                for(j=0; j< limiteVentas; j++)
                {
                    if(venta_getByIdCliente(&listVentas[j], 1, listClientes[i].idClientes) != 0)
                    {
                        acumuladorDeAfiches = acumuladorDeAfiches + listVentas[j].afiches;
                    }
                }
                clienteConMasAfiches[i] = acumuladorDeAfiches;
            }
            if((clienteConMasAfiches[i] < clientesConMenosAfiches || i == 0) && listClientes[i].isEmpty==1)
            {
                clientesConMenosAfiches = clienteConMasAfiches[i];
                auxID = listClientes[i].idClientes;
            }
        }
        for(i= 0; i < limiteClientes; i++)
        {
            if(listClientes[i].idClientes == auxID)
            {
                printf("\nEl cliente que compro menos afiches es  :\n");
                printf("\n ID : %d \n",listClientes[i].idClientes);
                printf("\n Nombre : %s \n",listClientes[i].nombre);
                printf("\n apellido : %s \n",listClientes[i].apellido);
                printf("\n Cuit : %s \n",listClientes[i].cuit);
                printf("\n---------------------\n");
                break;
            }
        }
        retorno = 0;
    }

    return retorno;
}


/**\brief Se utiliza esta funcion para mostrar el cliente con mas afiches  a cobrar
* \param listVentas Es el array que se recorre
* \param limiteVentas Es el limite de ventas que puede guardar el array
* \param listClientes Es el array que se recorre
* \param limiteClientes Es el limite de clientes que puede guardar el array
* \return El retorno es 0 si se mostraron los datos, si no el retorno es -1.
*/

int informes_clientesMasAfichesACobrar(Ventas* listVentas, int limiteVentas,Clientes* listClientes, int limiteClientes)
{

    int arrayVentasporCLienteACobrar[limiteClientes];
    int retorno=-1;
    int i;
    int j;
    int contadorVentaCobrar,contadorZonaOeste,contadorZonaSur;
    int mayorCantidadAfiches = 0;

    if(listVentas != NULL && limiteVentas > 0 && listClientes != NULL && limiteClientes > 0)
    {
        for(i=0; i < limiteClientes; i++)
        {
                    if(listClientes[i].isEmpty==1)
                    {
                        contadorVentaCobrar = 0;
                        for(j=0;j<limiteVentas; j++)
                        {
                            if( venta_getByIdCliente(&listVentas[j], 1, listClientes[i].idClientes) != 0 && strcmp(listVentas[j].estadoVenta,"A_COBRAR")==0)
                                {
                                    contadorVentaCobrar=contadorVentaCobrar + listVentas[j].afiches;

                                }
                        }

                                arrayVentasporCLienteACobrar[i]=contadorVentaCobrar;
                    }

                        if(listClientes[i].isEmpty== 1 && arrayVentasporCLienteACobrar[i] >mayorCantidadAfiches)
                            {
                               mayorCantidadAfiches=arrayVentasporCLienteACobrar[i];
                            }

        }
                for(i=0; i < limiteClientes; i++)
                {
                      if(listClientes[i].isEmpty==1 && mayorCantidadAfiches == arrayVentasporCLienteACobrar[i])
                        {
                            printf("ENTRO");
                            printf("\nEl cliente con mas afiches a cobrar es  :\n");
                            printf("\n ID : %d \n",listClientes[i].idClientes);
                            printf("\n Nombre : %s \n",listClientes[i].nombre);
                            printf("\n apellido : %s \n",listClientes[i].apellido);
                            printf("\n Cuit : %s \n",listClientes[i].cuit);
                            printf("\n---------------------\n");
                            break;
                        }
                }
        retorno = 0;
    }
    return retorno;
}

/**\brief Se utiliza esta funcion para mostrar la cantidad de clientes que compraron mas de 500 afiches
* \param listVentas Es el array que se recorre
* \param limiteVentas Es el limite de ventas que puede guardar el array
* \param listClientes Es el array que se recorre
* \param limiteClientes Es el limite de clientes que puede guardar el array
* \return El retorno es 0 si se mostraron los datos, si no el retorno es -1.
*/

int informes_clientesMasQuinientosAfiches(Ventas* listVentas, int limiteVentas,Clientes* listClientes, int limiteClientes)
{

    int retorno = -1;
    int i,j;
    int acumuladorDeAfiches;
    int contadorCLientesSuperan=0;
    int clientesConMasAfiches= 500;
    if (listVentas != NULL && limiteVentas > 0 && listClientes != NULL && limiteClientes > 0)
    {
        for (i= 0; i< limiteClientes; i++)
        {
            if(listClientes[i].isEmpty == 1)
            {
                acumuladorDeAfiches = 0;
                for(j=0; j< limiteVentas; j++)
                {
                    if(venta_getByIdCliente(&listVentas[j], 1, listClientes[i].idClientes) != 0)
                    {
                        acumuladorDeAfiches = acumuladorDeAfiches + listVentas[j].afiches;
                    }
                }

                    if(acumuladorDeAfiches > clientesConMasAfiches)
                        {
                          contadorCLientesSuperan++;
                        }
            }

        }
      printf("\n La Cantidad de Clientes  con mas de 500 afiches es : %d",contadorCLientesSuperan);
        retorno = 0;
           }

    return retorno;
}

/**\brief Se utiliza esta funcion para mostrar la cantidad de cafiches vendidos por cada una de las 3 zonas
* \param listVentas Es el array que se recorre
* \param limiteVentas Es el limite de ventas que puede guardar el array
* \param listClientes Es el array que se recorre
* \param limiteClientes Es el limite de clientes que puede guardar el array
* \return El retorno es 0 si se mostraron los datos, si no el retorno es -1.
*/
int informes_afichesVendidosPorZona(Ventas* listVentas, int limiteVentas)
{
    int retorno=-1;
    int contadorZonaSur = 0,contadorZonaCaba = 0,contadorZonaOeste = 0,i;
    int mayorCantidadAfiches = 0;

    if(listVentas != NULL && limiteVentas > 0)
    {
                for(i=0;i<limiteVentas; i++)
                {
                        if( listVentas[i].isEmptyVentas== 1 && strcmp(listVentas[i].zonaPegarAfiche,"CABA")==0)
                        {
                        contadorZonaCaba=contadorZonaCaba+listVentas[i].afiches;
                        }

                    if( listVentas[i].isEmptyVentas== 1 && strcmp(listVentas[i].zonaPegarAfiche,"ZONA_OESTE")==0)
                        {
                        contadorZonaOeste=contadorZonaOeste+listVentas[i].afiches;
                        }

                    if( listVentas[i].isEmptyVentas== 1  && strcmp(listVentas[i].zonaPegarAfiche,"ZONA_SUR")==0)
                        {
                        contadorZonaSur=contadorZonaSur+listVentas[i].afiches;
                        }
                }

                    printf("\nEn zona CABA se vendieron  : %d\n",contadorZonaCaba);
                    printf("\nEn zona ZONA OESTE  se vendieron  : %d\n",contadorZonaOeste);
                    printf("\nEn zona ZONA SUR se vendieron  : %d\n",contadorZonaSur);
                    retorno = 0;
        }

    return retorno;
}

/**\brief Se utiliza esta funcion para mostrar el promedio de los afiches vendidos dividido la cantidad de clientes
* \param listVentas Es el array que se recorre
* \param limiteVentas Es el limite de ventas que puede guardar el array
* \param listClientes Es el array que se recorre
* \param limiteClientes Es el limite de clientes que puede guardar el array
* \return El retorno es 0 si se mostraron los datos, si no el retorno es -1.
*/
int informes_cantidadAfichesVendidosPromedio(Ventas* listVentas, int limiteVentas,Clientes* listClientes, int limiteClientes)
{
    float promedio;
    int retorno=-1;
    int i;
    int j;
    int acumuladorAfiches=0, contadorClientes =0;
    int arrayClientes[limiteClientes];

    if(listVentas != NULL && limiteVentas > 0 && listClientes != NULL && limiteClientes > 0)
    {
                for(i=0; i < limiteClientes; i++)
                {
                    if(listClientes[i].isEmpty==1)
                    {
                        for(j=0;j<limiteVentas; j++)
                        {
                            if( venta_getByIdCliente(&listVentas[j], 1, listClientes[i].idClientes) != 0 )
                            {
                                acumuladorAfiches=acumuladorAfiches + listVentas[j].afiches;
                                contadorClientes++;
                            }
                        }
                    }
                }
                            promedio= acumuladorAfiches/contadorClientes;

                    if(contadorClientes>0)
                        {
                            printf("\n el promedio de afiches  por cliente es : %.2f",promedio);
                        }

                retorno = 0;
    }
return retorno;
}

int informes_listarVentasOrdenadasPorZona(Ventas * listVentas, int limiteVentas)
{

int retorno = -1;
    int i;
    if(listVentas != NULL && limiteVentas > 0)
    {
        for(i=0;i<limiteVentas;i++)
            {
                if(listVentas[i].isEmptyVentas==1 &&(strcmp(listVentas[i].zonaPegarAfiche,"ZONA_SUR")==0) )
                {
                printf("\nIdcliente: %d\nAfiches: %d\nImagen: %s\nIDVenta: %d\n Zona : %s \n"
                    ,listVentas[i].IdCliente, listVentas[i].afiches,listVentas[i].nombreAfiche, listVentas[i].IdVentas,listVentas[i].zonaPegarAfiche);
                }

            }
                    for(i=0;i<limiteVentas;i++)
                    {
                      if(listVentas[i].isEmptyVentas==1 &&(strcmp(listVentas[i].zonaPegarAfiche,"CABA")==0) )
                        {
                            printf("\nIdcliente: %d\nAfiches: %d\nImagen: %s\nIDVenta: %d\n Zona : %s \n"
                            ,listVentas[i].IdCliente, listVentas[i].afiches,listVentas[i].nombreAfiche, listVentas[i].IdVentas,listVentas[i].zonaPegarAfiche);
                        }


                    }
                       for(i=0;i<limiteVentas;i++)
                       {

                            if(listVentas[i].isEmptyVentas==1 &&(strcmp(listVentas[i].zonaPegarAfiche,"ZONA_OESTE")==0) )
                            {
                            printf("\nIdcliente: %d\nAfiches: %d\nImagen: %s\nIDVenta: %d\n Zona : %s \n"
                            ,listVentas[i].IdCliente, listVentas[i].afiches,listVentas[i].nombreAfiche, listVentas[i].IdVentas,listVentas[i].zonaPegarAfiche);

                            }
                        }
                          retorno = 0;
            }




    return retorno;
}











