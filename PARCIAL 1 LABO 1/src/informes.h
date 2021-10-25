#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "nexo.h"


int mostrarCliente(eCliente cliente);
int mostrarVectCliente(eCliente* vect, int tam);

int mostrarPedido(ePedido pedido);
int mostrarVectPedido(ePedido* vect, int tam);
void imprimirPedPend(ePedido* vect, int tam);
void imprimirPedProc(ePedido* vect, int tam);
int clienteMasPedPend(eCliente vectCliente[], int tamCliente, ePedido vectPedido[], int tamPedido);
int clienteMasPedComp(eCliente vectCliente[], int tamCliente, ePedido vectPedido[], int tamPedido);
int clienteMasPed(eCliente vectCliente[], int tamCliente, ePedido vectPedido[], int tamPedido);

#endif // INFORMES_H_INCLUDED
