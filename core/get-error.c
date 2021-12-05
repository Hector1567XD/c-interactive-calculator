#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./include/errors.h"

char* GetError(int errorCode)
{
     if (errorCode == NEGATIVE_ERROR) return "No se pueden utilizar numeros negativos para esta operacion";
     if (errorCode == INSUFICIENT_VALUES_ERROR) return "No hay suficientes valores en la pila";
     if (errorCode == DIVIDED_BY_ZERO_ERROR) return "La division entre 0 no esta definida";
     if (errorCode == ZERO_ERROR) return "No puede usar 0 para esta operacion";
     if (errorCode == DECIMAL_ERROR) return "No puede usar numeros decimales para esta operacion";
     if (errorCode == UNDEFINED) return "Valor indefinido";
     if (errorCode == DOMAIN_BETWEEN_ERROR) return "Error de dominio de Arc seno o Arc coseno, inserte un valor entre -1 y 1";
     if (errorCode == DOMAIN_LOG_ERROR) return "Error de dominio en logaritmo, No se puede calcular logaritmo de numeros menores o igual que 0";
     if (errorCode == DOMAIN_TAN_ERROR) return "Error de dominio en tangente, No se puede calcular tangente cuyo valor en coseno sea 0";
     if (errorCode == INSUFICIENT_VALUES_ERROR) return "No hay suficientes valores en la pila.";
     if (errorCode == INSUFICIENT_VALUES_IN_MEMORY_ERROR) return "No hay suficientes valores en la pila de memoria.";
     if (errorCode == NO_CAN_USE_NEGATIVES_ERROR) return "No puedes usar valores negativos para esta operacion.";
     if (errorCode == DOMAIN_BETWEEN_ERROR) return "Error de dominio en arcseno o arccoseno, inserte un valor entre -1 y 1";
     if (errorCode == DOMAIN_LOG_ERROR) return "Error de dominio en logaritmo, No se puede calcular logaritmo de numeros menores o igual que 0";
     if (errorCode == DOMAIN_TAN_ERROR) return "Error de dominio en tangente, No se puede calcular tangente cuyo valor en coseno sea 0";
     return "";
}
