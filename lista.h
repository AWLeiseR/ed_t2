
#ifndef _LISTA_H
#define _LISTA_H

typedef void Retangulo;

typedef void Circulo;

typedef void Hidrante;

typedef void Quadra;

typedef void Radio;

typedef void Semafaro;

typedef void Forma;

typedef void Item;

typedef void ListaFiguras;

//cria lista e retorna o ponteiro p/ inicio da lista
listaFigutas createLista();

//inicializa a lista
void inicializaLista();

//retorna o tamanho da lista
int lenght(listaFiguras list);

//insere um elemento na lista e retorna um indicador (ver sobre esse indicador)
int insert(listaFiguras list, Info info);



//remove um elemento da lista 
void delet(listaFiguras list, Posic p);

#endif



