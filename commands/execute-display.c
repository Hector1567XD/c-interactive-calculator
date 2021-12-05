#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"

#include "../core/include/errors.h"
#include "../core/include/context.h"

void executeDisplay(Context* context) {
    context->error = NO_ERRORS;

    if (getPilaLongitud(context->numberStack) == 0) {
      context->error = INSUFICIENT_VALUES_ERROR;
      return;
    }

    int i;
    double array[pilaSize];

    for(i = 0; i < pilaSize; i++){
      array[i] = TomarCimaYDesapilar(context->numberStack);
      printf("%g\n",array[i]);
    }

    for(i = pilaSize - 1; i >= 0; i--){
      Apilar(context->numberStack, array[i]);
    }
}
