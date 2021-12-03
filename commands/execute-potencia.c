#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"

#include "../core/include/errors.h"
#include "../core/include/context.h"

void executePotencia(Context* context)
{
    context->error = NO_ERRORS;
    char * resultado = (char *) malloc(45);

    int pilaSize = getPilaLongitud(context->numberStack);
    if (pilaSize < 2) {
      context->error = INSUFICIENT_VALUES_ERROR;
      return;
    }

    double numeroA = TomarCimaYDesapilar(context->numberStack);
    double numeroB = TomarCimaYDesapilar(context->numberStack);

    /*if (pilaSize < 2) {
      context->error = INSUFICIENT_VALUES_ERROR;
      return;*/

    /*double pow(double x, double y) calcula la potencia de un numero elevado(x) al segundo numero ingresado(y)*/

    double operacion = pow(numeroB,numeroA);

    Apilar(context->numberStack, operacion);

    snprintf( resultado, 46, "%g", operacion );
    context->response = resultado;
}