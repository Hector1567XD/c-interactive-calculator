#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/pila.h"
#include "./include/commands.h"

#include "../commands/add-numeric-value.c"
#include "../commands/execute-suma.c"
#include "../commands/execute-multiplicar.c"

void commandDispatch(char* command, char* input, Pila* pilaNumeros, char** responseText, int* error) {
    //strcpy(responseText, "asdasdasd");
    if (strcmp(command, ADD_NUMERIC_VALUE) == 0) addNumericValue(pilaNumeros, input);
    else if (strcmp(command, SUMA_COMMAND) == 0) executeSuma(pilaNumeros, responseText, error);
    else if (strcmp(command, MULTIPLICAR_COMMAND) == 0) executeMultiplicar(pilaNumeros, responseText, error);
    //printf("------- %s", responseText);
}
