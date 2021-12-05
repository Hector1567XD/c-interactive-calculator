#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./include/errors.h"

char* GetError(int errorCode)
{
    if (errorCode == INSUFICIENT_VALUES_ERROR) return "No hay suficientes valores en la pila.";
    if (errorCode == NO_CAN_USE_NEGATIVES_ERROR) return "No puedes usar valores negativos para esta operacion.";
    return "";
}
