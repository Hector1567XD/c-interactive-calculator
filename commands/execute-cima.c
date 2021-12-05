#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"
#include "../utils/include/string-formating-utils.h"

#include "../core/include/errors.h"
#include "../core/include/context.h"

void executeCima(Context* context) {
    context->error = NO_ERRORS;

    int pilaSize = getPilaLongitud(context->numberStack);
    if (pilaSize == 0) {
      context->error = INSUFICIENT_VALUES_ERROR;
      return;
    }

    double numero = TomarCimaYDesapilar(context->numberStack);

    Apilar(context->numberStack, numero);
    context->response = formatDoubleToString("%g", numero);
}
