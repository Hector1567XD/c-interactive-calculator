#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"
#include "../utils/include/string-formating-utils.h"

#include "../core/include/errors.h"
#include "../core/include/context.h"

void executeRaiz(Context* context) {
    context->error = NO_ERRORS;

    if (getPilaLongitud(context->numberStack) == 0) {
      context->error = INSUFICIENT_VALUES_ERROR;
      return;
    }

    double numero = Cima(context->numberStack);
    if (numero < 0) {
      context->error = NEGATIVE_ERROR;
      return;
    }

    Desapilar(context->numberStack);
    double operacion = sqrt(numero);

    Apilar(context->numberStack, operacion);
    context->response = formatDoubleToString("%g", operacion);
}
