

typedef struct{

int IdCliente;
int afiches;
char nombreAfiche[50];
char zonaPegarAfiche[50];
int isEmptyVentas;
int IdVentas;
char estadoVenta[50];
}Ventas;


//void imprimirVentas(Ventas * list,int limite);
int altaVenta(Ventas* list, int len, int idCLiente);
int ModificarVentasPorId(Ventas* list, int len,int id );
int inicializarVentas(Ventas* pBuffer,int limite);
int  imprimirVentaDeCliente(Ventas *list,Clientes *listcliente, int lenventa ,int lenclientes,int id);
 int ImprimirClientes(Clientes *listClientes,int limiteClientes,Ventas * listVentas,int limiteVentas );


static int getNextId();
//static int ventas_buscarIndiceVacio(Ventas* pBuffer,int limite,int*indice);
int ventas_ingresoForzado(Ventas* listVentas, int lenVentas,int idCliente, int afiches, char *nombreAfiche, char* zonaPegarAfiche, char* estadoVenta);

static int getLugarLibreVenta(Ventas* arrayVentas, int lenVentas);
venta_ById(Ventas* listVentas, int lenVentas, int id);
venta_getByIdCliente(Ventas *arrayVentas, int lenVentas, int idCliente);
int venta_imprimir(Ventas* arrayVentas, int lenVentas);













