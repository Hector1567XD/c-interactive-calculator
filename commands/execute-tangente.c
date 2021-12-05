#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"

#include "../core/include/errors.h"
#include "../core/include/context.h"
#define PI 3.14159265

void executeTangente(Context* context)
{
    context->error = NO_ERRORS;
    char * resultado = (char *) malloc(45);

    int pilaSize = getPilaLongitud(context->numberStack);
    if (pilaSize < 1) {
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

    snprintf( resultado, 46, "%g", operacion );
    context->response = resultado;
}
