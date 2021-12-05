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

     return "";      
}
