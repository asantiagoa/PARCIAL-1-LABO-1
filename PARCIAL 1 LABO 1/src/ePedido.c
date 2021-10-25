#include "nexo.h"

int initPedidos(ePedido* vectPed, int tam)
{
    int i;
    int status = -1;

    for(i=0; i<tam ; i++)
    {
        vectPed[i].isEmpty = 0;
        status = 0;
    }
    return status;
}

int nextPedidoId(ePedido* vectPed, int tam)
{
    int id=0;
    int i;

    for(i=0; i<tam; i++)
    {
        if(vectPed[i].isEmpty == 0)
        {
            id = i + IDPDBASE;
            break;
        }
        else if(vectPed[tam].isEmpty != 0)
        {
            printf("no se pudo obtener un ID");
        }
    }

    return id;
}

int findPedidoById(ePedido* vectPed, int tam, int idPedido)
{
    int index;
    int i;

    for(i = 0; i < tam; i++)
    {
        if(vectPed[i].idPedido == idPedido)
        {
            index = i;
        }
    }
    if(vectPed[index].isEmpty==0)
    {
        index = -1;
    }

    return index;
}

int procesarPedido(ePedido* vectPed, int tam, int idPedido, char promptHDPE[], char promptLDPE[], char promptPP[],char errorMensaje[], char errorKilo[], char mensajeExito[])
{
    int ret;

    vectPed[idPedido].kilosHDPE = ingresarFloatPos(promptHDPE, errorMensaje);
    vectPed[idPedido].kilosLDPE = ingresarFloatPos(promptLDPE, errorMensaje);
    vectPed[idPedido].kilosPP = ingresarFloatPos(promptPP, errorMensaje);


     if((vectPed[idPedido].kilosHDPE + vectPed[idPedido].kilosHDPE + vectPed[idPedido].kilosHDPE) > vectPed[idPedido].kilosTotales)
     {
         printf("%s", errorKilo);
         ret = -1;
     }
     else
     {
         vectPed[idPedido].estado = 1;
         printf(mensajeExito);
         ret = 0;
     }

     return ret;
}

int addPedido(ePedido* vectPed,eCliente* vectCliente, int tamPedido, int tamCliente, int idCliente, int idPedido, char promptIdCliente[], char promptKilo[], char mensajeError[])
{
    int i;
    int ret;


    for(i = 0; i < tamPedido; i++)
    {
        if(vectPed[i].isEmpty == 0)
        {
            vectPed[i].idPedido = idPedido;

            vectPed[i].cliente = vectCliente[idCliente];

            vectPed[i].kilosTotales = ingresarFloatPos(promptKilo, mensajeError);

            vectPed[i].estado = PEND;

            vectPed[i].isEmpty = 1;

            ret = vectPed[i].idPedido;


            break;
        }
        else if(vectPed[tamPedido].isEmpty == 1)
        {
            printf("NO SPACE");
            ret = -1;
        }


    }
    return ret;
}


