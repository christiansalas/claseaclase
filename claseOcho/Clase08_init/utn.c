#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"
#define STR 4096
#include <ctype.h>


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

 if(pBuffer != NULL && limite>0)
 {
 retorno = 1;
 for (i =0; i<limite && pBuffer[i] != '\0';i++ )
  {
    {

         if (tolower(pBuffer[i]) < 'a' || tolower(pBuffer[i] )<= 'z' )
         {
            retorno = 0;
            break;

         }



    }

  }

    return retorno;

}
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
    char bufferStr[STR];
    int auxLen;


    if (pBuffer != NULL && limite>0)
    {
         __fpurge(stdin);
        fgets(bufferStr,limite,stdin);

        auxLen = strlen(bufferStr);
        if ( auxLen != (limite-1) || bufferStr[limite-2]== '\n' )
        {

            bufferStr[auxLen-1]= '\0';


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
int utn_getNombre(  char* pnombre,int limite,char* msg,
                    char* msgErr, int reintentos)

{
    int retorno=-1;
    char bufferNombre[STR];

    if(pnombre !=NULL && limite> 0 && msg != NULL &&
            msgErr  != NULL && reintentos >=0)
    {
        do
        {
            printf("%s",msg);
        if (getString(bufferNombre,limite)==0 && isValidNombre(bufferNombre, limite))
            {
                strncpy(pnombre,bufferNombre,limite);
                retorno = 0;
                break;

            }
        else
            {
                printf("%s",msgErr);
            }


            reintentos--;



        }while(reintentos>0);



    }



    return retorno;
}
void String_swap (int* elementoA, int* elementoB)
{
    int auxiliar;
    auxiliar = *elementoA;
    *elementoA = *elementoB;
    *elementoB = auxiliar;
}
int ordenarString(int* pbuffer, int limite, int order)
{
    int retorno= -1;
    int j;
    int flagSwap = 0;
    if(pbuffer != NULL && limite > 0)
    {
        do
        {
            for(j=0;j<limite-1;j++)
            {
                if (order == 0 && pbuffer[j] < pbuffer[j+1] || (order == 1 && pbuffer[j] <pbuffer[j+1]))
                {
                    flagSwap = 1;
                    String_swap(&pbuffer[j], &pbuffer[j+1]);
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

void ordenarPorNombre(char* pNombres[50], char* pApellidos, int limite)
{

int swap ;
int i;
char bufferStr[256];


do
    {

    swap = 0;
    for (i=0; 1<limite-1;i++)
    {

       if( strcmp(pNombres[i],pNombres[i+1])>0)
       {
       strcpy(bufferStr,pNombres[i]);
       strcpy(bufferStr,pNombres[i]);
        strcpy(pNombres[i+1],bufferStr);



       }

    }



    }while (swap);





}






















