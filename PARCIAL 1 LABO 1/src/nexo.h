#ifndef NEXO_H_INCLUDED
#define NEXO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "eCliente.h"
#include "ePedido.h"
#include "eLocalidad.h"
#include "funciones.h"
#include "informes.h"

#define TAMSTR 50

#define IDBASE 1000
#define IDPDBASE 5000



int pedPendientesPorCliente(eCliente* vectCliente, int tamCliente, ePedido* vectPedido, int tamPedido);
int pedPendientesPorLoc(eCliente* vectCliente, int tamCliente, ePedido* vectPedido, int tamPedido, char localidad[]);

void menuReciclado(eCliente* vectCliente, ePedido* vectPedido,
                    char opcionMensaje[], char errorMensaje[],
                    char continueChar, char continueNeg, char continueMensaje[],
                    char promptEmpresa[], char promptDirec[], char promptLoc[], char promptCuit[], char altaExitosa[],
                    char promptIdClnt[], char opcionModificar[], char idInvalido[],
                    char confirmarBaja[], char cancelarBaja[], char bajaExitosa[],
                    char promptIdPed[],char promptKilo[], char promptHDPE[], char promptLDPE[], char promptPP[],
                    char procesarExito[], char procesarError[], char mensajePendLoc[], char mensajePromPP[],
                    char errorNoClnt[], char errorNoPed[]);





#endif // NEXO_H_INCLUDED
