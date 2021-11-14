#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/include/pila.h"
#include "../utils/pila.c"

#include "./include/commands.h"
#include "./include/errors.h"

#include "./input-handler.c"

/*
    Primer prototipo xP
    TODO:
    - Pila de numeros ✅
    - Agregar numeros ✅
    - Resolver acciones ✅
    - Accion QUIT ✅
    - Validaciones ✅ //Mas de 256 ✅
    - Debe aceptar numeros negativos ✅
*/

const TRUE = 1;
const FALSE = 0;

/*int stringEqual(s1, s2) {
    return (strcmp(s, "-") == 0);
}*/

int isNumber(char s[])
{
    int length = strlen(s);
    if (strcmp(s, "-") == 0) return FALSE; // Caso borde: "-"
    if (strlen(s) < 1) return FALSE; // Caso borde: ""
    for (int i = 0; s[i]!= '\0' && i < length; i++)
    {
        // Si es un digito, ignorar este IF
        if (!isdigit(s[i])) {
            if (i > 0) {
                // Si NO es el primer caracter, es falso inmediatamente.
                return FALSE;
            } else if (s[i] != '-') {
                // Si ES el primer caracter, sera falso solo si NO es "-".
                return FALSE;
            }
        }
    }
    return TRUE;
}

int isValidInput(char s[]) {
    if (isNumber(s)) return TRUE;
    if (strcmp(s, QUIT_COMMAND) == 0) return TRUE;
    return FALSE;
}

int main()
{
    int programIsRunning = TRUE;
    Pila* pilaNumeros = CrearPila();
    char input[65] = "";
    int error = NO_ERRORS;

    while (programIsRunning == TRUE) {
        error = NO_ERRORS;
        printf(">");

        getInputedString(input, sizeof(input), &error);
        if(error == INPUT_MAX_LENGTH_ERROR) {
            printf("Error: se ha ingresado mas caracteres de los permitidos\n      solo se tomaran caracteres hasta el limite permitido (%d)\n", sizeof(inputUser) - 1);
        }

        if (!isValidInput(input)) {
            printf(">Accion invalida.\n");
            continue;
        }

        if (strcmp(input, QUIT_COMMAND) == 0)
        {
            programIsRunning = FALSE;
            break;
        }
        else
        {
            if (isNumber(input)) {
                Apilar(pilaNumeros, atoi(input));
            }
        }
    }

    printf("%d", Cima(pilaNumeros));

    return 0;
}
