
CC = gcc
COMPILER_FLAGS = -std=c99
LINKER_FLAGS = -lm
OBJ_NAME = siguel


siguel: main.o 
	$(CC) main.o retangulo.o circulo.o lista.o  $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

main.o: main.c lista.o retangulo.o circulo.o
	$(CC) -c main.c

lista.o: lista.c lista.h retangulo.o retangulo.h circulo.o 
	$(CC) -c lista.c

retangulo.o: retangulo.c retangulo.h 
	$(CC) -c retangulo.c

circulo.o: circulo.c circulo.h 
	$(CC) -c circulo.c