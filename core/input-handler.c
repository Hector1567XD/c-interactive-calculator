#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./include/errors.h"

void getInputedString(char *receiver, int max_length, int *error)
{
    char input[] = "";
    *error = NO_ERRORS;
    fgets(input, max_length, stdin);

    /* Si NO encuentra un line break en el receiver
     * elimina el sobrante del fgetc en stdin */
    if(!strchr(input, '\n')) {
        *error = INPUT_MAX_LENGTH_ERROR;
        while(fgetc(stdin)!='\n');
    }else{
        // Elimina el '\n' al final del receiver
        input[strcspn(input, "\n")] = 0;
    }
    fflush(stdin);
    strcpy(receiver, input);
}
