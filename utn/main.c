#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    int numeroOculto;
    int numeroIngresado;
    char teclaIngresada;
    int jugar;

    teclaIngresada = 's';
    while (teclaIngresada == 's')
    {
        numeroOculto = getNumeroAleatorio(1,100,1);
        //printf("%d\n",numeroOculto );

        jugar = 1;
        while(jugar == 1)
        {
            numeroOculto = getInt("Ingrese un numero (0 - 99) \n");
            if(numeroIngresado < 0)
            {
                jugar = 0;
            }
            else if(numeroIngresado == numeroOculto)
            {
                printf("FELICITACIONES GANASTE!!! \n");
                jugar = 0;
            }
            else if(numeroIngresado > numeroOculto)
            {
                printf("EL NUMERO QUE INGRESASTE ES GRANDE!!! \n");
            }
            else if(numeroIngresado < numeroOculto)
            {
                printf("EL NUMERO QUE INGRESASTE ES CHICO!!! \n");
            }
        }

        teclaIngresada = getChar("Desea jugar nuevamente? (s/n)\n");

    }

    return 0;
}
