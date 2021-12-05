#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./include/errors.h"

char* GetError(int errorCode)
{
    if (errorCode == INSUFICIENT_VALUES_ERROR) return "No hay suficientes valores en la pila.";
    if (errorCode == INSUFICIENT_VALUES_IN_MEMORY_ERROR) return "No hay suficientes valores en la pila de memoria.";
    if (errorCode == DOMAIN_BETWEEN_ERROR) return "Error de dominio en arcseno o arccoseno, inserte un valor entre -1 y 1";
    if (errorCode == DOMAIN_LOG_ERROR) return "Error de dominio en logaritmo, No se puede calcular logaritmo de numeros menores o igual que 0";
    if (errorCode == DOMAIN_TAN_ERROR) return "Error de dominio en tangente, No se puede calcular tangente cuyo valor en coseno sea 0";
    return "";
}
