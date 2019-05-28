
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"figuras.h"
#include"quadra.h"
#include"semaforo.h"
#include"hidrante.h"
#include"radioBase.h"
 


typedef struct{
    char tipo;
    union{
        Retangulo *retangulo;
        Circulo *circulo;
        Quadra *quadra;
        Hidrante *hidrantes;
        Semaforo *semaforo;
        Radio *radio;
    };
}Forma;

typedef struct{
    Forma *forma;
    int ant;
    int prox;
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
    aux->info[tam_lista-1].prox=-1;
    return lista;
}

int lenght(ListaFiguras* list){
    int i=0;
    int primeiro;
    primeiro=list->primeiro;
    ListaFiguras* aux;
    aux=list;
    while(1){
        if(aux->info[aux->primeiro].prox!=-1){
            aux->primeiro=aux->info[aux->primeiro].prox;
            i++;
        }else{
            i++;
            break;
        }        
    }
    list->primeiro=primeiro;
    return i;
}
   

int insert(ListaFiguras* list, Forma* info){
    Forma* nItem;
    nItem=info;
    int n;
    int n1;
    int antLivre;
    n1=list->livre;
    antLivre=n1-1;
    n=list->info[list->livre].prox;
    if(list->primeiro==-1){
        list->primeiro=n1;
    }else{
        list->info[antLivre].prox=list->livre;  
    }
    list->info[list->livre].prox=-1;
    list->info[list->livre].forma=nItem;
    list->info[list->livre].ant=list->ultimo;
    list->livre=n;
    list->ultimo=n1;
    return n1;
}
void imprimir(ListaFiguras* list){
    int i=0;
    int primeiro;
    primeiro=list->primeiro;
    while(1){
        if(list->info[list->primeiro].prox!=-1){
            printf("anterior[%d] proximo[%d]\n",list->info[list->primeiro].ant,list->info[list->primeiro].prox);
            list->primeiro=list->info[list->primeiro].prox;
        }else{
            printf("anterior[%d] proximo[%d]\n",list->info[list->primeiro].ant,list->info[list->primeiro].prox); 
            break;
        }
    }
    list->primeiro=primeiro;
}

void delet(ListaFiguras* list, int p){
    int antLivre;
    antLivre=list->livre;
    if(list->primeiro == p && list->ultimo==p){
        list->info[p].prox=list->livre;
        list->primeiro=-1;
        list->ultimo=-1;
    }else if(list->primeiro == p){
        list->info[list->info[p].prox].ant=-1;
        list->primeiro=list->info[p].prox;
        list->info[p].prox=list->livre;
    }else if(list->ultimo==p){
        list->info[p].prox=list->livre;
        list->info[list->info[p].ant].prox=-1;
        list->ultimo=list->info[p].ant;
    }else{
        list->info[list->info[p].prox].ant=list->info[p].ant;
        list->info[list->info[p].ant].prox=list->info[p].prox;
        
    } 
    list->livre=p;   
}

void freeList(ListaFiguras *list){
    free(list->info);
    free(list);
}
//arrumar
int buscaCep(ListaFiguras* list, char cep[]){
    int i;
    int tam;
    tam=lenght(list);
    for(i=0;i<tam;i++){
        //strcmp(cep,list->info[i].forma->quadra);
        if(i){
            break;
        }
    }
    return i;
}



Item* setRetangulo(Retangulo *rec){
    Item *item;
    item=malloc(sizeof(Item));
    item->forma->tipo='r';
    item->forma->retangulo=rec;
    return item;
}

Item* setCirculo(Circulo *cir){
    Item *item=malloc(sizeof(Item));
    item->forma->tipo='c';
    item->forma->circulo=cir;
    return item;
}

void setQuadra(char cep [],Quadra quadra){

}

void setHidrante( int id,double x, double y){

}

void setSemafaro(int id,double x, double y){

}

void setRadio(int id,double x, double y){

}

Forma getForma(){

}

double getX(){

    return 0.00;
}
double getY(){

    return 0.00;
}

