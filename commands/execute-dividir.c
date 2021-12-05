#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"
#include "../utils/include/string-formating-utils.h"

#include "../core/include/errors.h"
#include "../core/include/context.h"

void executeDividir(Context* context)
{
    context->error = NO_ERRORS;

    int pilaSize = getPilaLongitud(context->numberStack);
    if (pilaSize < 2) {
      context->error = INSUFICIENT_VALUES_ERROR;
      return;
    }

    double numeroA = Cima(context->numberStack);

    if (numeroA == 0) {
      context->error = DIVIDED_BY_ZERO_ERROR;
      return;
    }

    Desapilar(context->numberStack);
    double numeroB = TomarCimaYDesapilar(context->numberStack);

    double operacion = numeroB / numeroA;

    Apilar(context->numberStack, operacion);
    context->response = formatDoubleToString("%g", operacion);
}
