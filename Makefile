
CC = gcc
COMPILER_FLAGS = -std=c99
LINKER_FLAGS = -lm
OBJ_NAME = siguel


siguel: main.o 
	$(CC) main.o figuras.o  lista.o  $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

main.o: main.c lista.o lista.h  
	$(CC) -c main.c

lista.o: lista.c lista.h figuras.o figuras.h quadra.o quadra.h radioBase.o hidrante.o 
	$(CC) -c lista.c

figuras.o: figuras.c figuras.h 
	$(CC) -c figuras.c

quadra.o: quadra.c quadra.h 
	$(CC) -c quadra.c

radioBase.o: radioBase.c radioBase.h 
	$(CC) -c radioBase.c

hidrante.o: hidrante.c hidrante.h 
	$(CC) -c hidrante.c