vpath %.h ./core/include:./utils/include:./utils/include
vpath %.c ./core:./commands:./utils

TARGET = calc
programa = execute-multiplicar.o get-inputed.o is-number.o pila.o\
					 create-program-context.o add-numeric-value.o execute-suma.o\
					 command-dispatch.o get-error.o get-command-by-input.o\
					 execute-program.o interactive-mode.o shell-mode.o main.o
CFLAGS = -Wall


$(TARGET) : $(programa)
	gcc $(CFLAGS) $(programa) -o $(TARGET)

.PHONY: clean
clean:
	@rm -f *.o $(TARGET)
