#include <stdio.h>
#include <stdlib.h>
#include "utn.h"



static  int getInt (int* numeroIngresado)
{
fflush(stdin);
  return scanf("%d",numeroIngresado);

}


static int getChar (char* caracterIngresado)
{
fflush(stdin);
return scanf("%c",caracterIngresado);
}


static  int getString (char* textoIngresado[])
{
fflush(stdin);
  return scanf("%s",textoIngresado);
}

static  int getFloat (float* numeroIngresado)
{
fflush(stdin);
  return scanf("%f",numeroIngresado);

}
/*
*\ brief solicita un numero al usuario valida y devuelve un resultado.
*\param presultado puntero a la variable resultado.
*\param mensaje es el mensaje a ser mostrado.
*\param mensaje de error.
*\param minimo es el numero minimo aceptado.
*\param maximo es el numero maximo aceptado.
*\param reintentos es la cantida de reintentos permitidos.
*\ return retorna 0 si esta correcto o -º si es incorrecto.
*/

