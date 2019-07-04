#include <stdlib.h>

#include "pila.h"

const int TAM = 100;

Pila* iniciarpila()
{
   Pila* newpila = (Pila*) malloc(sizeof(Pila));
   newpila->posicionActual=0;
   newpila->Tamano = TAM;
   newpila->Pila= (float *)malloc(TAM * sizeof(float));
   return newpila;
}

void Push(Pila *pila , float elemento)
{
   verificador(pila);
   *(pila->Pila + pila->posicionActual)=elemento;
   pila->posicionActual++;

}

void verificador(Pila* pila)
{
   if(pila->posicionActual+1 < pila->Tamano)
      return;

   pila->Pila= (float*)realloc(pila->Pila, pila->Tamano+TAM);
   pila->Tamano= pila->Tamano+TAM;
}


float Pop(Pila* pila)
{

   if(isEmpty(pila))
   return -1;

   float valor= *(pila->Pila + pila->posicionActual -1 );
   pila->posicionActual--;

   return valor;
}

int SIZE(Pila *pila)
{
   return pila->posicionActual;
}
short isEmpty(Pila* pila)
{
   return pila->posicionActual==0;
}

float Peek(Pila *pila)
{
   float valor= Pop(pila);
   Push(pila,valor);

   return valor;
}
