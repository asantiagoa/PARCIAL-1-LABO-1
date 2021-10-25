#include "nexo.h"



int initClientes(eCliente* vect, int tam)
{
    int i;
    int status = -1;

    for(i=0; i<tam ; i++)
    {
        vect[i].isEmpty = 0;
        vect[i].cantPedidos = 0;
        status = 0;
    }
     //printf("clientes inicializados");
    return status;
}


int nextClienteId(eCliente* vect, int tam)
{
    int id=0;
    int i;

    for(i=0; i<tam; i++)
    {
        if(vect[i].isEmpty == 0)
        {
            id = i + IDBASE;
            break;
        }
        else if(vect[tam].isEmpty == 1)
        {
            printf("no se pudo obtener un ID");
        }
    }

    return id;
}

int findClienteById(eCliente* vect, int tam, int idCliente)
{
    int index;
    int i;

    for(i = 0; i < tam; i++)
    {
        if(vect[i].idCliente == idCliente)
        {
            index = i;
        }
    }
    if(vect[index].isEmpty==0)
    {
        index = -1;
    }

    return index;
}

int removeCliente(eCliente* vect, int idCliente)
{
    int ret = 0;

    if(idCliente == -1)
    {
        ret = -1;
    }
    else
    {
        vect[idCliente].isEmpty = 0;
    }

    return ret;
}


int addCliente(eCliente* vect, int tam, int idCliente, char promptEmpresa[] , char promptDireccion[] ,char promptCuit[], char promptLoc[], char entradaInvalida[])
{
    int i;
    int ret;

    char auxEmpresa[TAMSTR];
    char auxDir[TAMSTR];
    char auxLoc[TAMSTR];

    for(i = 0; i < tam; i++)
    {
        if(vect[i].isEmpty == 0)
        {
            vect[i].idCliente = idCliente;

            ingresarString(auxEmpresa, promptEmpresa, entradaInvalida, TAMSTR);
            strcpy(vect[i].nombreEmpresa, auxEmpresa);

            ingresarString(auxDir, promptDireccion, entradaInvalida, TAMSTR);
            strcpy(vect[i].localidad.direccion, auxDir);

            vect[i].cuit = ingresarEntero(promptCuit);

            ingresarString(auxLoc, promptLoc, entradaInvalida, TAMSTR);
            strcpy(vect[i].localidad.nombreLoc, auxLoc);

            vect[i].isEmpty = 1;

            ret = vect[i].idCliente;

            break;
        }
        else if(vect[tam].isEmpty == 1)
        {
            printf("NO SPACE");
            ret = -1;
        }


    }
    return ret;
}

