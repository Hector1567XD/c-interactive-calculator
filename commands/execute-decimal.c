#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"
#include "../utils/include/string-formating-utils.h"

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

void executeDecimal(Context* context) {
    context->error = NO_ERRORS;

    if (getPilaLongitud(context->numberStack) < 1) {
      context->error = INSUFICIENT_VALUES_ERROR;
      return;
    }

    int numero = TomarCimaYDesapilar(context->numberStack);

    int operacion = integerBinaryToDecimal(numero);

    Apilar(context->numberStack, operacion);
    context->response = formatDoubleToString("%g", operacion);
}
