#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"

#include "../core/include/errors.h"
#include "../core/include/context.h"

int integerDecimalToBinary(int decimalNumber) {
  int i = 1, binaryNumber = 0;

  while (decimalNumber != 0) {
    binaryNumber += (decimalNumber % 2) * i;
    decimalNumber /= 2;
    i *= 10;
  }

  return binaryNumber;
}

void executeBinary(Context* context)
{
    context->error = NO_ERRORS;
    char * resultado = (char *) malloc(45);

    int pilaSize = getPilaLongitud(context->numberStack);
    if (pilaSize < 1) {
      context->error = INSUFICIENT_VALUES_ERROR;
      return;
    }

    int numero = TomarCimaYDesapilar(context->numberStack);

    int operacion = integerDecimalToBinary(numero);

    Apilar(context->numberStack, operacion);

    snprintf( resultado, 46, "%d", operacion );
    context->response = resultado;
}