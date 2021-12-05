vpath %.h ./core/include:./utils/include:./utils/include
vpath %.c ./core:./commands:./utils

TARGET = calc
programa = execute-multiplicar.o get-inputed.o is-number.o pila.o\
				   execute-tangente.o execute-logaritmo.o execute-arctan.o execute-swap.o\
				   create-program-context.o add-numeric-value.o\
				   execute-suma.o execute-resta.o execute-dividir.o\
				   execute-coseno.o execute-arccoseno.o execute-seno.o execute-arcseno.o\
			     execute-potencia.o -lm execute-raiz.o -lm execute-factorial.o -lm\
				   execute-cima.o execute-display.o execute-clear.o\
					 execute-binary.o execute-octal.o execute-hexadecimal.o execute-decimal.o execute-octal-to-decimal.o\
					 execute-memory-recall.o execute-memory-store.o execute-memory-suma.o execute-memory-resta.o\
				   command-dispatch.o get-error.o get-command-by-input.o\
				   execute-program.o interactive-mode.o shell-mode.o main.o

CFLAGS = -Wall


$(TARGET) : $(programa)
	gcc $(CFLAGS) $(programa) -o $(TARGET) -lm

.PHONY: clean
clean:
	@rm -f *.o $(TARGET)
