#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"
#include "../utils/include/string-formating-utils.h"

#include "../core/include/errors.h"
#include "../core/include/context.h"
#include "../core/include/constants.h"

void executeSeno(Context* context) {
    context->error = NO_ERRORS;

    if (getPilaLongitud(context->numberStack) < 1) {
      context->error = INSUFICIENT_VALUES_ERROR;
      return;
    }

    double numeroA = TomarCimaYDesapilar(context->numberStack);
    double operacion = sin(numeroA*(PI/180.0));
    operacion = floor(10000000*operacion)/10000000;

    Apilar(context->numberStack, operacion);
    context->response = formatDoubleToString("%g", operacion);
}
