#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"
#include "../utils/pila.c"
#include "../utils/is-number.c"

#include "../core/include/errors.h"

void executeMultiplicar(Pila* pila, char **responseText, int *error)
{
    *error = NO_ERRORS;
    char resultado[45] = "";

    int pilaSize = getPilaLongitud(pila);
    if (pilaSize < 2) {
      *error = INSUFICIENT_VALUES_ERROR;
      return;
    }

    int numeroA = TomarCimaYDesapilar(pila);
    int numeroB = TomarCimaYDesapilar(pila);

    int operacion = numeroA * numeroB;

    Apilar(pila, operacion);

    snprintf( resultado, 46, "%d", operacion );
    *responseText = resultado;
}
