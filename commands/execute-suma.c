#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"
//#include "../utils/pila.c"
#include "../utils/is-number.c"

#include "../core/include/errors.h"
#include "../core/include/context.h";

void executeSuma(Context* context)
{
    context->error = NO_ERRORS;
    char resultado[45] = "";

    int pilaSize = getPilaLongitud(context->numberStack);
    if (pilaSize < 2) {
      context->error = INSUFICIENT_VALUES_ERROR;
      return;
    }

    int numeroA = TomarCimaYDesapilar(context->numberStack);
    int numeroB = TomarCimaYDesapilar(context->numberStack);

    int operacion = numeroA + numeroB;

    Apilar(context->numberStack, operacion);

    snprintf( resultado, 46, "%d", operacion );
    context->response = resultado;
}
