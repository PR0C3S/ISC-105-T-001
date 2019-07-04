#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
   nodo *pila;
    float nuevo=0;

    Pilita= iniciarpila(Pilita);

    do
    {
       printf("Ingrese un valor (-1 para salir): ");
       scanf("%f",&nuevo);

      Push(Pilita, nuevo);
    }while(nuevo>=0);

    while(!isEmpty(Pilita))
    {
      nuevo= Pop(Pilita);
      printf("%.f  ",nuevo);
    }

   return 0;
}
