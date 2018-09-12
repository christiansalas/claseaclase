#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



int esSoloLetra(char str[])

{

int i;
int retorno= 1;
int ContadorLetras = strlen(str);


    for ( i =0;i<ContadorLetras;i++)
        {

         if(str[i]!= '\0' && str[i] != ' ' && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
         {


        retorno =0;
        break;
         }


    return retorno;


}
}


char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    if (esSoloLetra(mensaje)==1)
{
printf("El nombre ingresado es correcto");
}

else
{
printf("Ingrese solo caracteres!!");
}
  /*  fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;*/
}





