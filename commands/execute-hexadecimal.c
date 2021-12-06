#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"

#include "../core/include/errors.h"
#include "../core/include/context.h"

void strrev(char *str);

void integerDecimalToHexadecimal(int decimalNumber, char hexadecimalString[45]) {
    int remainder;
    int i = 0;
    while (decimalNumber != 0) {
        remainder = decimalNumber % 16;

        if (remainder < 10)
            hexadecimalString[i++] = 48 + remainder;
        else
            hexadecimalString[i++] = 55 + remainder;

        decimalNumber /= 16;
    }
    return;
}

void executeHexadecimal(Context* context) {
    context->error = NO_ERRORS;
    char * resultado = (char *) malloc(45);

    if (getPilaLongitud(context->numberStack) < 1) {
      context->error = INSUFICIENT_VALUES_ERROR;
      return;
    }

    int numero = Cima(context->numberStack);

    if (numero < 0) {
      context->error = NEGATIVE_NUMBER_ERROR;
      return;
    }

    Desapilar(context->numberStack);

    integerDecimalToHexadecimal(numero, resultado);
   
    strrev(resultado);

    context->response = resultado;
}

void strrev(char *str){
    int i;
    int longitud = strlen(str);
    char aux;
    for(i = 0; i < longitud/2; i++){
        aux = str[i];
        str[i] = str[longitud-i-1];
        str[longitud-i-1] = aux;
    }   
}