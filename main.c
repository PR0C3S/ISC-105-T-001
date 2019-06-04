#include <stdio.h>
#include <stdlib.h>
#include "monticulo.h"
///MONTICULOS
int main()
{
   float nuevoValor;
    Monticulo *miHeap;
    miHeap = Inicializar(1);

    do
    {
       printf("\nIngrese un valor, digite (0) para salir: ");
       scanf("%d",&nuevoValor);
    }while(nuevoValor !=0);
    while(!isEmpty(miHeap))
    {
       printf("%.2f\t",Poll(miHeap))
    }
    return 0;
}
