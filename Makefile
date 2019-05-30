
CC = gcc
COMPILER_FLAGS = -std=c99
LINKER_FLAGS = -lm
OBJ_NAME = siguel


siguel: main.o 
	$(CC) main.o figuras.o lista.o quadra.o radioBase.o hidrante.o geofile.o semaforo.o svgFile.o qryFile.o geometria.o $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

main.o: main.c lista.o lista.h geofile.o geofile.h svgFile.o svgFile.h qryFile.o qryFile.h
	$(CC) -c main.c

qryFile.o: qryFile.c qryFile.h svgFile.o geometria.o
	$(CC) -c qryFile.c

geometria.o: geometria.c geometria.h lista.h
	$(CC) -c geometria.c

lista.o: lista.c lista.h figuras.o figuras.h quadra.o quadra.h radioBase.h hidrante.h semaforo.h
	$(CC) -c lista.c

figuras.o: figuras.c figuras.h geometria.o geometria.h
	$(CC) -c figuras.c

quadra.o: quadra.c quadra.h 
	$(CC) -c quadra.c

radioBase.o: radioBase.c radioBase.h 
	$(CC) -c radioBase.c

hidrante.o: hidrante.c hidrante.h 
	$(CC) -c hidrante.c

semaforo.o: semaforo.c semaforo.h 
	$(CC) -c semaforo.c

svgFile.o: svgFile.c svgFile.h 
	$(CC) -c svgFile.c

