#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#define BUFFER_STR 4096

/**
    utn_getNombre :
    @param
    @param
    @return
*/
static int isValidNombre(char* pBuffer,int limite)
{
    int retorno = 0;
    int i;
    if(pBuffer != NULL && limite > 0)
    {
        retorno = 1;
        for(i=0;i < limite && pBuffer[i] != '\0';i++)
        {
            if(tolower(pBuffer[i]) < 'a' || tolower(pBuffer[i]) > 'z')
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
    utn_getNombre :
    @param
    @param
    @return
*/
static int getString(char* pBuffer, int limite)
{
    int retorno = -1;
    char bufferStr[BUFFER_STR];
    int len;
    if(pBuffer != NULL && limite > 0)
    {
        __fpurge(stdin);
        fgets(bufferStr,limite,stdin);
        len = strlen(bufferStr);
        if(len != limite-1 ||  bufferStr[limite-2] == '\n')
        {
            bufferStr[len-1] = '\0';
        }
        retorno = 0;
        strncpy(pBuffer,bufferStr,limite);
    }
    return retorno;
}


/**
    utn_getNombre :
    @param
    @param
    @return
*/
int utn_getNombre(  char* pNombre, int limite, char* msg,
                    char* msgErr, int reintentos)

{
    int retorno=-1;
    char bufferNombre[BUFFER_STR];

    if( pNombre != NULL && limite > 0 && msg != NULL &&
        msgErr != NULL && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( getString(bufferNombre,limite) == 0 &&
                isValidNombre(bufferNombre,limite))
            {
                strncpy(pNombre,bufferNombre,limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("%s",msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}


int producto_init(eProducto* arrayProducto, int len, int valor)
{
    int i;
    int retorno = -1;

    if(arrayProducto != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            arrayProducto[i].isEmpty = valor;
            retorno = 0;
        }
    }

    return retorno;
}

int producto_alta(eProducto* arrayProducto, int len, int indice)
{
    int retorno = -1;
    char auxNombre[50];
    char auxDescripcion[200];
    float auxPrecio = 13.55;

    if(arrayProducto != NULL && len > 0 && indice >= 0 && indice < len && arrayProducto[indice].isEmpty)
    {
        if( !utn_getNombre(auxNombre,50,"Nombre Producto: \n","Nombre no valido: \n",2) &&
            !utn_getNombre(auxDescripcion,50,"Descripcion: \n","Descripcion no valido: \n",2) )
        {
            strncpy(arrayProducto[indice].nombre,auxNombre,50);
            strncpy(arrayProducto[indice].descripcion,auxDescripcion,50);
            arrayProducto[indice].precio = auxPrecio;
            arrayProducto[indice].isEmpty = 0;
            arrayProducto[indice].iD = indice+1;
            retorno = 0;
        }
    }

    return retorno;
}


int producto_imprimir(eProducto* arrayProducto, int lenght)
{

    int i;
    int retorno = -1;
    if(arrayProducto != NULL && len > 0)
    {

    for(i=0;i<lenght;i++)
    {
        if(arrayProducto[i].isEmpty != 1)
        {
            printf("\nP: %s\nD: %s\nV: %.2f\n Id: %d\n",arrayProducto[i].nombre,arrayProducto[i].descripcion,arrayProducto[i].precio,arrayProducto[i].iD);
        }
    }
    }

    return retorno;
}


int producto_indiceLibre(eProducto* arrayProducto, int len )
{

    int i;
    int retorno = -1;
    if(arrayProducto != NULL && len > 0)
    {
    for(i=0;i<len;i++)
    {
        if(arrayProducto[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }
    }
    }

    return retorno;



}


int producto_indiceId(eProducto* arrayProducto,int len ,int iD)
{
int i ;
int retorno = -1;

if(arrayProducto != NULL && len > 0 && id>0
{
for (i=0;i<len ; i++)
{

if (arrayProducto[i].iD ==  iD)
{

retorno = i;

}


}

return   retorno;
}





}












