#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"

#include "../core/include/errors.h"
#include "../core/include/context.h"

int integerBinaryToDecimal(int binaryNumber) {
  int i = 1, decimalNumber = 0;

  while (binaryNumber != 0) {
    decimalNumber += (binaryNumber % 10) * i;
    binaryNumber /= 10;
    i *= 2;
  }

  return decimalNumber;
}

void executeDecimal(Context* context)
{
    context->error = NO_ERRORS;
    char * resultado = (char *) malloc(45);

    int pilaSize = getPilaLongitud(context->numberStack);
    if (pilaSize < 1) {
      context->error = INSUFICIENT_VALUES_ERROR;
      return;
    }

    int numero = TomarCimaYDesapilar(context->numberStack);

    int operacion = integerBinaryToDecimal(numero);

    Apilar(context->numberStack, operacion);

    snprintf( resultado, 46, "%d", operacion );
    context->response = resultado;
}