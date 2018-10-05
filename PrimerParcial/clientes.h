


typedef struct{

char nombre [50];
char apellido[50];
char cuit[20];
int isEmpty;
int idClientes;
}Clientes;






int inicializarCliente(Clientes* pBuffer,int limite);
int altaCliente(Clientes* list, int len);
int utn_getString(char *pBuffer, int limite);

int utn_getNombre(  char* pNombre, int limite, char* msg,
                    char* msgErr, int reintentos);

int getString(char* pBuffer, int limite);
 int isValidNombre(char* pBuffer,int limite);

 int utn_getLetrasYNumeros(char* pBuffer,int limite,char* msj);
 int isValidEntero(char *pBuffer, int limite);

 int menu(int*opcion);
 int ModificarclientePorId(Clientes*list, int len,int id );
 int borrarCliente(Clientes* list, int len , int id);










