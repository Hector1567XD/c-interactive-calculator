#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/pila.h"
#include "../utils/include/booleans.h"
#include "./include/commands.h"

#include "../commands/include/add-numeric-value.h"
#include "../commands/include/execute-suma.h"
#include "../commands/include/execute-multiplicar.h"
#include "../commands/include/execute-binary.h"
#include "../commands/include/execute-octal.h"
#include "./include/context.h"

void commandDispatch(Context* context) {
    if (isCommand(context, ADD_NUMERIC_VALUE)) addNumericValue(context);
    else if (isCommand(context, SUMA_COMMAND)) executeSuma(context);
    else if (isCommand(context, MULTIPLICAR_COMMAND)) executeMultiplicar(context);
    else if (isCommand(context, DEC_BINARY_COMMAND)) executeBinary(context);
    else if (isCommand(context, DEC_OCTAL_COMMAND)) executeOctal(context);
    else if (isCommand(context, DEC_HEXA_COMMAND)) executeOctal(context);
}

int isCommand(Context* context, char* command) {
  if (strcmp(context->command, command) == 0) return TRUE;
  return FALSE;
}
