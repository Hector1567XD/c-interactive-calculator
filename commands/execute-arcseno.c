#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"
#include "../utils/include/string-formating-utils.h"

#include "../core/include/errors.h"
#include "../core/include/context.h"
#include "../core/include/constans.h"

void executeArcseno(Context* context) {
    context->error = NO_ERRORS;

    if (getPilaLongitud(context->numberStack) < 1) {
      context->error = INSUFICIENT_VALUES_ERROR;
      return;
    }

    double numeroA = Cima(context->numberStack);
    if ((numeroA < -1) || (numeroA >1)) {
      context->error = DOMAIN_BETWEEN_ERROR;
      return;
    }
    Desapilar(context->numberStack);

    double operacion = asin(numeroA)*(180.0/PI);
    operacion = floor(10000000*operacion)/10000000;

    Apilar(context->numberStack, operacion);
    context->response = formatDoubleToString("%g", operacion);
}
