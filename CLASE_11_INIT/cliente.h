#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"
#include "Clientees.h"

typedef struct{

char cuit [10];
int IdCliente;
int isEmpty;

}Clientes;



int con_inicializarArray(Clientes* pBuffer,int limite);
static co_obtenerID();
int con_imprimirClientees(Clientes* pBuffer,int limite);
int con_ordenarByCuit(Cliente* pBuffer,int limite,int

Clientes* cliente_getClienteByCuit(Clientes* pbuffer , int limite,char* cuit);

#endif
