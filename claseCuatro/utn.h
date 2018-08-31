int utn_getNumero( int *pResultado,
                char mensaje[],

                char  mensajeError[],
                int minimo,
                int maximo,
                int reintentos);


int utn_getChar(char *pResultado,
                char mensaje[],
                char  mensajeError[],
                int minimo,
                int maximo,
                int reintentos);

float utn_getFloat(  float *pResultado,
                char mensaje[],
                char mensajeError[],
                int minimo,
                int maximo,
                int reintentos);

 int utn_getCaracter( int *pResultado,
                    char mensaje[],
                    char  mensajeError[],
                    int minimo,
                    int maximo,
                    int reintentos);

    static int getChar (char* caracterIngresado);
    static  int getString (char* textoIngresado[]);
    static  int getFloat (float* numeroIngresado);
    static  int getInt (int* numeroIngresado);





