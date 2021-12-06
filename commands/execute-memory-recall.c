#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"
#include "../utils/include/string-formating-utils.h"

#include "../core/include/commands.h"
#include "../core/include/errors.h"
#include "../core/include/context.h"

void executeMemoryRecall(Context* context) {
  context->error = NO_ERRORS;

  if (getPilaLongitud(context->memoryStack) < 1) {
    context->error = INSUFICIENT_VALUES_IN_MEMORY_ERROR;
    return;
  }

  double numero = TomarCimaYDesapilar(context->memoryStack);

  Apilar(context->numberStack, numero);
  context->response = formatDoubleToString("%g", numero);
}
