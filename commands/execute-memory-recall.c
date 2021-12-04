#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"

#include "../core/include/commands.h"
#include "../core/include/errors.h"
#include "../core/include/context.h"

void executeMemoryRecall(Context* context) {
  context->error = NO_ERRORS;
  char * resultado = (char *) malloc(45);

  int pilaSize = getPilaLongitud(context->memoryStack);
  if (pilaSize < 1) {
    context->error = INSUFICIENT_VALUES_IN_MEMORY_ERROR;
    return;
  }

  double numero = TomarCimaYDesapilar(context->memoryStack);
  Apilar(context->numberStack, numero);

  snprintf( resultado, 46, "%g", numero );
  context->response = resultado;
}
