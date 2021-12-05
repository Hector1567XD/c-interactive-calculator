#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"

#include "../core/include/errors.h"
#include "../core/include/context.h"

void executeClear(Context* context) {
    context->error = NO_ERRORS;
    char * resultado = (char *) malloc(45);

    if (getPilaLongitud(context->numberStack) == 0) {
      context->error = INSUFICIENT_VALUES_ERROR;
      return;
    }

   DestruirPila(context->numberStack);
   context->numberStack = CrearPila();
}
