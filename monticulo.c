#include<stdlib.h>
#include<math.h>
#include "monticulo.h"

const int ALTURA=10;

Monticulo* Inicializar(short esMin)
{
   Monticulo *nuevoHeap = (Monticulo*) malloc(sizeof(Monticulo));
   nuevoHeap->tamano= pow(2,ALTURA)-1;
   nuevoHeap->posicionActual=0;
   nuevoHeap->altura=ALTURA;
   nuevoHeap->esMin= esMin;
   nuevoHeap->elementos = (float*)calloc(nuevoHeap->tamano,sizeof(float));
   return nuevoHeap;
}

void VerificiarEspacio(Monticulo *heap)
{
   if(heap->posicionActual < heap->tamano)
   {
      return;
   }
   heap->altura++;
   heap->tamano= pow(2, heap->altura);
   heap->elementos= (float*)realloc(heap->elementos, heap->tamano);
}

void Insertar(Monticulo *heap, float elementos)
{
   VerificiarEspacio(heap);
   *(heap->elementos+heap->posicionActual)= elementos;
   heap->posicionActual++;
   HeapifyUp(heap, heap->posicionActual-1);
}

void HeapifyUp(Monticulo *heap, int indice)
{
   /// axiomas;
   if( indice ==0)
   {
      return;
   }

   int indicePadre= IndicePadre(indice);

   if(heap->esMin && *(heap->elementos+indicePadre) < *(heap->elementos+indice))
   {
      return;
   }

   if(!heap->esMin && *(heap->elementos+indicePadre) > *(heap->elementos+indice))
   {
      return;
   }

   /// Cuerpo;
   Swap(heap->elementos+indicePadre, heap->elementos+indice);

   /// Llamada recursiva con cambios;
   HeapifyUp(heap, indicePadre);
}

int IndicePadre(int indice)
{
   int result = (indice-1)/2;
   return result <0 ? 0 : result;
}
int IndiceHijoIzquierdo(Monticulo *heap, int indice)
{
   int result = (indice*2)+1;

   return result < heap->posicionActual ? result: -1;
}
int IndiceHijoDerecho(Monticulo * heap, int indice)
{
   int result = (indice*2)+2;
   return result < heap->posicionActual ? result: -1;
}

void Swap(float* desde, float* hasta)
{
   float burbuja;
   burbuja= *desde;
   *desde = *hasta;
   *hasta= burbuja;
}

float GetTop(Monticulo *heap)
{
   return *(heap->elementos);
}

void HeapifyDown(Monticulo *heap, int indice)
{
   int indiceMenor= IndiceHijoIzquierdo(heap, indice);
   int indiceDerecho= IndiceHijoDerecho(heap, indice);

   /// Primer axiomas (tanto de min como de max heaps)
   if(indiceMenor< 0)
   {
      return;
   }
   /// Evaluando indice menor con Min heaps
   if( heap->esMin && indice>=0 && *(heap->elementos+indiceMenor) < *(heap->elementos+indiceDerecho))
   {
      indiceMenor= indiceDerecho;}
      /// segundo axioma para el Min heaps
      if (heap->esMin && *(heap->elementos+indice) < *(heap->elementos+indiceMenor));
      {
         return;
      }

        /// Evaluando indice menor con Max heaps
   if( !heap->esMin && indice>=0 && *(heap->elementos+indiceMenor) > *(heap->elementos+indiceDerecho))
   {
      indiceMenor= indiceDerecho;}
      /// Segundo axioma para el Max heaps
     if (!heap->esMin && *(heap->elementos+indice) > *(heap->elementos+indiceMenor));
      {
         return;
      }

      Swap(heap->elementos+indice, heap->elementos+indiceMenor);
      HeapifyDown(heap, indiceMenor);

}
float Poll(Monticulo *heap)
{
   if (heap->posicionActual ==0)
   {
      return *heap->elementos;
   }

   float raiz = GetTop(heap);
   Swap(heap->elementos, heap->elementos+(heap->posicionActual-1));
   heap->posicionActual--;
   HeapifyDown(heap, 0);

   return raiz;
}

