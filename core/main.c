#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./include/commands.h"
#include "../utils/include/pila.h"
#include "../utils/pila.c"

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
    char inputUser[65] = "";
    Pila* pilaNumeros = CrearPila();

    while (programIsRunning == TRUE) {
        printf(">");
        // Test Change (Remove this commeeent pls)
        // Mecanismo super complicado de input (TODO: Refactorizar)
        fgets(inputUser, sizeof(inputUser), stdin);
        // Newline does not exist
        if(!strchr(inputUser, '\n')) {
            printf("Error: se ha ingresado mas caracteres de los permitidos\n");
            printf("       solo se tomaran caracteres hasta el limite permitido (%d)\n", sizeof(inputUser) - 1);
            while(fgetc(stdin)!='\n');  // Discard until newline
        }
        fflush(stdin);

        // Limpia el \n al final del inputUser (si existe)
        inputUser[strcspn(inputUser, "\n")] = 0;

        if (!isValidInput(inputUser)) {
            printf(">Accion invalida.\n");
            continue;
        }

        if (strcmp(inputUser, QUIT_COMMAND) == 0)
        {
            programIsRunning = FALSE;
            break;
        }
        else
        {
            if (isNumber(inputUser)) {
                Apilar(pilaNumeros, atoi(inputUser));
            }
        }
    }

    printf("%d", Cima(pilaNumeros));

    return 0;
}
