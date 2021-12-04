#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"

#include "../core/include/errors.h"
#include "../core/include/context.h"

int integerDecimalToBinary(int inputNumber){
  int i;
  char binaryString[45] = "";
  int number = inputNumber;

  for(i=0;n>0;i++)
  {
    binaryString[i]=number%2+'0';
    number=number/2;
  }

  return atoi(binaryString);
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
