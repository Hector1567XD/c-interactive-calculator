vpath %.h ./include:../utils/include
vpath %.c ../commands:../utils

TARGET = calc
programa = execute-multiplicar.o get-inputed.o is-number.o pila.o\
					 create-program-context.o add-numeric-value.o execute-suma.o execute-resta.o execute-dividir.o\
					 execute-potencia.o -lm execute-raiz.o -lm execute-factorial.o -lm execute-cima.o execute-display.o\
					 command-dispatch.o get-error.o get-command-by-input.o main.o
CFLAGS = -Wall


$(TARGET) : $(programa)
	gcc $(CFLAGS) $(programa) -o $(TARGET)

.PHONY: clean
clean:
	@rm -f *.o $(TARGET)
