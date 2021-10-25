#ifndef ECLIENTE_H_INCLUDED
#define ECLIENTE_H_INCLUDED

#include "nexo.h"
#include "eLocalidad.h"

#define TAMCLNT 100
#define TAMSTR 50

typedef struct
{
    int idCliente;
    char nombreEmpresa[TAMSTR];
    eLocalidad localidad;
    int cuit;
    int cantPedidos;
    int isEmpty;

}eCliente;



int addCliente(eCliente* vect, int tam, int idCliente, char promptEmpresa[] , char promptDireccion[] ,char promptCuit[], char promptLoc[], char entradaInvalida[]);
int findClienteById(eCliente* vect, int tam, int idCliente);
int removeCliente(eCliente* vect, int idCliente);



int initClientes(eCliente* vect, int tam);
int nextClienteId(eCliente* vect, int len);




#endif // ECLIENTE_H_INCLUDED
