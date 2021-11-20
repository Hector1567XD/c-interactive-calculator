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
#include "./include/context.h";

int main()
{
    Context* context = (Context *) malloc(sizeof(Context));
    context->numberStack = CrearPila();
    context->command = "";
    context->response = "";
    context->error = NO_ERRORS;
    int programIsRunning = TRUE;

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
        commandDispatch(context->command, context->input, context->numberStack, &context->response, &context->error);

        // Error displayer
        if (context->error == INSUFICIENT_VALUES_ERROR) {
            printf(">No hay suficientes valores en la pila.\n");
        }

        // Response of Command (If is Neccesary)
            // TODO: Example, Result of "Suma"
        if (context->response != "") printf(">%s\n", context->response);
    }

    return 0;
}

// TODO: Bug, los primeros 3 valores que introducs son (numero, numero y +) o (numero, numero y *) entonces el "responseText" saldra blanco la primera vez
