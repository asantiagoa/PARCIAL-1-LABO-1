#include "informes.h"

int mostrarCliente(eCliente cliente)
{
        if(cliente.isEmpty == 1)
        {
            printf("%d  %14s    %14s  %16.2d  %16s %16d\n", cliente.idCliente, cliente.nombreEmpresa, cliente.localidad.direccion, cliente.cuit, cliente.localidad.nombreLoc, cliente.cantPedidos);
            fflush(stdin);
        }
        return 0;
}

int mostrarVectCliente(eCliente* vect, int tam)
{
    int i;
    printf("ID              NOMBRE          DIRECCION       CUIT          LOCALIDAD       PEDIDOS PENDIENTES\n");

    for(i = 0; i < tam; i++)
    {
        mostrarCliente(vect[i]);
    }

    return 0;
}

int mostrarPedido(ePedido pedido)
{
    if(pedido.isEmpty == 1)
    {
        printf("%d  %14s %14d %16.2f/%2.f/%.2f/%.2f %16d\n", pedido.idPedido, pedido.cliente.nombreEmpresa, pedido.tipo, pedido.kilosTotales, pedido.kilosHDPE, pedido.kilosLDPE, pedido.kilosPP, pedido.estado);
        fflush(stdin);
    }

    return 0;
}

int mostrarVectPedido(ePedido* vect, int tam)
{
    int i;

    printf("ID              CLIENTE          TIPO        KILOGRAMOS(TOTALES/HDPE/LDPE/PP)          ESTADO\n");

    for(i = 0; i < tam; i++)
    {
        mostrarPedido(vect[i]);
    }

    return 0;
}

void imprimirPedPend(ePedido* vect, int tam)
{
    int i;
    printf("CUIT CLIENTE        DIRECCION CLIENTE       CANTIDAD KG\n");
    for(i = 0; i < tam; i++)
    {

        if(vect[i].isEmpty == 1&& vect[i].estado == 0)
        {
            printf("%d                  %s                  %.2f\n", vect[i].cliente.cuit, vect[i].cliente.localidad.direccion, vect[i].kilosTotales);
            fflush(stdin);
        }
    }
}

void imprimirPedProc(ePedido* vect, int tam)
{
    int i;
    printf("CUIT CLIENTE        DIRECCION CLIENTE       CANTIDAD KG PROCESADOS(HDPE/LDPE/PP)\n");
    for(i = 0; i < tam; i++)
    {

        if(vect[i].isEmpty == 1&& vect[i].estado == 1)
        {
            printf("%d                  %s                  %.2f/%.2f/%.2f\n", vect[i].cliente.cuit, vect[i].cliente.localidad.direccion, vect[i].kilosHDPE, vect[i].kilosLDPE, vect[i].kilosPP);
            fflush(stdin);
        }
    }
}

int clienteMasPedPend(eCliente vectCliente[], int tamCliente, ePedido vectPedido[], int tamPedido)
{
	int idMP;
    int numPedidos;
    //int aux;
    int flag=0;
    int i;
    int j;

    for(i=0; i < tamCliente; i++)
    {
        numPedidos=0;
        for(j=0; j < tamPedido ; j++)
        {
            if(vectPedido[j].cliente.idCliente == vectCliente[i].idCliente && vectPedido[j].estado == 0)
            {
                numPedidos++;
            }
			vectCliente[i].cantPedidos = numPedidos;
        }

        if(flag == 0 || vectCliente[i].cantPedidos>vectCliente[idMP].cantPedidos)
		{
        	idMP=i;
        	flag = 1;
		}
    }
    return vectCliente[idMP].idCliente;
}

int clienteMasPedComp(eCliente vectCliente[], int tamCliente, ePedido vectPedido[], int tamPedido)
{
	int idMP;
    int numPedidos;
    //int aux;
    int flag=0;
    int i;
    int j;

    for(i=0; i < tamCliente; i++)
    {
        numPedidos=0;
        for(j=0; j < tamPedido ; j++)
        {
            if(vectPedido[j].cliente.idCliente == vectCliente[i].idCliente && vectPedido[j].estado == 1)
            {
                numPedidos++;
            }
			vectCliente[i].cantPedidos = numPedidos;
        }

        if(flag == 0 || vectCliente[i].cantPedidos > vectCliente[idMP].cantPedidos)
		{
        	idMP= i;
        	flag = 1;
		}
    }
    return vectCliente[idMP].idCliente;
}

int clienteMasPed(eCliente vectCliente[], int tamCliente, ePedido vectPedido[], int tamPedido)
{
	int idMP;
    int numPedidos;
    //int aux;
    int flag=0;
    int i;
    int j;

    for(i=0; i < tamCliente; i++)
    {
        numPedidos=0;
        for(j=0; j < tamPedido ; j++)
        {
            if(vectPedido[j].cliente.idCliente == vectCliente[i].idCliente)
            {
                numPedidos++;
            }
			vectCliente[i].cantPedidos = numPedidos;
        }

        if(flag == 0 || vectCliente[i].cantPedidos>vectCliente[idMP].cantPedidos)
		{
        	idMP=i;
        	flag = 1;
		}
    }
    return vectCliente[idMP].idCliente;
}
