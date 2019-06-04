#include <stdlib.h>

#ifndef _Monticuloh
#define _Monticuloh

typedef struct
{
   int tamano;
   int posicionActual;
   int altura;
   short esMin;
   float *elementos;
}Monticulo;

Monticulo* Inicializar(short esMin);
void VerificiarEspacio(Monticulo *heap);
void Insertar(Monticulo *heap, float elementos);
float GetTop(Monticulo *heap);
float Poll(Monticulo *heap);
void HeapifyUp(Monticulo *heap, int indice);
void HeapifyDown(Monticulo *heap, int indice);
int IndicePadre(int indice);
int IndiceHijoIzquierdo(Monticulo * heap, int indice);
int IndiceHijoDerecho(Monticulo * heap, int indice);
void Swap(float* desde, float* hasta);

#endif // _Monticuloh
