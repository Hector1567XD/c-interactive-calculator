#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./include/commands.h"
#include "./include/constans.h"
#include "./include/errors.h"

#include "../utils/include/get-inputed.h"
#include "../utils/include/booleans.h"

#include "./include/execute-program.h"
#include "./include/get-error.h"
#include "./include/context.h"

void interactiveMode(Context* context) {
  int programIsRunning = TRUE;
  char* errorDisplay = "";

  printf("CALC>");
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
