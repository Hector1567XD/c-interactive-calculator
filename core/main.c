#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"

#include "../utils/include/get-inputed.h"
#include "../utils/include/is-number.h"

#include "./include/commands.h"
#include "./include/constans.h"
#include "./include/errors.h"

#include "./include/create-program-context.h"
#include "./include/get-command-by-input.h"
#include "./include/command-dispatch.h"
#include "./include/get-error.h"
#include "./include/context.h"

void executeProgram(Context* context) {
  context->error = NO_ERRORS;
  context->response = "";
  context->command = getCommandByInput(context->input, &context->error);
  if (context->error == NO_ERRORS && strcmp(context->command, QUIT_COMMAND) != 0) {
      commandDispatch(context);
  }
}

void interactiveMode(Context* context) {
  int programIsRunning = TRUE;
  char* errorDisplay = "";

  printf(">");
  getInputed(context->input, &context->error);

  if(context->error == INPUT_MAX_LENGTH_ERROR)
      printf("Error: se ha ingresado mas caracteres de los permitidos\n      solo se tomaran caracteres hasta el limite permitido (%d)\n", MAX_LENGTH);

  executeProgram(context);

  // Si detecta que ha habido un comando invalido
  if (context->error == INVALID_COMMAND_ERROR) {
    printf(">Accion invalida.\n");
  }
  else if (strcmp(context->command, QUIT_COMMAND) == 0) {
    // Dispatch Command QUIT
    programIsRunning = FALSE;
  }else{
    // Error displayer
    errorDisplay = GetError(context->error);
    if (strlen(errorDisplay) > 0) printf(">%s\n", errorDisplay);

    // Response of Command (If is Neccesary)
    if (strlen(context->response) > 0) printf(">%s\n", context->response);
  }

  if (strlen(context->response) > 0) free(context->response);

  // Vuelve a ejecutar el interactiveModeExecution si es que el
  // programa sigue corriende
  if (programIsRunning == TRUE)
    interactiveMode(context);
}

int main(int argQuantity, char* arg[])
{
    Context* context = CreateProgramContext();

    if (argQuantity < 2) {
      interactiveMode(context);
    }else{
      int programIsRunning = TRUE;
      char* errorDisplay = "";
      for (int i = 0; i < argQuantity; i++) {

        strcpy(context->input, arg[i]);

        executeProgram(context);

        // Si detecta que ha habido un comando invalido
        if (context->error == INVALID_COMMAND_ERROR) {
          printf("Comando o accion invalida '%s' en el argumento %d", context->input, i);
          break;
        }
        else if (strcmp(context->command, QUIT_COMMAND) == 0) {
          programIsRunning = FALSE;
        }else{
          // Error displayer
          errorDisplay = GetError(context->error);
          if (strlen(errorDisplay) > 0) printf(">%s\n", errorDisplay);

          // Response of Command (If is Neccesary)
          if (strlen(context->response) > 0) printf(">%s\n", context->response);
        }

        // Vuelve a ejecutar el interactiveModeExecution si es que el
        // programa sigue corriende
        if (programIsRunning == TRUE)
          interactiveMode(context);
      }
    }

    return 0;
}

// TODO: Bug, los primeros 3 valores que introducs son (numero, numero y +) o (numero, numero y *) entonces el "responseText" saldra blanco la primera vez
