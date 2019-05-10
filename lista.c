#include"lista.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char tipo;
    double x,y;
    double h,w;
}Retangulo;


typedef struct{
    Retangulo forma;
    int ant;
    int prox
}Item;

typedef struct{
    Item* info;
    int primeiro;
    int livre;
    int ultimo;
}*ListaFiguras;

ListaFiguras criaLista(int tam){
    ListaFiguras lista= malloc(sizeof(ListaFiguras));
    lista->info = malloc(sizeof(Item)*tam);
    lista->livre=0;
    lista->primeiro=0;
    lista->ultimo=tam-1;
    return lista;

}