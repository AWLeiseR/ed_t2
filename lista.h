
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
ListaFiguras createLista();

//inicializa a lista
void inicializaLista();

//retorna o tamanho da lista
int lenght(ListaFiguras list);

//insere um elemento na lista e retorna um indicador (ver sobre esse indicador)
int insert(ListaFiguras list, Item info);



//remove um elemento da lista 
void delet(ListaFiguras list, int p);

//define um retangulo
void setRetangulo(int id, double x, double y);

//define um circulo
void setCirculo(int id,double x, double y);

//define um quadra
void setQuadra(char cep [],Retangulo rec);

//define um hidrante
void setHidrante( int id,double x, double y);

//define um semafaro
void setSemafaro(int id,double x, double y);

//define uma radio-base
void setRadio(int id,double x, double y);

//retorna uma forma
Forma getForma();

//retorna a coordenada x de algum ponto
double getX();

//retorna a coordenada y de algum ponto
double getY();

#endif



