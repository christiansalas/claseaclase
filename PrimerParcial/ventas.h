

typedef struct{

char IdCliente[50];
char afiches[50];
char nombreAfiche[50];
char zonaPegarAfiche[50];
int isEmptyVentas;
int iD;
int IdVentas;
}Ventas;


int imprimirVentas(Ventas* pBuffer,int limite);
int altaVenta(Ventas* list, int len);
int ModificarVentasPorId(Ventas* list, int len,int id );
int inicializarVentas(Ventas* pBuffer,int limite);





