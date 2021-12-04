#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"

#include "../core/include/errors.h"
#include "../core/include/context.h"

void executeLogaritmo(Context* context)
{
    context->error = NO_ERRORS;
    char * resultado = (char *) malloc(45);

    double numeroA = TomarCimaYDesapilar(context->numberStack);
    if (numeroA == 0) {
      context->error = LOG_ERROR;
      return;
    }

    double operacion = log10(numeroA);

    Apilar(context->numberStack, operacion);

    snprintf( resultado, 46, "%f", operacion );
    context->response = resultado;
}
