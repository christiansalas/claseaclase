
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/**
 * \brief funcion que  valida ,que el usuario ingrese solo caracteres
 * \param recibe el dato ingresado por el usuario.-
 * \return 1 si res corecto 0 si no lo es.-
 *
 */

int getValidarLetras (char* pArray)
{
	int retorno = 0;
	int i;
	int auxTamanio = strlen(pArray);


	while(retorno ==0)
    {


	if(pArray != NULL && auxTamanio > 0)
	{
		for(i=0; i<auxTamanio; i++)
		{

			if (scanf("%c", &pArray[i]) == 1 && pArray[i]>= 'a' && pArray[i]<= 'z' )
			{
				retorno = 1;
				break;
			}else
			{
			    	printf("\nNo es un caracter, reeingrese \n");

				retorno = 0;



			}

		}
	}
	 }
	return retorno;
}

/**
 * \brief Solicita un dato de tipo char  al usuario y lo valida a traves de la funcion getValidarNombre
 * \param mensaje  de error si es incorrecto y pide el reeingreso o muestra el nombre si es correcto
 * \return El dato ingresado por el usuario.
 */

void getChar(char* pArray)
{
	printf("Ingrese un nombre\n");
	if (getValidarLetras(pArray) == 1)
	{
	    printf("  Usted ingreso un nombre valido\n");
	}
}

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat(char mensaje[])
{


/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char mensaje[])
{
/*
* \brief Genera un número aleatorio
 * \param desde Número aleatorio mínimo
 * \param hasta Número aleatorio máximo
 * \param iniciar Indica si se trata del primer número solicitado 1 indica que si
 * \return retorna el número aleatorio generado
 *
 */
char getNumeroAleatorio(int desde , int hasta, int iniciar)
{

    /**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumerico(char str[])
{

 /**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[])
{


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}
