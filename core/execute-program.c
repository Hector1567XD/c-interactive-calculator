#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./include/commands.h"
#include "./include/constans.h"
#include "./include/errors.h"

#include "./include/get-command-by-input.h"
#include "./include/command-dispatch.h"
#include "./include/context.h"

void executeProgram(Context* context) {
  context->error = NO_ERRORS;
  context->response = "";
  context->command = getCommandByInput(context->input, &context->error);
  if (context->error == NO_ERRORS && strcmp(context->command, QUIT_COMMAND) != 0) {
      commandDispatch(context);
  }
}
