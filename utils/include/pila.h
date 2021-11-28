#ifndef pila_h
    #define pila_h

    #include <stdio.h>

    typedef struct nodo {
        double value;
        struct nodo* siguiente;
    } Nodo;

    typedef struct pila {
        Nodo* cima;
        int longitud;
    } Pila;

    Nodo* CrearNodo(double value);
    void DestruirPila(Pila* pila);
    Pila* CrearPila();
    void DestruirNodo(Nodo* nodo);

    void Apilar(Pila* pila, double url);
    void Desapilar(Pila* pila);
    double Cima(Pila* pila);
    int getPilaLongitud(Pila* pila);
    double TomarCimaYDesapilar(Pila* pila);

#endif /* pila_h */
