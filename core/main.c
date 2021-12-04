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

void shellMode(Context* context, int argQuantity, char* arg[]) {
  char* errorDisplay = "";
  char* lastResponse = "";
  int hasError = FALSE;
  for (int i = 1; i < argQuantity; i++) {

    strcpy(context->input, arg[i]);
    executeProgram(context);

    if (context->error == INVALID_COMMAND_ERROR) {
      printf("Comando o accion invalida '%s' en el argumento %i\n", context->input, i);
      hasError = TRUE;
      break;
    }else if (strcmp(context->command, QUIT_COMMAND) == 0) {
      hasError = TRUE;
      break;
    }else{

      errorDisplay = GetError(context->error);
      if (strlen(errorDisplay) > 0) {
        hasError = TRUE;
        printf("Error en argumento '%s' numero %i: %s\n", context->input, i, errorDisplay);
        break;
      }

      if (strlen(context->response) > 0) lastResponse = context->response;
    }
  }
  if (strlen(lastResponse) > 0 && !hasError) {
    printf("%s\n", lastResponse);
    free(lastResponse);
  }
}

int main(int argQuantity, char* arg[])
{
    Context* context = CreateProgramContext();

    if (argQuantity < 2) {
      interactiveMode(context);
    }else{
      shellMode(context, argQuantity, arg);
    }

    return 0;
}

// TODO: Bug, los primeros 3 valores que introducs son (numero, numero y +) o (numero, numero y *) entonces el "responseText" saldra blanco la primera vez
