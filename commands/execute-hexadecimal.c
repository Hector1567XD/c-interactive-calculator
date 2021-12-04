#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"

#include "../core/include/errors.h"
#include "../core/include/context.h"

void integerDecimalToHexadecimal(int decimalNumber, char hexadecimalString[45]) {
    int remainder;
    int i, j = 0;
    while (decimalNumber != 0) {
        remainder = decimalNumber % 16;

        if (remainder < 10)
            hexadecimalString[j++] = 48 + remainder;
        else
            hexadecimalString[j++] = 55 + remainder;

        decimalNumber /= 16;
    }
    return;
}

void executeHexadecimal(Context* context)
{
    context->error = NO_ERRORS;
    char * resultado = (char *) malloc(45);

    int pilaSize = getPilaLongitud(context->numberStack);
    if (pilaSize < 1) {
      context->error = INSUFICIENT_VALUES_ERROR;
      return;
    }

    int numero = TomarCimaYDesapilar(context->numberStack);

    integerDecimalToHexadecimal(numero, resultado);
    context->response = resultado;
}
