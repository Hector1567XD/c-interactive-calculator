#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"

#include "../utils/is-number.c"

#include "./include/commands.h"
#include "./include/errors.h"

int isValidInput(char s[]) {
    if (isNumber(s)) return TRUE;
    if (strcmp(s, QUIT_COMMAND) == 0) return TRUE;
    return FALSE;
}

char* getCommandByInput(char *input, int *error)
{
    *error = NO_ERRORS;

    if (!isValidInput(input)) {
        *error = INVALID_COMMAND_ERROR;
        return NO_COMMAND;
    }

    if (strcmp(input, QUIT_COMMAND) == 0)
    {
        return QUIT_COMMAND;
    }
    else
    {
        if (isNumber(input)) return ADD_NUMERIC_VALUE;
    }

    return NO_COMMAND;
}

/*
    TODO:
    int stringEqual(s1, s2) {
        return (strcmp(s, "-") == 0);
    }
*/
