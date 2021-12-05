#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./include/errors.h"

char* GetError(int errorCode)
{
    if (errorCode == INSUFICIENT_VALUES_ERROR) return "No hay suficientes valores en la pila.";
    else if(errorCode == DOMAIN_ERROR) return "ERROR de dominio de Arc seno o Arc coseno, inserte un valor entre -1 y 1";
    else if(errorCode == LOG_ERROR) return "ERROR Logaritmo, No se puede calcular logaritmo de 0";
    else if(errorCode == DOMAIN_TAN_ERROR) return "ERROR de dominio de tangente, No se puede calcular tangente cuyo valor en coseno sea 0";
    return "";
}
