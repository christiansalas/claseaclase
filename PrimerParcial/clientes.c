
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "clientes.h"
#include "ventas.h"
/* brief inicializa el array en 0 para verificar que esten vacios
*
*/

int inicializarCliente(Clientes* pBuffer,int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
       pBuffer[i].isEmpty = 0;
    }
    return 0;
}

/**
* \brief    funcion que da de alta un cliente.
* \param list es la cadena que evaluamos.
* \param len Es el tamano maximo del string
* \return En caso de exito retorna 0, si no -1
*/

int altaCliente(Clientes* list, int len)
{
int i;
int retorno =-1;
char auxNombre [50];
char auxApellido [50];
char auxCuit[12];


        if(list != NULL && len > 0)
            {
                 for(i=0;i<len;i++)
                 {
                     fflush(stdin);
                        if( list[i].isEmpty ==0
                        &&
                         utn_getNombre(auxNombre,50,"\n Ingrese nombre \n","\n Error, nombre Invalido\n", 2)==0
                         &&
                         utn_getNombre(auxApellido,50,"\n Ingrese apellido \n","\n Error, apellido Invalido\n", 2)==0
                         &&
                         utn_getLetrasYNumeros(auxCuit,12,"\n Ingrese cuit \n")==0)
                            {
                                list[i].idClientes =  getNextId()
    ;
                                strncpy(list[i].nombre, auxNombre, 50);
                                strncpy(list[i].apellido, auxApellido, 50);
                                  strncpy(list[i].cuit, auxCuit, 50);
                                list[i].isEmpty =  1;
                                retorno = 0;

                              /*  printf("idcleinte : %d",list[i].idClientes);
                                printf(" nombre : %s",list[i].nombre);
                                printf("apellido : %s",list[i].apellido);
                                printf("apellido : %s",list[i].cuit);*/

                                break;
                             }
                }
            }
return retorno;
}

/**
* \brief    Evalua si es un string valido
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 0, si no -1
*/
int utn_getString(char *pBuffer, int limite)
{
    int retorno = -1;
    char bufferStr[4096];
    int len;
    if(pBuffer != NULL && limite > 0)
    {
        //__fpurge(stdin);
        fflush(stdin);
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
* \brief    Evalua si es un nombre valido
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 0, si no -1
*/


int utn_getNombre(  char* pNombre, int limite, char* msg,
                    char* msgErr, int reintentos)

{
    int retorno=-1;
    char bufferNombre[100];

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

/**
* \brief    Evalua si es un string valido
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 0, si no -1
*/

 int getString(char* pBuffer, int limite)
{
    int retorno = -1;
    char bufferStr[100];
    int len;
    if(pBuffer != NULL && limite > 0)
    {
       // __fpurge(stdin);
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
* \brief    Evalua si es un nombre valido
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 0, si no -1
*/


 int isValidNombre(char* pBuffer,int limite)
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
* \brief    Evalua si se ingresan letras y numeros
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 1, si no 0
*/

int utn_getLetrasYNumeros(char* pBuffer,int limite,char* msj)
{
    int retorno=-1;
    char aux[limite];
    printf("%s",msj);
    if (pBuffer!=NULL&&limite>0&&getString(aux,limite)==0){
            retorno=0;
            strncpy(pBuffer,aux,limite);
}
    return retorno;
}

/**
* \brief   modifica un cliente recibiendo su ID
* \param pBuffer Es la cadena que evaluamos
* \param len Es el tamano maximo del string
* \return En caso de exito retorna 0, si no -1
*/

int ModificarclientePorId(Clientes*list, int len,int id )
{
    int retorno = -1;
    int opcion;
    char auxNombre[50];
    char auxApellido[50];
    char auxCuit[11];

    if(list != NULL && len > 0 && len>0 && id >= 0 && id < len )
    {
        if (list[id].isEmpty == 1)
        {
            printf("\n Desea modificar : \n 1-Nombre: \n 2-Apellido: \n 3-Cuit: \n 4 Salir:  \n");
            scanf("%d",&opcion);
            switch(opcion)
            {
                case 1:
                    fflush(stdin);
                if (utn_getNombre(auxNombre, 50, "\n Ingrese nombre :\n", "Nombre Invalido! \n", 2)==0)
                {
                    strncpy(list[id].nombre, auxNombre, 50);
                    printf("\n Se ha modificado el nombre con exito!!\n");
                    break;
                }
                case 2:
                                        fflush(stdin);
                if (utn_getNombre( auxApellido,50, "\n Ingrese apellido: \n","\n Apellido invalido!\n", 2) == 0)
                {
                    strncpy(list[id].apellido, auxApellido, 51);
                    printf("Apellido modicado\n");
                            break;
                }
                break;
                case 3:
                                        fflush(stdin);
                if (utn_getLetrasYNumeros(auxCuit,20, "\n Ingrese Salario:\n")== 0)
                {
                   strncpy(list[id].cuit, auxCuit, 11);
                    printf("\n Se ha modificado el salario con exito!!\n");
                    break;
                }
                case 4:
                                        fflush(stdin);
                   printf("\n Saliendo!! \n");
                   break;
                default :
                printf("Opcion no valida\n");
            }
            retorno = 0;
        }else
        {
            printf("\nEl id ingresado es inexistente!!\n");
        }
            }
return retorno;
}
/**
* \brief    Evalua si es un entero
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 1, si no 0
*/
int isValidEntero(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    if  ((pBuffer != NULL && limite > 0 ) &&
        (pBuffer[0] == '-' || pBuffer[0] == '+' ||
        (pBuffer[0]>='0' && pBuffer[0]<='9')))
    {
        retorno = 1;
        for(i=1;i < limite && pBuffer[i] != '\0';i++)
        {
            if (!(pBuffer[i]>='0' && pBuffer[i]<='9'))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
/**
* \brief   menu de opciones
* \param escanea la opcion ingresada
* \return la opcion indicada por el usuario
*/

int menu(int*opcion)
{
    int aux;
        //system("clear");
        fflush(stdin);
        printf("1- Alta de cliente\n");
        printf("2- Modificar datos de cliente\n");
        printf("3- Baja Cliente\n");
        printf("4-Vender Afiches\n");
        printf("5- Editar Venta\n");
        printf("6- Cobrar Venta \n");
        printf("7- Imprimir Clientes\n");
        printf("9-Salir\n");

        utn_getEntero(&aux,10,"\nIngrese una opcion: ","\nError Ingrese Una Opcion Valida",1,12);
        *opcion=aux;
    return 0;
}

/**
* \brief    evalua el id ingresado y en caso de exito y de haber informacion en ese id
*           borra la informacion
* \param pArray Recibe el array ingresado
* \param id es el numero a buscar
* \param limite Es el tamano maximo del string
*/


int borrarCliente(Clientes* list, int len , int id)
{
    int retorno = -1;


    fflush(stdin);

     if(list != NULL && len > 0  && id >= 0 && list[id].isEmpty == 1)
        {
            list[id].isEmpty=0;
            retorno = 0;
        }
        else
            {
               printf("\n Error, el id ingresado no existe... \n");
            }


return retorno;


 }

 /**
* \brief    Se utiliza esta funcion para obtener un nuevo id
*           declarando una variable static para el id y suma 1 al anterior
* \return devuelve un id nuevo
*/
static int getNextId()
{
    static int ultimoId=-1;
    ultimoId++;
    return ultimoId;
}


