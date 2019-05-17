
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
}Semafaro;

typedef struct{
    int id;
    double x,y;
}Radio;

typedef struct{
    char tipo;
    double x,y;
    union{
        Retangulo retangulo;
        Circulo circulo;
        Quadra quadra;
        Hidrante hidrantes;
        Semafaro semafaro;
        Radio radio;
    }
}Forma;

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
    if(list->primeiro != p){
        list->info[p-1].prox=p+1;
        list->info[p+1].ant=p-1;
    }    
    list->info[p].prox=list->livre;
    list->info[p].ant=-1;
    list->livre=p;
}

void setRetangulo(){

}

void setCirculo(){

}

void setQuadra(){

}

void setHidrante(){

}

void setSemafaro(){

}

void setRadio(){

}

Retangulo getRetangulo(){

}

Circulo getCirculo(){

}

Quadra getQuadra(){

}

Hidrante getHidrante(){

}

Semafaro getSemafaro(){

}

Radio getRadio(){

}

double getX(){

    return double;
}
double getY(){

    return double;
}

