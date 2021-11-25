#ifndef pila_h
    #define pila_h

    #include <stdio.h>

    typedef struct nodo {
        int value;
        struct nodo* siguiente;
    } Nodo;

    typedef struct pila {
        Nodo* cima;
    } Pila;

    Nodo* CrearNodo(int value);
    Pila* CrearPila();
    void DestruirNodo(Nodo* nodo);

    void Apilar(Pila* pila, int url);
    void Desapilar(Pila* pila);
    int Cima(Pila* pila);

#endif /* pila_h */
