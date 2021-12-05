#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"

#include "../core/include/commands.h"
#include "../core/include/errors.h"
#include "../core/include/context.h"

void executeMemoryResta(Context* context) {
  context->error = NO_ERRORS;
  char * resultado = (char *) malloc(45);

  if (getPilaLongitud(context->numberStack) < 1) {
    context->error = INSUFICIENT_VALUES_ERROR;
    return;
  }

  if (getPilaLongitud(context->memoryStack) < 1) {
    context->error = INSUFICIENT_VALUES_IN_MEMORY_ERROR;
    return;
  }

  double number = TomarCimaYDesapilar(context->numberStack);
  double memoryNumber = TomarCimaYDesapilar(context->memoryStack);

  double operacion = memoryNumber - number;

  Apilar(context->memoryStack, operacion);

  snprintf( resultado, 46, "%g", operacion );
  context->response = resultado;
}
