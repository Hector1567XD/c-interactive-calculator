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
    if (strcmp(input, DIVIDIR_COMMAND) == 0) return TRUE;
    if (strcmp(input, RAIZ_COMMAND) == 0) return TRUE;
    if (strcmp(input, POTENCIA_COMMAND) == 0) return TRUE;
    if (strcmp(input, FACTORIAL_COMMAND) == 0) return TRUE;
    if (strcmp(input, CIMA_COMMAND) == 0) return TRUE;
    if (strcmp(input, DISPLAY_COMMAND) == 0) return TRUE;
    if (strcmp(input, CLEAR_COMMAND) == 0) return TRUE;
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
    if (strcmp(input, RESTA_COMMAND) == 0) return RESTA_COMMAND;
    if (strcmp(input, MULTIPLICAR_COMMAND) == 0) return MULTIPLICAR_COMMAND;
    if (strcmp(input, MULTIPLICAR_COMMAND_ALTERNATIVE) == 0) return MULTIPLICAR_COMMAND;
    if (strcmp(input, DIVIDIR_COMMAND) == 0) return DIVIDIR_COMMAND;
    if (strcmp(input, RAIZ_COMMAND) == 0) return RAIZ_COMMAND;
    if (strcmp(input, POTENCIA_COMMAND) == 0) return POTENCIA_COMMAND;
    if (strcmp(input, FACTORIAL_COMMAND) == 0) return FACTORIAL_COMMAND;
    if (strcmp(input, CIMA_COMMAND) == 0) return CIMA_COMMAND;
    if (strcmp(input, DISPLAY_COMMAND) == 0) return DISPLAY_COMMAND;
    if (strcmp(input, CLEAR_COMMAND) == 0) return CLEAR_COMMAND;
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
