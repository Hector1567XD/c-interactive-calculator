vpath %.h ./include:../utils/include
vpath %.c ../commands:../utils

TARGET = prog
OBJ-DIR = ../obj
programa = main.o command-dispatch.o get-error.o get-command-by-input.o\
					 create-program-context.o add-numeric-value.o execute-suma.o\
					 execute-multiplicar.o get-inputed.o is-number.o pila.o
CFLAGS = -Wall


$(TARGET) : $(programa)
	gcc $(CFLAGS) $(programa) -o $(TARGET)

$(OBJ-DIR)/%.o : %.c
	mkdir -f $(OBJ-DIR)
	gcc -c -MD $(CFLAGS) $< -o $@

-include $(OBJ-DIR)*.d

#-I func1 -I func2

.PHONY: clean
clean:
	rm -f *.o $(TARGET)
