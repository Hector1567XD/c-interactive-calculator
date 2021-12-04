vpath %.h ./include:../utils/include
vpath %.c ../commands:../utils

TARGET = calc
programa = execute-multiplicar.o get-inputed.o is-number.o pila.o execute-tangente.o execute-logaritmo.o execute-arctan.o\
					 create-program-context.o add-numeric-value.o execute-suma.o execute-coseno.o execute-arccoseno.o execute-seno.o execute-arcseno.o\
					 command-dispatch.o get-error.o get-command-by-input.o main.o
CFLAGS = -Wall


$(TARGET) : $(programa)
	gcc $(CFLAGS) $(programa) -o $(TARGET) -lm

.PHONY: clean
clean:
	@rm -f *.o $(TARGET)
