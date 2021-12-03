#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"

#include "../core/include/errors.h"
#include "../core/include/context.h"

void executeFactorial(Context* context)
{
    context->error = NO_ERRORS;
    char * resultado = (char *) malloc(45);

    int pilaSize = getPilaLongitud(context->numberStack);
    if (pilaSize == 0) {
      context->error = INSUFICIENT_VALUES_ERROR;
      return;
    }

    double numeroA = TomarCimaYDesapilar(context->numberStack);

    if (numeroA < 0) { 
      context->error = UNDEFINED;
      return;
    }

    double ptr;
    double decimal = modf(numeroA, &ptr);

    if (decimal != 0){ //revisar(?)
      context->error = UNDEFINED;
      return;
    }

    double factorial(double  n)
    {
    if (n == 0)
      {  
       return 1;  
      }
    else
      { 
       return(n * factorial(n-1));
      }   
    }

    double operacion = factorial(numeroA);

    Apilar(context->numberStack, operacion);

    snprintf( resultado, 46, "%g", operacion );
    context->response = resultado;
}