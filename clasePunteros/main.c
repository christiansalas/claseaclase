#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>
#define CLIENTES 100







//mallor () pide bytes
//free devuelve espacio de memoria sin utilIZAR

int main()
{

Cliente* aux;

Cliente*arrayClientes[CLIENTES];
int i;
int indexVacio;

 aux = cli_newCliente();
 clie_inicializarArray(arrayClientes,CLIENTES);


            if(aux != NULL)
                 {
                 clie_setNombre(aux,"Juan");// al campo nombre le escribe juan
                   // strncpy(aux->nombre,"Camela",sizeof(aux->nombre));
                    arrayClientes[0]=aux;
                    char nombreAux[64];
                    clie_getNombre(aux,nombreAux);
                    printf("%s",aux->nombre);
                 }


return 0;


}









