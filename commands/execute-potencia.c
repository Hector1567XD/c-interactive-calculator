#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"
#include "../utils/include/string-formating-utils.h"

#include "../core/include/errors.h"
#include "../core/include/context.h"

void executePotencia(Context* context) {
    context->error = NO_ERRORS;

    int pilaSize = getPilaLongitud(context->numberStack);
    if (pilaSize < 2) {
      context->error = INSUFICIENT_VALUES_ERROR;
      return;
    }

    double numeroA = TomarCimaYDesapilar(context->numberStack); //exponente
    double numeroB = TomarCimaYDesapilar(context->numberStack); //base

    double operacion = 0;

    if (numeroA < 0){
     numeroA = numeroA * -1;
     operacion = 1/(pow(numeroB,numeroA));
    }
    else{
     operacion = pow(numeroB,numeroA);
    }
    /*
     * double pow(double x, double y) calcula la potencia de un numero(x)
     * elevado a un segundo numero ingresado(y)
     */

    Apilar(context->numberStack, operacion);
    context->response = formatDoubleToString("%g", operacion);
}
