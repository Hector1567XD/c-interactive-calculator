#include "pila.h"

#include <stdio.h>
#include <stdlib.h>

Nodo* CrearNodo(int value)
{
    Nodo* nodo = (Nodo *) malloc(sizeof(Nodo));
    nodo->value = value;
    nodo->siguiente = NULL;
    return nodo;
}

Pila* CrearPila()
{
    Pila* pila = (Pila *) malloc(sizeof(Pila));
    pila->cima = NULL;
    return pila;
}

void DestruirNodo(Nodo* nodo)
{
    nodo->siguiente = NULL;
    free(nodo);
}

void Apilar(Pila* pila, int value) {
    Nodo* nodo = CrearNodo(value);
    nodo->siguiente = pila->cima;
    pila->cima = nodo;
}

void Desapilar(Pila* pila) {
    if (pila->cima != NULL) {
        Nodo* eliminar = pila->cima;
        pila->cima = pila->cima->siguiente;
        DestruirNodo(eliminar);
    }
}

int Cima(Pila* pila) {
    if (pila->cima == NULL)
        return NULL;
    else
        return pila->cima->value;
}
