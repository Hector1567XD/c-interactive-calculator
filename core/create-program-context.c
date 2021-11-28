#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"

#include "./include/commands.h"
#include "./include/constans.h"
#include "./include/errors.h"

#include "./include/context.h"

Context* CreateProgramContext()
{
    Context* context = (Context *) malloc(sizeof(Context));
    context->numberStack = CrearPila();
    context->command = NO_COMMAND;
    context->response = "";
    context->error = NO_ERRORS;

    return context;
}

// TODO: Bug, los primeros 3 valores que introducs son (numero, numero y +) o (numero, numero y *) entonces el "responseText" saldra blanco la primera vez
