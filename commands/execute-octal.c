#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"
#include "../utils/include/string-formating-utils.h"

#include "../core/include/errors.h"
#include "../core/include/context.h"

int integerDecimalToOctal(int decimalNumber) {
    int i = 1, octalNumber = 0;

    while (decimalNumber != 0) {
        octalNumber += (decimalNumber % 8) * i;
        decimalNumber /= 8;
        i *= 10;
    }

    return octalNumber;
}

void executeOctal(Context* context) {
    context->error = NO_ERRORS;

    if (getPilaLongitud(context->numberStack) < 1) {
      context->error = INSUFICIENT_VALUES_ERROR;
      return;
    }

    int numero = TomarCimaYDesapilar(context->numberStack);
    int operacion = integerDecimalToOctal(numero);

    Apilar(context->numberStack, operacion);
    context->response = formatDoubleToString("%g", operacion);
}
