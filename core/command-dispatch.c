#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/pila.h"
#include "../utils/include/booleans.h"
#include "./include/commands.h"

#include "../commands/add-numeric-value.c"
#include "../commands/execute-suma.c"
#include "../commands/execute-multiplicar.c"
#include "./include/context.h"

void commandDispatch(Context* context) {
    if (isCommand(context, ADD_NUMERIC_VALUE)) addNumericValue(context);
    else if (isCommand(context, SUMA_COMMAND)) executeSuma(context);
    else if (isCommand(context, MULTIPLICAR_COMMAND)) executeMultiplicar(context);
}

int isCommand(Context* context, char* command) {
  if (strcmp(context->command, command) == 0) return TRUE;
  return FALSE;
}
