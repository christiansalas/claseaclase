#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *    10. Salir

 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno = -1;
    pArchivo = fopen(path,"r");
    if(!parser_EmployeeFromText(pArchivo, pArrayListEmployee))
    {
        retorno = 0;
    }
    fclose(pArchivo);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    char auxNombre[128];
    int auxHorasTrabajadas;
    float auxSueldo;
    int auxId;

    Employee* nuevoEmpleado;

    if(pArrayListEmployee!= NULL)
        {
           nuevoEmpleado= Employee_new();
           if(nuevoEmpleado!= NULL && utn_getNombre(auxNombre,128,"\nIngrese nombre\n","\n Nombre Incorrecto\n",2)== 0
              &&utn_getEntero(&auxHorasTrabajadas,9,"\n Ingrese cantidad de horas trabajadas\n","\n Error, ingrese un numero\n",2)==0
              &&utn_getEntero(&auxSueldo,10,"Ingrese Sueldo \n", "Error, ingrese un sueldo valido \n",2)==0 )
           {
                auxId=getNextId(pArrayListEmployee);
                Employee_setId(nuevoEmpleado,auxId);
                Employee_setNombre(nuevoEmpleado,auxNombre);
                Employee_setHorasTrabajadas(nuevoEmpleado,auxHorasTrabajadas);
                Employee_setSueldo(nuevoEmpleado,auxSueldo);
                ll_add(pArrayListEmployee,nuevoEmpleado);
                retorno = 0;
           }
        }


    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
int retorno = -1;
int id;
        if (pArrayListEmployee != NULL
            &&
            utn_getEntero(&id, 10, "Ingrese id", "id invalido", 3) == 0
            &&
            Employee_BuscarPorId (pArrayListEmployee, id)== 0)
            {
                printf("Empleado modificado\n");
            }

        return retorno;
}
/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    int id;
    int bufferId;
    Employee * auxPunteroEmpleado;
    if (pArrayListEmployee != NULL &&
        utn_getEntero(&id, 10, "Ingrese Id\n", "Id invalido", 3) == 0)
    {
        for (i = 1; i< ll_len(pArrayListEmployee); i++)
        {
            auxPunteroEmpleado = ll_get(pArrayListEmployee,i);
            Employee_getId(auxPunteroEmpleado,&bufferId);
            if(bufferId == id)
            {
             Employee_delete(auxPunteroEmpleado);
             retorno = 0;
             break;
            }
        }

    }
    return retorno;
}
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    Employee* auxPunteroEmpleado;
    char nombre[1024];
    int id;
    int bufferHorasTrabajo;
    int bufferSueldo;
    if(pArrayListEmployee != NULL)
    {
        for (i = 0; i< ll_len(pArrayListEmployee); i++)
        {
             auxPunteroEmpleado = ll_get(pArrayListEmployee,i);
             Employee_getNombre(auxPunteroEmpleado,nombre);
             Employee_getId(auxPunteroEmpleado, &id);
             Employee_getHorasTrabajadas(auxPunteroEmpleado, &bufferHorasTrabajo);
             Employee_getSueldo(auxPunteroEmpleado, &bufferSueldo);
             printf("\nId %d - Nombre: %s - Horas: %d - Sueldo: %d \n",id, nombre, bufferHorasTrabajo, bufferSueldo);
             retorno = 0;
        }
    }

    return retorno;
}
/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

