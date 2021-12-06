#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"
#include "../utils/include/string-formating-utils.h"

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

void executeBinary(Context* context) {
    context->error = NO_ERRORS;

    if (getPilaLongitud(context->numberStack) < 1) {
      context->error = INSUFICIENT_VALUES_ERROR;
      return;
    }

    int numero = TomarCimaYDesapilar(context->numberStack);

    int operacion = integerDecimalToBinary(numero);

    Apilar(context->numberStack, operacion);
    context->response = formatDoubleToString("%g", operacion);
}
