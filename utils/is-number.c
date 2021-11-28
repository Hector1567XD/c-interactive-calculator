#ifndef is_number_c
    #define is_number_c

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #include "./include/booleans.h"

    int isNumber(char s[])
    {
        int length = strlen(s);
        int dotQuantity = 0;
        if (strcmp(s, "-") == 0) return FALSE; // Caso borde: "-"
        if (strlen(s) < 1) return FALSE; // Caso borde: ""
        for (int i = 0; s[i]!= '\0' && i < length; i++)
        {
            // Si es un digito, ignorar este IF
            if (!isdigit(s[i])) {
                if (i > 0) {
                    // Si NO es el primer caracter
                    if (s[i] == '.') {
                        // Si resulta ser un punto
                        if (dotQuantity < 1) {
                            // Si no se ha encontrado ningun punto hasta entonces, suma el contador y no pasa nada
                            dotQuantity++;
                        }else{
                            // Si la cantidad de puntos encontradas es mayor que 0, retorna FALSE
                            // (Por que habrian 2 puntos en el string, los decimales tienen 1 solo)
                            return FALSE;
                        }
                    }else{
                        // Si no es un punto, retorna FALSO inmediatamente
                        return FALSE;
                    }
                } else if (s[i] != '-') {
                    // Si ES el primer caracter, sera falso solo si NO es "-".
                    return FALSE;
                }
            }
        }
        return TRUE;
    }

#endif /* is_number_c */
