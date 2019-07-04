#include <stdlib.h>

#ifndef _Pila
#define _Pila

typedef struct{

int Tamano;
float *Pila;
int posicionActual;

}Pila;

Pila* iniciarpila();
void Push(Pila*, float);
void verificador(Pila*);
float Pop(Pila*);
short isEmpty(Pila*);
int SIZE(Pila*);
float Peek(Pila*);
#endif // _Pila
