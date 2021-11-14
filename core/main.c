#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"
#include "../utils/pila.c"
#include "../utils/is-number.c"
#include "../utils/get-inputed.c"

#include "./include/commands.h"
#include "./include/constans.h"
#include "./include/errors.h"

#include "./get-command-by-input.c"
#include "./command-dispatch.c"

int main()
{
    int programIsRunning = TRUE;
    Pila* pilaNumeros = CrearPila();
    char input[65] = "";
    int error = NO_ERRORS;
    char* command = "";

    while (programIsRunning == TRUE) {
        error = NO_ERRORS;
        printf(">");

        getInputed(input, &error);

        if(error == INPUT_MAX_LENGTH_ERROR)
            printf("Error: se ha ingresado mas caracteres de los permitidos\n      solo se tomaran caracteres hasta el limite permitido (%d)\n", MAX_LENGTH);

        command = getCommandByInput(input, &error);
        if (error == INVALID_COMMAND_ERROR) {
            printf(">Accion invalida.\n");
            continue;
        }

        // Dispatch Command QUIT
        if (strcmp(command, QUIT_COMMAND) == 0) {
            programIsRunning = FALSE;
            break;
        }

        // Dispatch any other COMMAND
        commandDispatch(command, input, pilaNumeros, &error);

        // Error displayer
    }

    printf("%d", Cima(pilaNumeros));

    return 0;
}
