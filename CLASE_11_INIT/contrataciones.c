#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"
#include "contrataciones.h"

static int con_buscarIndiceVacio(Contratacion* pBuffer,int limite,int*indice);
int con_inicializarArray(Contratacion* pBuffer,int limite){
    int i;
    for(i=0;i<limite;i++){
        pBuffer[i].isEmpty=1;
    }
    return 0;
}
int con_borrarPorID(Contratacion* pBuffer,int limite,int id){
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++){
        if(pBuffer[i].isEmpty==0&& pBuffer[i].ID==id){
            pBuffer[i].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}
int con_contratarPublicidad(Contratacion* pBuffer,int id,int limite){
    int indice;
    if(con_buscarIndiceVacio(pBuffer,limite,&indice)==0){
        pBuffer[indice].ID=con_obtenerID();
        pBuffer[indice].isEmpty=0;
        pBuffer[indice].idPantalla=id;
        utn_getLetrasYNumeros(pBuffer[indice].video,15,"\nIngrese el nombre del video: ");
        utn_getLetrasYNumeros(pBuffer[indice].cuit,10,"\nIngrese el CUIT: ");
        utn_getEntero(&pBuffer[indice].dias,3,"\nIngrese la cantidad de dias: ","\nError Ingrese una cantidad de dias validos",1,200);
    }
    return 0;
}
int con_obtenerID(){
    static int ID=0;
    return ID++;
}
static int con_buscarIndiceVacio(Contratacion* pBuffer,int limite,int*indice){
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++){
        if(pBuffer[i].isEmpty==1){
            *indice=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}
int con_imprimirPorCuit(Contratacion* pBuffer,int limite,char* cuit){
    int i;
    int retorno=-1;
    if(pBuffer!=NULL&&limite>0&&cuit!=NULL){
        for(i=0;i<limite;i++){
            if(pBuffer[i].isEmpty==0&&strcmp(pBuffer[i].cuit,cuit)==0){
                retorno=0;
                printf("\nID: %d",pBuffer[i].ID);
                printf("\tID Pantalla: %d",pBuffer[i].idPantalla);
                printf("\tDias: %d",pBuffer[i].dias);
                printf("\tVideo: %s",pBuffer[i].video);
            }
        }
    }
    return retorno;
}
int con_modificarPorIdPantalla(Contratacion* pBuffer,int limite,int idPantalla){
    int i;
    int retorno=-1;
    if(pBuffer!=NULL&&limite>0){
        for (i=0;i<limite;i++){
            if(pBuffer[i].idPantalla==idPantalla&& pBuffer[i].isEmpty==0){
                retorno=0;
                utn_getEntero(&pBuffer[i].dias,3,"\nIngrese la cantidad de dias: ","\nError Ingrese una cantidad de dias validos",1,200);
            }
        }
    }
    return retorno;
}
int con_cancelarById(Contratacion* pBuffer,int limite,int idPantalla){
    int i;
    int retorno=-1;
        if(pBuffer!=NULL&&limite>0){
            for(i=0;i<limite;i++){
                if(pBuffer[i].idPantalla==idPantalla&& pBuffer[i].isEmpty==0){
                    retorno=0;
                    pBuffer[i].isEmpty=1;
                }
            }
        }
    return retorno;
}

int con_listarImportePorContratacion(Contratacion* pBufferCon,Pantalla* pBufferPan,int limiteCon,char* cuit,int limitePan){
    int retorno=-1;
    char auxCuit;
    int i,j;

    for (i=0;i<limiteCon;i++)
    {
        if (pBufferCon[i].isEmpty == 0 && (strcmp(pBufferCon[i].cuit,cuit)==0))
        {

            for(j=0;j<limiteCon;j++)
                {

                    if(pBufferCon[j].idPantalla == pBufferCon[j].ID)
                        {
                        printf("\n El importe a pagar es : %.2f",pBufferPan[j].precio);
                        break;

                        }
                }

       }
            retorno = 0 ;
    }


    return retorno;
}

int con_imprimirContrataciones(Contratacion* pBuffer,int limite)
{
    int i;
    system("clear");



    for (i=0;i<limite;i++)
    {
            if ( pBuffer[i].isEmpty == 0 )
        {
            printf("\nID: %d",pBuffer[i].ID);
            printf("\tVideo: %s",pBuffer[i].video );
            printf("\tCuit: %s",pBuffer[i].cuit);
            printf("\tDias: %d",pBuffer[i].dias);
            printf("\tTipo: %d",pBuffer[i].idPantalla);

        }
    }


    return 1;
}

int con_ordenarByCuit(Contratacion* pBuffer,int limite,int upOrDonw)

{
  int i,j;

Contratacion auxBuffer;


    for (i=0;i<limite;i++)
    {

      for (j=i+1;j<limite-1;j++)
        {
            if (strcmp(pBuffer[i].cuit,pBuffer[j].cuit)>upOrDonw)
                {
                    auxBuffer =pBuffer[j];
                    pBuffer[j]=pBuffer[i];
                    pBuffer[i] = auxBuffer;

                }

        }

    }

 return 1;

}
int con_intercambiarPocionEstructura(Contratacion* pBuffer,int indiceDestino,int indiceOrigen){
    return 0;
}

int con_agruparPosiciones(Contratacion* pBuffer,int limite){

    return 1;
}

int con_ingresoForzado(Contratacion* pBuffer,int limite,char* video,char* cuit,int dias,int idPantalla){
    int aux;
    con_buscarIndiceVacio(pBuffer,limite,&aux);
    strcpy(pBuffer[aux].video,video);
    strcpy(pBuffer[aux].cuit,cuit);
    pBuffer[aux].dias=dias;
    pBuffer[aux].idPantalla=idPantalla;
    pBuffer[aux].isEmpty=0;
    pBuffer[aux].ID=con_obtenerID();
    return 0;
}
int con_listarClientesEImportes(Contratacion * pBufferCon,Pantalla* pbufferPan,int limiteCon,int limitePan)
{
int i,j,k;

Informes arrayInformes[4026];

   for(k=0;k<limiteCon;k++)
   {
   arrayInformes[k].isEmpty == 0;

   }

    for (i=0;i<limiteCon;i++)
    {
        for(j=i+1;j<limitePan-1;j++)
            {
                if(  strcmp(pBufferCon[i].cuit,pbufferPan[j].cuit) != 0 && arrayInformes)

                    {

                 strcpy(arrayInformes[i].cuit,pBufferCon[i].cuit);



                    }

            }


    }
      return 1;
}
