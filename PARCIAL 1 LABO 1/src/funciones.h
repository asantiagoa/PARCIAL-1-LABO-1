#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


int ingresarEntero(char mensaje[]);//pide un entero
int ingresarEnteroLim(char mensaje[], char mensajeError[], int numMin, int numMax);//pide un entero dentro de un rango determinado
int verifPar(int num);//verifica la paridad de un entero, devuelve 0 si es impar y 1 si es par
int verifPos(int num);//verifica el signo de un entero, devuelve 0 si es negativo y 1 si es positivo

float ingresarFloat(char mensaje[]);//pide un flotante
float ingresarFloatLim(char mensaje[], float numMin, float numMax);//pide un flotante dentro de un rango determinado
float ingresarFloatPos(char mensaje[], char mensajeError[]);

char ingresarChar(char mensaje[]);//pide un char
char continuarMenu(char mensaje[], char mensajeError[], char op1, char op2);
int ingresarString(char cadena[], char mensaje[], char mensajeError[], int tam);// pide una cadena de caracteres con un limite de tamaño

void ingresarVectInt(char mensaje[], int vect[], int tam);//pide el ingreso de enteros hasta llenar el vector
int ingresarVectIntLim(char mensaje[],char error[], int vect[], int tam, int numMin, int numMax);//pide enteros dentro de un rango hasta llenar el vector
void cargaAleatoriaVectInt(int vect[], int tam);//permite cargar un vector de enteros en la posicion que el usuario elija, la cantidad de veces que el mismo desee
void iniciaVectInt(int vect[], int tam);//inicializa un vector de enteros en 0
void listarVectInt(int vect[], int tam);//lista todo un vector de enteros



#endif // FUNCIONES_H_INCLUDED
