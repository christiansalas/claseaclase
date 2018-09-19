#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

typedef struct
{
    char nombre[50];
    char descripcion[200];
    float precio;
    int isEmpty;
    int iD;

}eProducto;

int producto_init(eProducto* arrayProducto, int lenght, int valor);
int producto_alta(eProducto* arrayProducto, int lenght, int indice);
int producto_imprimir(eProducto* arrayProducto, int lenght);

int utn_getNombre(  char* pNombre, int limite, char* msg,
                    char* msgErr, int reintentos);

int producto_indiceLibre(eProducto* arrayProducto, int len );
int producto_indiceId(eProducto* arrayProducto,int len ,int iD);



#endif // UTN_H_INCLUDED
