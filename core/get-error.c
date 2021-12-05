#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./include/errors.h"

char* GetError(int errorCode)
{
<<<<<<< HEAD

     if (errorCode == NEGATIVE_ERROR) return "No se pueden utilizar numeros negativos para esta operacion";
     if (errorCode == INSUFICIENT_VALUES_ERROR) return "No hay suficientes valores en la pila";
     if (errorCode == DIVIDED_BY_ZERO_ERROR) return "La division entre 0 no esta definida";
     if (errorCode == ZERO_ERROR) return "No puede usar 0 para esta operacion";
     if (errorCode == DECIMAL_ERROR) return "No puede usar numeros decimales para esta operacion";

     return "";      
=======
    if (errorCode == INSUFICIENT_VALUES_ERROR) return "No hay suficientes valores en la pila.";
    else if(errorCode == DOMAIN_BETWEEN_ERROR) return "ERROR de dominio de Arc seno o Arc coseno, inserte un valor entre -1 y 1";
    else if(errorCode == DOMAIN_LOG_ERROR) return "ERROR Logaritmo, No se puede calcular logaritmo de numeros menores o igual que 0";
    else if(errorCode == DOMAIN_TAN_ERROR) return "ERROR de dominio de tangente, No se puede calcular tangente cuyo valor en coseno sea 0";
    return "";
>>>>>>> main
}
