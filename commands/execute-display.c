#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"

#include "../core/include/errors.h"
#include "../core/include/context.h"

void executeDisplay(Context* context)
{
    context->error = NO_ERRORS;
    char * resultado = (char *) malloc(45);

    int pilaSize = getPilaLongitud(context->numberStack);
    if (pilaSize == 0) {
      context->error = INSUFICIENT_VALUES_ERROR;
      return;
    }

    int i; 
    double array[pilaSize];

    for(i = 0; i < pilaSize; i++){
    
    double numeroA = TomarCimaYDesapilar(context->numberStack);
    double operacion = numeroA;
    array[i] = numeroA;
    
    printf("%g\n",numeroA);
  }

   for(i = pilaSize; i = 0; i--){

    Apilar(context->numberStack, array[i]);
    printf("%g\n",array[i]);
   } 
}