#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"

#include "../core/include/errors.h"
#include "../core/include/context.h"
#define PI 3.14159265

void executeSeno(Context* context)
{
    context->error = NO_ERRORS;
    char * resultado = (char *) malloc(45);

    double numeroA = TomarCimaYDesapilar(context->numberStack);

    double operacion = sin(numeroA*(PI/180.0));

    Apilar(context->numberStack, operacion);

    snprintf( resultado, 46, "%g", operacion );
    context->response = resultado;
}
