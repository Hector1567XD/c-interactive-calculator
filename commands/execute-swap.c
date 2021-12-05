#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"

#include "../core/include/errors.h"
#include "../core/include/context.h"

void executeSwap(Context* context) {
    context->error = NO_ERRORS;

    int pilaSize = getPilaLongitud(context->numberStack);
    if (pilaSize < 2) {
      context->error = INSUFICIENT_VALUES_ERROR;
      return;
    }

    double numeroA = TomarCimaYDesapilar(context->numberStack);
    double numeroB = TomarCimaYDesapilar(context->numberStack);

    Apilar(context->numberStack, numeroA);
    Apilar(context->numberStack, numeroB);
}
