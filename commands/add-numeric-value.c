#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/booleans.h"
#include "../utils/include/pila.h"
#include "../utils/pila.c"
#include "../utils/is-number.c"

#include "../core/include/commands.h"
#include "../core/include/errors.h"

void addNumericValue(Pila* pila, char* rawValue)
{
    Apilar(pila, atoi(rawValue));
}
