#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"
//#include "../utils/pila.c"

#include "../utils/include/is-number.h"
#include "../utils/include/get-inputed.h"

#include "./include/commands.h"
#include "./include/constans.h"
#include "./include/errors.h"

#include "./include/get-command-by-input.h"
#include "./include/command-dispatch.h"
#include "./include/context.h"
#include "./include/create-program-context.h"
#include "./include/get-error.h"

int main()
{
    Context* context = CreateProgramContext();
    int programIsRunning = TRUE;
    char* errorDisplay = "";

    while (programIsRunning == TRUE) {
        context->error = NO_ERRORS;
        context->response = "";

        printf(">");
        getInputed(context->input, &context->error);

        if(context->error == INPUT_MAX_LENGTH_ERROR)
            printf("Error: se ha ingresado mas caracteres de los permitidos\n      solo se tomaran caracteres hasta el limite permitido (%d)\n", MAX_LENGTH);

        context->command = getCommandByInput(context->input, &context->error);
        if (context->error == INVALID_COMMAND_ERROR) {
            printf(">Accion invalida.\n");
            continue;
        }

        // Dispatch Command QUIT
        if (strcmp(context->command, QUIT_COMMAND) == 0) {
            programIsRunning = FALSE;
            break;
        }

        // Dispatch any other COMMAND
        commandDispatch(context);

        // Error displayer
        errorDisplay = GetError(context->error);
        if (strlen(errorDisplay) > 0) printf(">%s\n", errorDisplay);

        // Response of Command (If is Neccesary)
        if (strlen(context->response) > 0) printf(">%s\n", context->response);
    }

    return 0;
}

// TODO: Bug, los primeros 3 valores que introducs son (numero, numero y +) o (numero, numero y *) entonces el "responseText" saldra blanco la primera vez
