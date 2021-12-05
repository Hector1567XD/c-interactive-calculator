#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/pila.h"
#include "../utils/include/booleans.h"
#include "./include/commands.h"

#include "../commands/include/add-numeric-value.h"
#include "../commands/include/execute-suma.h"
#include "../commands/include/execute-resta.h"
#include "../commands/include/execute-multiplicar.h"
#include "../commands/include/execute-dividir.h"
#include "../commands/include/execute-raiz.h"
#include "../commands/include/execute-potencia.h"
#include "../commands/include/execute-factorial.h"
#include "../commands/include/execute-cima.h"
#include "../commands/include/execute-display.h"
#include "../commands/include/execute-clear.h"
#include "../commands/include/execute-coseno.h"
#include "../commands/include/execute-tangente.h"
#include "../commands/include/execute-logaritmo.h"
#include "../commands/include/execute-arccoseno.h"
#include "../commands/include/execute-arctan.h"
#include "../commands/include/execute-swap.h"
#include "./include/context.h"

void commandDispatch(Context* context) {
    if (isCommand(context, ADD_NUMERIC_VALUE)) addNumericValue(context);
    else if (isCommand(context, RESTA_COMMAND)) executeResta(context);
    else if (isCommand(context, SUMA_COMMAND)) executeSuma(context);
    else if (isCommand(context, MULTIPLICAR_COMMAND)) executeMultiplicar(context);
    else if (isCommand(context, DIVIDIR_COMMAND)) executeDividir(context);
    else if (isCommand(context, RAIZ_COMMAND)) executeRaiz(context);
    else if (isCommand(context, POTENCIA_COMMAND)) executePotencia(context);
    else if (isCommand(context, FACTORIAL_COMMAND)) executeFactorial(context);
    else if (isCommand(context, CIMA_COMMAND)) executeCima(context);
    else if (isCommand(context, DISPLAY_COMMAND)) executeDisplay(context);
    else if (isCommand(context, CLEAR_COMMAND)) executeClear(context);
    else if (isCommand(context, SENO_COMMAND)) executeSeno(context);
    else if (isCommand(context, COSENO_COMMAND)) executeCoseno(context);
    else if (isCommand(context, TANGENTE_COMMAND)) executeTangente(context);
    else if (isCommand(context, LOGARITMO_COMMAND)) executeLogaritmo(context);
    else if (isCommand(context, ARCSENO_COMMAND)) executeArcseno(context);
    else if (isCommand(context, ARCCOSENO_COMMAND)) executeArccoseno(context);
    else if (isCommand(context, ARCTAN_COMMAND)) executeArctan(context);
    else if (isCommand(context, SWAP_COMMAND)) executeSwap(context);
}

int isCommand(Context* context, char* command) {
  if (strcmp(context->command, command) == 0) return TRUE;
  return FALSE;
}
