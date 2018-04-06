int getInt(char*mensaje, char*error, int reintentos, int minimo, int maximo, int* resultado)
{
        int DatoRequerido;
        int retorno =-1;

    do
   {
      reintentos--;
   printf("%s",mensaje);
   scanf("%s",&DatoRequerido);
   if(DatoRequerido>minimo && DatoRequerido< maximo)
   {
       retorno = 0;
   }
   else if (DatoRequerido<minimo  )
   {
      retorno = -1;
   }
    else
    {
        retorno = -2;
    }
    printf("%d",error);

   }while (reintentos >= 0  );
   return retorno;

}


int mostrarArrayInt(int*array, int cantidad)
{


int i;
int retorno = -1;

 if (cantidad > 0)
 {
     retorno = 0;
     for (i = 0 ; i < cantidad; i++)
     {
         printf("/n%D", array[i]);
     }
 }

return retorno;

}
