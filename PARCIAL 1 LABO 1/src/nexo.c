#include "nexo.h"


int pedPendientesPorCliente(eCliente* vectCliente, int tamCliente, ePedido* vectPedido, int tamPedido)
{
    int numPedidos;
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
        }
        vectCliente[i].cantPedidos = numPedidos;
    }
    return numPedidos;
}

int pedPendientesPorLoc(eCliente* vectCliente, int tamCliente, ePedido* vectPedido, int tamPedido, char localidad[])
{
    int numPedidos;
    int i;
    int j;

    for(i=0; i < tamCliente; i++)
    {
        numPedidos=0;
        for(j=0; j < tamPedido ; j++)
        {
            if((strcmp(vectPedido[j].cliente.localidad.nombreLoc, localidad)==0) && (vectPedido[j].estado == 0))
            {
                numPedidos++;
            }
        }
    }
    return numPedidos;
}

float cantPromPropCliente(eCliente* vectCliente, int tamCliente, ePedido* vectPedido, int tamPedido)
{
    int i;
    int j;

    float cantClientes=0;
    float kilosPP=0;
    float promKilosPP;

    for(i=0; i<tamCliente; i++)
    {
        if(vectCliente[i].isEmpty == 1)
        {
            cantClientes++;
        }
    }
    for(j=0; j<tamPedido; j++)
    {
        if(vectPedido[j].isEmpty == 1)
        {
            kilosPP = vectPedido[j].kilosPP + kilosPP;
        }
    }
    promKilosPP = kilosPP/cantClientes;

    return promKilosPP;
}


