#ifndef pila_h
    #define pila_h

    #include <stdio.h>

    typedef struct nodo {
        int value;
        struct nodo* siguiente;
    } Nodo;

    typedef struct pila {
        Nodo* cima;
        int longitud;
    } Pila;

    Nodo* CrearNodo(int value);
    void DestruirPila(Pila* pila);
    Pila* CrearPila();
    void DestruirNodo(Nodo* nodo);

    void Apilar(Pila* pila, int url);
    void Desapilar(Pila* pila);
    int Cima(Pila* pila);
    int getPilaLongitud(Pila* pila);
    int TomarCimaYDesapilar(Pila* pila);

#endif /* pila_h */
