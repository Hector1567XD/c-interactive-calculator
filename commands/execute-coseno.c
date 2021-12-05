#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"

#include "../core/include/errors.h"
#include "../core/include/context.h"
#define PI 3.14159265

void executeCoseno(Context* context)
{
    context->error = NO_ERRORS;
    char * resultado = (char *) malloc(45);
    
    int pilaSize = getPilaLongitud(context->numberStack);
    if (pilaSize < 1) {
      context->error = INSUFICIENT_VALUES_ERROR;
      return;
    }

    double numeroA = TomarCimaYDesapilar(context->numberStack);

    double operacion = cos(numeroA*(PI/180.0));
    operacion = floor(10000000*operacion)/10000000;

    Apilar(context->numberStack, operacion);


    snprintf( resultado, 46, "%g", operacion );
    context->response = resultado;
}
