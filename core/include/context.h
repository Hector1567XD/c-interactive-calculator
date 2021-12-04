#ifndef context_h
#define context_h

  #include "../../utils/include/pila.h"

  typedef struct context {
      char input[65];
      char* command;
      char* response;
      int error;
      Pila* numberStack;
  } Context;

#endif
