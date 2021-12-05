#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"

#include "../core/include/errors.h"
#include "../core/include/context.h"

void executeRaiz(Context* context)
{
    context->error = NO_ERRORS;
    char * resultado = (char *) malloc(45);

    int pilaSize = getPilaLongitud(context->numberStack);
    
    if (pilaSize == 0) {
     
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

    snprintf( resultado, 46, "%g", operacion );
    context->response = resultado;
}