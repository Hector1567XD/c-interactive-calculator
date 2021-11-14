#ifndef get_inputed_c
    #define get_inputed_c

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #include "../core/include/errors.h"
    #include "../core/include/constans.h"

    void getInputed(char *receiver, int *error)
    {
        // TODO: replace 65 for MAX_LENGTH+1
        char input[65] = "";
        *error = NO_ERRORS;
        fgets(input, sizeof(input), stdin);

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

#endif /* get_inputed_c */
