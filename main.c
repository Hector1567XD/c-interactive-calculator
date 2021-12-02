#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int misterio(int x) {
    return (!x) ? x : misterio(x >> 3) * 10 + (x & 7);
}

int main() {

    misterio(5);

    char nombre[] = "Hector";
    int sizeArray = strlen(nombre);
    char lastElement;

    for (int k=0; k < sizeArray-1; k++) {
        lastElement = nombre[sizeArray-1];
        for (int i = sizeArray-1; i>k; i--) {
            nombre[i] = nombre[i-1];
        }
        nombre[k] = lastElement;
    }
    printf("\n%s", nombre);
    return 0;
}
