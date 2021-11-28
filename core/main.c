#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"

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

void executeProgram(Context* context) {
  context->error = NO_ERRORS;
  context->response = "";
  context->command = getCommandByInput(context->input, &context->error);
  if (context->error == NO_ERRORS && strcmp(context->command, QUIT_COMMAND) != 0) {
      printf("XD Respuesta");
      commandDispatch(context);
      printf("c%s\n", context->response);
  }
}

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

        executeProgram(context);

        printf("c1--%s\n", context->response);

        // Si detecta que ha habido un comando invalido
        if (context->error == INVALID_COMMAND_ERROR) {
            printf(">Accion invalida.\n");
            continue;
        }

        printf("c2--%s\n", context->response);

        // Dispatch Command QUIT
        if (strcmp(context->command, QUIT_COMMAND) == 0) {
            programIsRunning = FALSE;
            break;
        }
        
        printf("c3--%s\n", context->response);

        // Error displayer
        errorDisplay = GetError(context->error);
        if (strlen(errorDisplay) > 0) printf(">%s\n", errorDisplay);
        
        printf("c4--%s\n", context->response);

        // Response of Command (If is Neccesary)
        if (strlen(context->response) > 0) printf(">%s\n", context->response);
    }

    return 0;
}

// TODO: Bug, los primeros 3 valores que introducs son (numero, numero y +) o (numero, numero y *) entonces el "responseText" saldra blanco la primera vez
