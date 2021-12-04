#ifndef pila_c
    #define pila_c

    #include "./include/pila.h"

    #include <stdio.h>
    #include <stdlib.h>

    Nodo* CrearNodo(double value)
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
        pila->longitud = 0;
        return pila;
    }

    void DestruirPila(Pila* pila) {
        while (pila->cima != NULL) {
            Desapilar(pila);
        }
        free(pila);
    }

    void DestruirNodo(Nodo* nodo)
    {
        nodo->siguiente = NULL;
        free(nodo);
    }

    void Apilar(Pila* pila, double value) {
        Nodo* nodo = CrearNodo(value);
        nodo->siguiente = pila->cima;
        pila->longitud++;
        pila->cima = nodo;
    }

    void Desapilar(Pila* pila) {
        if (pila->cima != NULL) {
            Nodo* eliminar = pila->cima;
            pila->cima = pila->cima->siguiente;
            pila->longitud--;
            DestruirNodo(eliminar);
        }
    }

    double Cima(Pila* pila) {
        if (pila->cima == NULL)
            return 0;
        else
            return pila->cima->value;
    }

    int getPilaLongitud(Pila* pila) {
        return pila->longitud;
    }

    double TomarCimaYDesapilar(Pila* pila) {
        double valor = Cima(pila);
        Desapilar(pila);
        return valor;
    }

#endif /* pila_c */

