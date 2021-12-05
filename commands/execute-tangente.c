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

void executeTangente(Context* context) {
    context->error = NO_ERRORS;

    if (getPilaLongitud(context->numberStack) < 1) {
      context->error = INSUFICIENT_VALUES_ERROR;
      return;
    }

    double numeroA = Cima(context->numberStack);
    double validar = cos(numeroA*(PI/180.0));
    validar = floor(10000000*validar)/10000000;
    if (validar == 0){
      context->error = DOMAIN_TAN_ERROR;
      return;
    }
    Desapilar(context->numberStack);

    double operacion = tan(numeroA*(PI/180.0));
    operacion = floor(10000000*operacion)/10000000;

    Apilar(context->numberStack, operacion);
    context->response = formatDoubleToString("%g", operacion);
}
