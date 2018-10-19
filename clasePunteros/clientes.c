#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>
static int isValidNombre(char* nombre);


Cliente * cli_newCliente(void)
{

   return (Cliente*) malloc(sizeof(Cliente));
 /*Cliente *p;

 p= (Cliente*) malloc(sizeof(Cliente));
 return p;*/



}
int clie_setNombre(Cliente* this,char* nombre)
{
    int retorno = -1;
    if(this !=NULL && isValidNombre(nombre))
            {
                strncpy(this->nombre,nombre,sizeof(this->nombre));
                retorno = 0;
            }

    return retorno ;
}
static int isValidNombre(char* nombre)
{
    return 1;

}




int clie_getNombre(Cliente* this, char*nombre)
{
int retorno= -1;

            if(this !=NULL && nombre!=NULL)
            {
            strncpy(nombre, this->nombre,sizeof(this->nombre));

            }
        return retorno;

}



int clie_buscarLugarVacio(Cliente* array[], int limitearray)
{
int retorno = -1;
int i;
        if(array !=NULL)
            {
                for (i=0; i<limitearray ; i++)
                        {
                         if( array[i]==NULL)
                             {
                             retorno = i;
                             break;
                             }
                        }

            }
return retorno;
}



int clie_inicializarArray(Cliente* array[],int limiteArray)
{
int retorno =-1;
int i;
            if(array!=NULL && limiteArray>0)
            {

            retorno =0;
            for (i=0; i<limiteArray ; i++)
                {
                    array[i]=NULL;
                }

            }

            return retorno;
}


int clie_buscarPorId(Cliente * array[],int limiteArray, int id)
{

int retorno = -1;
int i ;
Cliente* aux;


if(array !=NULL && limiteArray>0 && id>=0)
{
for(i=0;i<limiteArray;i++)
    {

        aux = array[i];

            if(aux != NULL && aux->iDClientes==id)
                {
                retorno = i;
                break;

                }

    }
    return retorno;

}







return retorno;

}
int clie_deleteCliente(Cliente* this)
{
int retorno =-1;
        if(this !=NULL)
        {
            free(this);
            retorno = 0;

        }

return retorno;
}


Cliente* clie_newClienteParametroas(char* nombre,char *apellido,int id)
{
Cliente* p;
p =cli_newCliente();

                if (p != NULL)
                {
                    if(clie_setNombre(p,apellido)==-1 /*clie_setApellido(p,nombre)==-1 || clie_setId(p,id)==-1*/)
                    {
                    clie_deleteCliente(p);
                    p=NULL;

                    }


                }
return p;

}






