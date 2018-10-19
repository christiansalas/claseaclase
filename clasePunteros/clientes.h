typedef struct
{
char nombre[50];
char apellido[50];
int iDClientes;

}Cliente;


Cliente * cli_newCliente(void);
int clie_setNombre(Cliente *aux,char* nombre);
int clie_getNombre(Cliente* this, char*nombre);
int clie_buscarLugarVacio(Cliente* array[], int limitearray);
int clie_inicializarArray(Cliente* array[],int limiteArray);
int clie_buscarPorId(Cliente * array[],int limiteArray, int id);
int clie_deleteCliente(Cliente* this);
Cliente* clie_newClienteParametroas(char* nombre,char *apellido,int id);





