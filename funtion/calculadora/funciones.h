#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#endif // FUNCIONES_H_INCLUDED

int suma(int a,int b);
int resta(int a, int b);
int division(int a, int b);
int producto (int a, int b);
int factorial (int a);

int suma (int a , int b)
{
return a+b;
}
int resta (int a, int b )
{
    return a-b;
}
int division(int a, int b)
{

   return a/b;
}

int producto (int a, int b)
{
    return a*b;
}
int factorial (int a)

{
    int i;
    int resultado=1;
    for (i=2;i<=a;i++)
    {
        resultado =resultado*i;

    }
    return resultado;
}
void calcularTodo(int a, int b)
{

     int z;
     z = suma(a,b);
    printf("el resultado es %d\n",z);

     z = resta(a,b);
                    printf("El resultado es : %d\n",z);


     if (b ==0)
     {
         printf("Error, no se puede dividir por 0 \n");

     }else
     {
           z = division(a,b);

        printf("La division es : %d\n", z);

     }


            z = producto(a,b);
            printf("El producto es : %d\n",z);

            z = factorial(a);
            printf("El factorial es : %d\n",z);

}

