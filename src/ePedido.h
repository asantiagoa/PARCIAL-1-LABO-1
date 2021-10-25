#ifndef EPEDIDO_H_INCLUDED
#define EPEDIDO_H_INCLUDED

#include "nexo.h"

#define TAMPDD 1000
#define HDPE 1
#define LDPE 2
#define PP 3

#define PEND 0
#define COMP 1


typedef struct
{
    int idPedido;
    eCliente cliente;
    int tipo;
    float kilosTotales;
    float kilosHDPE;
    float kilosLDPE;
    float kilosPP;
    int estado;
    int isEmpty;

}ePedido;


int initPedidos(ePedido* vectPed, int tam);
int nextPedidoId(ePedido* vectPedido, int tam);
int findPedidoById(ePedido* vectPed, int tam, int idPedido);
int procesarPedido(ePedido* vectPed, int tam, int idPedido, char promptHDPE[], char promptLDPE[], char promptPP[],char errorMensaje[], char errorKilo[], char mensajeExito[]);
int addPedido(ePedido* vectPed, eCliente* vectCliente, int tamPedido, int tamCliente, int idCliente, int idPedido, char promptIdCliente[], char promptKilo[], char mensajeError[]);



#endif // EPEDIDO_H_INCLUDED
