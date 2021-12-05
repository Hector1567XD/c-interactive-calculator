#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"

#include "../utils/include/is-number.h"

#include "./include/commands.h"
#include "./include/errors.h"

int isValidInput(char input[]) {
    if (isNumber(input)) return TRUE;
    if (strcmp(input, QUIT_COMMAND) == 0) return TRUE;
    if (strcmp(input, SUMA_COMMAND) == 0) return TRUE;
    if (strcmp(input, MULTIPLICAR_COMMAND) == 0) return TRUE;
    if (strcmp(input, MULTIPLICAR_COMMAND_ALTERNATIVE) == 0) return TRUE;
    if (strcmp(input, MEMORY_STORE_COMMAND) == 0) return TRUE;
    if (strcmp(input, MEMORY_RECALL_COMMAND) == 0) return TRUE;
    if (strcmp(input, MEMORY_SUMA_COMMAND) == 0) return TRUE;
    if (strcmp(input, MEMORY_RESTA_COMMAND) == 0) return TRUE;
    if (strcmp(input, SENO_COMMAND) == 0) return TRUE;
    if (strcmp(input, COSENO_COMMAND) == 0) return TRUE;
    if (strcmp(input, TANGENTE_COMMAND) == 0) return TRUE;
    if (strcmp(input, LOGARITMO_COMMAND) == 0) return TRUE;
    if (strcmp(input, ARCSENO_COMMAND) == 0) return TRUE;
    if (strcmp(input, ARCCOSENO_COMMAND) == 0) return TRUE;
    if (strcmp(input, ARCTAN_COMMAND) == 0) return TRUE;
    if (strcmp(input, SWAP_COMMAND) == 0) return TRUE;
    return FALSE;
}


char* getCommandByInput(char *input, int *error)
{
    *error = NO_ERRORS;

    // TODO: Simplificar esto
    if (!isValidInput(input)) {
        *error = INVALID_COMMAND_ERROR;
        return NO_COMMAND;
    }

    if (strcmp(input, QUIT_COMMAND) == 0) return QUIT_COMMAND;
    if (strcmp(input, SUMA_COMMAND) == 0) return SUMA_COMMAND;
    if (strcmp(input, MULTIPLICAR_COMMAND) == 0) return MULTIPLICAR_COMMAND;
    if (strcmp(input, MULTIPLICAR_COMMAND_ALTERNATIVE) == 0) return MULTIPLICAR_COMMAND;
    if (strcmp(input, MEMORY_STORE_COMMAND) == 0) return MEMORY_STORE_COMMAND;
    if (strcmp(input, MEMORY_RECALL_COMMAND) == 0) return MEMORY_RECALL_COMMAND;
    if (strcmp(input, MEMORY_SUMA_COMMAND) == 0) return MEMORY_SUMA_COMMAND;
    if (strcmp(input, MEMORY_RESTA_COMMAND) == 0) return MEMORY_RESTA_COMMAND;
    if (strcmp(input, SENO_COMMAND) == 0) return SENO_COMMAND;
    if (strcmp(input, COSENO_COMMAND) == 0) return COSENO_COMMAND;
    if (strcmp(input, TANGENTE_COMMAND) == 0) return TANGENTE_COMMAND;
    if (strcmp(input, LOGARITMO_COMMAND) == 0) return LOGARITMO_COMMAND;
    if (strcmp(input, ARCSENO_COMMAND) == 0) return ARCSENO_COMMAND;
    if (strcmp(input, ARCCOSENO_COMMAND) == 0) return ARCCOSENO_COMMAND;
    if (strcmp(input, ARCTAN_COMMAND) == 0) return ARCTAN_COMMAND;
    if (strcmp(input, SWAP_COMMAND) == 0) return SWAP_COMMAND;
    if (isNumber(input)) return ADD_NUMERIC_VALUE;

    return IMPOSIBLE_COMMAND;
}

/*
    TODO:
    int stringEqual(s1, s2) {
        return (strcmp(s, "-") == 0);
    }
*/
