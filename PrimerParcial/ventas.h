

typedef struct{

int IdCliente;
int afiches;
char nombreAfiche[50];
char zonaPegarAfiche[50];
int isEmptyVentas;
int IdVentas;
char estadoVenta[50];
}Ventas;


void imprimirVentas(Ventas * list,int limite);
int altaVenta(Ventas* list, int len, int idCLiente);
int ModificarVentasPorId(Ventas* list, int len,int id );
int inicializarVentas(Ventas* pBuffer,int limite);
int  imprimirVentaDeCliente(Ventas *list,Clientes *listcliente, int lenventa ,int lenclientes,int id);
 int ImprimirClientes(Clientes *listClientes,int limiteClientes,Ventas * listVentas,int limiteVentas );
/**
* \brief    Se utiliza esta funcion para obtener un nuevo id
*           declarando una variable static para el id y suma 1 al anterior
* \return devuelve un id nuevo
*/
static int getNextId();







