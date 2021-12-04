#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"

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

void executeOctal(Context* context)
{
    context->error = NO_ERRORS;
    char * resultado = (char *) malloc(45);

    int pilaSize = getPilaLongitud(context->numberStack);
    if (pilaSize < 1) {
      context->error = INSUFICIENT_VALUES_ERROR;
      return;
    }

    int numero = TomarCimaYDesapilar(context->numberStack);

    int operacion = integerDecimalToOctal(numero);

    Apilar(context->numberStack, operacion);

    snprintf( resultado, 46, "%d", operacion );
    context->response = resultado;
}
