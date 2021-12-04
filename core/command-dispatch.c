#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/pila.h"
#include "../utils/include/booleans.h"
#include "./include/commands.h"

#include "../commands/include/add-numeric-value.h"
#include "../commands/include/execute-suma.h"
#include "../commands/include/execute-multiplicar.h"
#include "../commands/include/execute-coseno.h"
#include "../commands/include/execute-tangente.h"
#include "../commands/include/execute-logaritmo.h"
#include "../commands/include/execute-arccoseno.h"
#include "../commands/include/execute-arctan.h"
#include "./include/context.h"

void commandDispatch(Context* context) {
    if (isCommand(context, ADD_NUMERIC_VALUE)) addNumericValue(context);
    else if (isCommand(context, SUMA_COMMAND)) executeSuma(context);
    else if (isCommand(context, MULTIPLICAR_COMMAND)) executeMultiplicar(context);
    else if (isCommand(context, SENO_COMMAND)) executeSeno(context);
    else if (isCommand(context, COSENO_COMMAND)) executeCoseno(context);
    else if (isCommand(context, TANGENTE_COMMAND)) executeTangente(context);
    else if (isCommand(context, LOGARITMO_COMMAND)) executeLogaritmo(context);
    else if (isCommand(context, ARCSENO_COMMAND)) executeArcseno(context);
    else if (isCommand(context, ARCCOSENO_COMMAND)) executeArccoseno(context);
    else if (isCommand(context, ARCTAN_COMMAND)) executeArctan(context);
}

int isCommand(Context* context, char* command) {
  if (strcmp(context->command, command) == 0) return TRUE;
  return FALSE;
}
