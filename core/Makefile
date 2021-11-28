vpath %.h ./include:../utils/include
vpath %.c ../commands:../utils

TARGET = prog
OBJ-DIR = ../obj
programa = pila.o main.o
CFLAGS = -Wall


$(TARGET) : $(programa)
	gcc $(CFLAGS) pila.o main.o -o $(TARGET)

$(OBJ-DIR)/%.o : %.c
	mkdir -p $(OBJ-DIR)
	gcc -c -MD $(CFLAGS) $< -o $@

-include $(OBJ-DIR)*.d

#-I func1 -I func2

.PHONY: clean
clean:
	rm -f *.o $(TARGET)
