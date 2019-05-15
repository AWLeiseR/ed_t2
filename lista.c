#include"lista.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
#define tam_lista 10000

typedef struct{
   
    double h,w;
}Retangulo;

typedef struct{
   
    double r;
}Circulo;

typedef struct{
    Retangulo retangulo;
    char cep[10];
}Quadra;

typedef struct{
    int id;
    double x,y;
}Hidrante;

typedef struct{
    int id;
    double x,y;
}Semaforo;

typedef struct{
    char tipo;
    double x,y;
    union{
        Retangulo retangulo;
        Circulo circulo;
        Quadra quadra;
    }
}
typedef struct{
    Forma *forma;
    int ant;
    int prox
}Item;

typedef struct{
    Item* info;
    int primeiro;
    int livre;
    int ultimo;
}ListaFiguras;

ListaFiguras* createLista(){
    int i=0 ;
    ListaFiguras* aux;
    ListaFiguras* lista= malloc(sizeof(ListaFiguras));
    lista->info = malloc(sizeof(Item)*tam_lista);
    lista->livre=0;
    lista->primeiro=-1;
    lista->ultimo=-1;
    aux=lista;
    for(i=0;i<tam_lista;i++){
        aux->info[i].prox=1+i;
    }
    aux.info[tam_lista-1].prox=-1;
    return lista;
}

int lenght(listaFiguras* list){
    int i=0;
    ListaFiguras aux;
    aux=list->primeiro;
    while(1){
        if(aux.prox!=-1){
            aux=aux->info[aux].prox;
            i++;
        }else{
            break;
        }        
    }
    return i;
}

int insert(listaFiguras* list, Info info){
    Info nItem;
    list->info[list.livre]=;
}