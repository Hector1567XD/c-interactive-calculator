#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"
#include "../utils/include/string-formating-utils.h"

#include "../core/include/errors.h"
#include "../core/include/context.h"

int integerOctalToDecimal(int octalNumber) {
  int i = 1, decimalNumber = 0;

  while (octalNumber != 0) {
    decimalNumber += (octalNumber % 10) * i;
    octalNumber /= 10;
    i *= 8;
  }

  return decimalNumber;
}


void executeOctalToDecimal(Context* context) {
    context->error = NO_ERRORS;

    if (getPilaLongitud(context->numberStack) < 1) {
      context->error = INSUFICIENT_VALUES_ERROR;
      return;
    }

    int numero = TomarCimaYDesapilar(context->numberStack);

    int operacion = integerOctalToDecimal(numero);

    Apilar(context->numberStack, operacion);
    context->response = formatDoubleToString("%g", operacion);
}
