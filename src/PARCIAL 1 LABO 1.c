#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "nexo.h"




int main()
{

    setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

    eCliente vectCliente[TAMCLNT];
    ePedido vectPedido[TAMPDD];

    initClientes(vectCliente, TAMCLNT);
    initPedidos(vectPedido, TAMPDD);

    menuReciclado(vectCliente, vectPedido,
                  "-------------MENU------------\nIngrese Opcion:\n1-ALTA CLIENTE      2-MODIFICAR CLIENTE     3-BAJA CLIENTE\n4-CREAR PEDIDO      5-PROCESAR RESIDUOS     6-IMPRIMIR CLIENTES\n7-IMPRIMIR PEDIDOS PENDIENTES\n8-IMPRIMIR PEDIDOS PROCESADOS\n9-IMPRIMIR PEDIDOS PENDIENTES POR LOCALIDAD\n10-CANT KILOS PROP\n11-SALIR 12-A 13-B 14-C\n",
                  "error. entrada invalida\n",
                  's', 'n',"desea continuar?",
                  "ingrese nombre empresa: ", "ingrese direccion: ","ingrese localidad: ", "ingrese cuit: ","se ha creado un cliente con id %d\n",
                   "ingrese id del cliente: ",
                  "\nIngrese opcion:     \n1-Modificar Direccion    2-Modificar Localidad\n", "Error, ID invalido. Ingrese Nuevamente: ",
                  "desea dar de baja al cliente? s/n: ", "la baja fue cancelada.", "El cliente ha sido dado de baja\n",
                  "ingrese ID del pedido: ","Ingrese Cant. de kilos: " ,"ingrese kilos HDPE: ", "ingrese kilos LDPE: ", "ingrese kilos PP: ",
                  "El pedido se ha procesado exitosamente\n", "Error al procesar el pedido", "la localidad %s tiene %d pedidos pendientes.\n",
                  "el promedio de kilos de PP por cliente es %.2f\n",
                  "Error. primero debe ingresar un cliente\n", "Error. primero debe ingresar un pedido\n");

    return 0;
}
