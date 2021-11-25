#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/pila.h"
#include "./include/commands.h"
#include "../commands/add-numeric-value.c"

void commandDispatch(char* command, char* input, Pila* pilaNumeros, int* error) {
    if (strcmp(command, ADD_NUMERIC_VALUE) == 0) addNumericValue(pilaNumeros, input);
}
