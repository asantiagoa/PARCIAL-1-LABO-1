#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "nexo.h"
#include "funciones.h"

int ingresarEntero(char mensaje[])
{
    int numero;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%d", &numero);

    return numero;

}

int ingresarEnteroLim(char mensaje[], char mensajeError[], int numMin, int numMax)
{
    int numero;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%d", &numero);
    while(numero > numMax || numero < numMin)
    {
        printf("%s", mensajeError);
        fflush(stdin);
        scanf("%d", &numero);
    }


    return numero;
}


int verifPar(int num)
{
    int par = 0;//0 es impar 1 es par

    if(num%2 == 0)
    {
        par = 1;
    }
    return par;
}


int verifPos(int num)
{
    int pos = 0;//0 es neg 1 es pos

    if(num >= 0)
    {
        pos = 1;
    }
    return pos;
}

float ingresarFloat(char mensaje[])
{
    float numero;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%f", &numero);

    return numero;
}

float ingresarFloatPos(char mensaje[], char mensajeError[])
{
    float numero;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%f", &numero);
    while(verifPos(numero)==0)
    {
        printf("%s %s", mensajeError, mensaje);
        fflush(stdin);
        scanf("%f", &numero);
    }

    return numero;
}


float ingresarFloatLim(char mensaje[], float numMin, float numMax)
{
        float numero;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%f", &numero);
    while(numero > numMax || numero < numMin)
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%f", &numero);
    }


    return numero;
}

char ingresarChar(char mensaje[])
{
    char carac;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &carac);

    return carac;
}

char continuarMenu(char mensaje[], char mensajeError[],char op1, char op2)
{
    char carac;

    carac = ingresarChar(mensaje);

    while(carac != op1 && carac != op2)
    {
        printf("%s", mensajeError);
        carac = ingresarChar(mensaje);
    }

    return carac;
}

int ingresarString(char cadena[], char mensaje[], char mensajeError[], int tam)
{
    char auxiliarString[1000];
    int retorno;
    retorno = 0;
    if(cadena!=NULL && mensaje != NULL)
    {
        retorno = 1;
        printf(mensaje);
        fflush(stdin);
        gets(auxiliarString);
        while(strlen(auxiliarString)> tam)
        {
            printf(mensajeError);
            fflush(stdin);
            gets(auxiliarString);
        }
        strcpy(cadena, auxiliarString);
    }
    return retorno;
}

void iniciaVectInt(int vect[], int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        vect[i]=0;
    }
}

void ingresarVectInt(char mensaje[], int vect[], int tam)
{
       int i;
    	for(i=0; i<tam; i++)
	{
		printf("%s (%d)", mensaje, i);
		fflush(stdin);
		scanf("%d", &vect[i]);
	}
}

int IngresarVectIntLim(char mensaje[], char error[], int vect[], int tam, int numMax, int numMin)
{
    int i;
    	for(i=0; i<tam; i++)
	{
		printf("%s (%d)", mensaje, i);
		fflush(stdin);
		scanf("%d", &vect[i]);
		while(vect[i] < numMin || vect[i] > numMax)
        {
            printf("%s (%d)", error, i);
            fflush(stdin);
            scanf("%d", &vect[i]);
        }
	}

	return 0;
}

void cargaAleatoriaVectInt(int vect[], int tam)
{
    int pos;
    char cont;

    do
    {
    printf("ingrese posicion: ");
    scanf("%d",&pos);
    printf("ingrese valor a cargar en la pos %d: ", pos);
    scanf("%d",&vect[pos]);
    while(vect[pos]==0)
    {
        printf("numero invalido, ingrese numero distinto a 0: ");
        fflush(stdin);
        scanf("%d",&vect[pos]);
    }
    printf("continuar ingresando? s/n?");
    fflush(stdin);
    scanf("%c",&cont);
    }while(cont=='s');
}

void listarVectInt(int vect[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
	{
		printf("%d ", vect[i]);
	}
}