void menuReciclado(eCliente* vectCliente, ePedido* vectPedido,
                    char opcionMensaje[], char errorMensaje[],
                    char continueChar, char continueNeg, char continueMensaje[],
                    char promptEmpresa[], char promptDirec[], char promptLoc[], char promptCuit[], char altaExitosa[],
                    char promptIdClnt[], char opcionModificar[], char idInvalido[],
                    char confirmarBaja[], char cancelarBaja[], char bajaExitosa[],
                    char promptIdPed[],char promptKilo[], char promptHDPE[], char promptLDPE[], char promptPP[],
                    char procesarExito[], char procesarError[], char mensajePendLoc[], char mensajePromPP[],
                    char errorNoClnt[], char errorNoPed[])
{
    int opcion;
    int inputId;
    int vectId;

    char auxLoc[TAMSTR];
    int pedidosLoc;

    int flagCliente=0;
    int flagPedido=0;



    char seguir = 's';

    do
    {
        opcion = ingresarEntero(opcionMensaje);
        fflush(stdin);

        switch(opcion)
        {
        case 1://ALTA DEL CLIENTE
            {
                printf(altaExitosa,
                        addCliente(vectCliente, TAMCLNT,
                                nextClienteId(vectCliente, TAMCLNT),
                                promptEmpresa,
                                promptDirec,
                                promptCuit,
                                promptLoc,
                                errorMensaje));
                flagCliente = 1;
                break;
            }
        case 2://MODIFICAR DATOS DEL CLIENTE
        {
            if(flagCliente == 1)
            {
            inputId = ingresarEnteroLim(promptIdClnt, idInvalido, IDBASE, (IDBASE+TAMCLNT));
            vectId = findClienteById(vectCliente, TAMCLNT, inputId);

			while(vectId == -1)
            {
                printf("%s", errorMensaje);
                /*inputId = ingresarEntero(promptIdClnt);
                vectId = findClienteById(vectCliente, TAMCLNT, inputId);*/
            }

            opcion = ingresarEntero(opcionModificar);
            switch(opcion)
			{
				case 1://mod direccion
				    {
					ingresarString(vectCliente[vectId].localidad.direccion, promptDirec, errorMensaje, TAMSTR);
					break;
				    }

				case 2://mod localidad
				    {
					ingresarString(vectCliente[vectId].localidad.nombreLoc, promptLoc, errorMensaje, TAMSTR);
					break;
					}

                default:
                    {
                        printf("%s", errorMensaje);
                        break;
                    }

			}



            }
            else
            {
                printf("%s", errorNoClnt);
            }
            break;
        }

        case 3://BAJA CLIENTE
        {

            if(flagCliente == 1)
            {
                inputId = ingresarEnteroLim(promptIdClnt, idInvalido, IDBASE, (IDBASE+TAMCLNT));
                vectId = findClienteById(vectCliente, TAMCLNT, inputId);
                while(vectId == -1)
                {
                    printf(errorMensaje);
                    inputId = ingresarEnteroLim(promptIdClnt, idInvalido, IDBASE, (IDBASE+TAMCLNT));
                    vectId = findClienteById(vectCliente, TAMCLNT, inputId);
                }

                if(continuarMenu(confirmarBaja, errorMensaje, continueChar, continueNeg)== continueChar)
                {
                    removeCliente(vectCliente, vectId);
                    printf(bajaExitosa);
                }
                else
                {
                    printf("%s",cancelarBaja);
                }

            }
            else
            {
                printf("%s",errorNoClnt);
            }
            break;
        }

        case 4://CREAR PEDIDO
            {
                mostrarVectCliente(vectCliente, TAMCLNT);
                inputId = ingresarEnteroLim(promptIdClnt, idInvalido, IDBASE, (IDBASE+TAMCLNT));
                vectId = findClienteById(vectCliente, TAMCLNT, inputId);

                addPedido(vectPedido,vectCliente,
                          TAMPDD, TAMCLNT,
                          vectId,
                          nextPedidoId(vectPedido, TAMPDD),
                          promptIdPed, promptKilo,
                          errorMensaje);

                mostrarVectPedido(vectPedido, TAMPDD);

                flagPedido=1;

                /*while(vectCliente[vectId].isEmpty != 1)
                {
                    printf(errorMensaje);
                    inputId = ingresarEntero(promptIdMod);
                    vectId = findClienteById(vectCliente, TAMCLNT, inputId);
                }*/

                break;
            }

        case 5://PROCESAR PEDIDOS
            {
                if(flagPedido==1)
                {


                    inputId = ingresarEnteroLim(promptIdPed, idInvalido, IDPDBASE, (IDPDBASE+TAMPDD));
                    vectId = findPedidoById(vectPedido, TAMPDD, inputId);

                    procesarPedido(vectPedido, TAMPDD, vectId,
                                   promptHDPE, promptLDPE, promptPP,
                                   errorMensaje, procesarError, procesarExito);
                }
                else
                {
                    printf("%s",errorNoPed);
                }

                break;
            }
        case 6://IMPRIMIR CLIENTES
            {
                if(flagCliente==1)
                {
                    pedPendientesPorCliente(vectCliente, TAMCLNT, vectPedido, TAMPDD);
                    mostrarVectCliente(vectCliente, TAMCLNT);
                }
                else
                {
                    printf("%s",errorNoClnt);
                }

                break;
            }
        case 7://IMPRIMIR PEDIDOS PENDIENTES
            {
                if(flagPedido==1)
                {
                    imprimirPedPend(vectPedido, TAMPDD);
                }
                else
                {
                    printf("%s",errorNoPed);
                }
                break;
            }
        case 8://IMPRIMIR PEDIDOS PROCESADOS
            {   if(flagPedido == 1)
                {
                    imprimirPedProc(vectPedido, TAMPDD);
                }
                else
                {
                    printf("%s",errorNoPed);
                }
                break;
            }
        case 9://CANT DE PED PEND POR LOCALIDAD
            {
                if(flagPedido == 1)
                {
                    fflush(stdin);
                    ingresarString(auxLoc, promptLoc, errorMensaje, TAMSTR);
                    pedidosLoc = pedPendientesPorLoc(vectCliente, TAMCLNT, vectPedido, TAMPDD, auxLoc);
                    printf(mensajePendLoc, auxLoc, pedidosLoc);
                }
                else
                {
                    printf("%s",errorNoPed);
                }
                break;
            }
        case 10://PROM DE PP POR CLIENTE
            {
                if(flagPedido == 1)
                {
                    printf(mensajePromPP, cantPromPropCliente(vectCliente, TAMCLNT, vectPedido, TAMPDD));
                }
                else
                {
                        printf("%s",errorNoPed);
                }
                break;
            }
        case 11://SALIR
            {
                exit(0);
                break;
            }
        case 12://cliente mas pedidos pendientes
        {
        	printf("el cliente con mas pedidos pendientes es %s\n", vectCliente[clienteMasPedPend(vectCliente, TAMCLNT, vectPedido, TAMPDD)].nombreEmpresa);
        	break;
        }
        case 13://cliente mas pedidos completos
        {
        	printf("el cliente con mas pedidos completos es %s\n", vectCliente[clienteMasPedPend(vectCliente, TAMCLNT, vectPedido, TAMPDD)].nombreEmpresa);
        	break;
        }
        case 14://cliente mas pedidos
        {
        	printf("el cliente con mas pedidos es %s\n", vectCliente[clienteMasPedPend(vectCliente, TAMCLNT, vectPedido, TAMPDD)].nombreEmpresa);
        	break;
        }


        default:
        {
            printf(errorMensaje);
        }

        }

    seguir = continuarMenu(continueMensaje, errorMensaje, continueChar, continueNeg);
    system("cls");
    }while(seguir==continueChar);
}


