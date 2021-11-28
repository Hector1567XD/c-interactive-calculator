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
    if (strcmp(input, RESTA_COMMAND) == 0) return TRUE;
    if (strcmp(input, MULTIPLICAR_COMMAND) == 0) return TRUE;
    if (strcmp(input, MULTIPLICAR_COMMAND_ALTERNATIVE) == 0) return TRUE;
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
    if (strcmp(input, RESTA_COMMAND) == 0) return RESTA_COMMAND;
    if (strcmp(input, MULTIPLICAR_COMMAND) == 0) return MULTIPLICAR_COMMAND;
    if (strcmp(input, MULTIPLICAR_COMMAND_ALTERNATIVE) == 0) return MULTIPLICAR_COMMAND;
    if (isNumber(input)) return ADD_NUMERIC_VALUE;

    return IMPOSIBLE_COMMAND;
}

/*
    TODO:
    int stringEqual(s1, s2) {
        return (strcmp(s, "-") == 0);
    }
*/
