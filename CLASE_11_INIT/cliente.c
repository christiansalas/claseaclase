#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"

#include "cliente.h"


static int getNextId()

{

static int idCLiente = -1;
idCLiente++;
return idCLiente;



}

int con_inicializarArray(Clientes* pCliente,int limiteCliente,Contratacion* pContrataciones,int limiteContrataciones);

{

int retorno = -1;

if(pCliente!=NULL && limiteCliente>0 && pContrataciones != NULL)
{



}








return retorno;


}

int con_imprimirClientees(Clientes* pBuffer,int limite);
{


}

int cliente_ordenarBycuit(Clientes* pBuffer,int limite,int upOrDonw);
{

}


int con_listarClientesEImportes(Contratacion * pBufferCon,Pantalla* pbufferPan,int limiteCon,int limitePan)
{




Clientes* cliente_getClienteByCuit(Clientes* pbuffer , int limite,char* cuit)
{

Clientes* retorno =NULL;
int i;
if(pbufferPan!=NULL && limite>0 && cuit != NULL)
{

    for (i=o;i<limite;i++)
        {
            if(!strcmp(cuit,pbuffer[i].cuit))
                {

                retorno = &pbuffer[i];//pbuffer+i (la forma correcta seria
                break;

                }

        }
        }

return retorno:


}
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
