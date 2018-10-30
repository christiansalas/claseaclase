#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
cc     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int opcionMenu;

    LinkedList* listaEmpleados = ll_newLinkedList();



do{
    printf("\Ingrese una Opcion: \n");
    printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
    printf("\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).");
    printf("\n3. Alta de empleado ");
    printf("\n4. Modificar datos de empleado");
    printf("\n5. Baja de empleado");
    printf("\n6. Listar empleados  ");
    printf("\n7. Ordenar empleados");
    printf("\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto). ");
    printf("\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).");
    printf("\n10. Salir\n");
    scanf("%d",&opcionMenu);

        switch(opcionMenu)
        {
            case 1:
            printf("\nSize de la lista %d", ll_len(listaEmpleados));
                controller_loadFromText("data.csv",listaEmpleados);
            printf("\nSize de la lista %d\n", ll_len(listaEmpleados));
            controller_ListEmployee(listaEmpleados);
            break;

            case 2:
                break;
            case 3:
                if(controller_addEmployee(listaEmpleados)==0)
                {
                    printf("\n Se ha cargado con exito el empleado!! \n");
                }
                break;

            case 4:
                controller_editEmployee(listaEmpleados);
            case 5 :
                if (controller_removeEmployee(listaEmpleados)==0)
                {
                    printf("\n Empleado Borrado con exito!!\n");
                }
                break;
            case 6 :
                break;
            case 7:
                break;
            case 8:
                break;
            case 9 :
                break;
            case 10:
                    printf("\Saliendo! \n");
            default:
                    printf("\nOpcion no Valida!!!\n");

        }
    }while(opcionMenu!= 10);
    return 0;
}
