
#ifndef _LISTA_H
#define _LISTA_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"figuras.h"
#include"quadra.h"
#include"semaforo.h"
#include"hidrante.h"
#include"radioBase.h"

typedef void* Forma;

typedef void* Item;

typedef void* ListaFiguras;

//cria lista e retorna o ponteiro p/ inicio da lista
ListaFiguras* createLista();

//inicializa a lista
void inicializaLista();

//retorna o tamanho da lista
int lenght(ListaFiguras *list);

//insere um elemento na lista e retorna um indicador (ver sobre esse indicador)
int insert(ListaFiguras *list, Item info);



//remove um elemento da lista 
void delet(ListaFiguras *list, int p);
//desaloca a lista
void freeList(ListaFiguras *list);

void imprimir(ListaFiguras *list);

//busca
int buscaChar(ListaFiguras* list, char id[]);


#endif



