#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"
#include "../utils/include/string-formating-utils.h"

#include "../core/include/errors.h"
#include "../core/include/context.h"
#define PI 3.14159265

void executeArccoseno(Context* context)
{
    context->error = NO_ERRORS;

    int pilaSize = getPilaLongitud(context->numberStack);
    if (pilaSize < 1) {
      context->error = INSUFICIENT_VALUES_ERROR;
      return;
    }

    double numeroA = Cima(context->numberStack);
    if ((numeroA < -1) || (numeroA >1)) {
      context->error = DOMAIN_BETWEEN_ERROR;
      return;
    }

    Desapilar(context->numberStack);
    double operacion = acos(numeroA)*(180.0/PI);
    operacion = floor(10000000*operacion)/10000000;

    Apilar(context->numberStack, operacion);

    context->response = formatDoubleToString("%g", operacion);
}
