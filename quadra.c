#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char cep[20];
    double x;
    double y;
    double w;
    double h;
    double sw;
    char cstrk[20];
    char cfill[20];
}Quadra;

Quadra* criaQuadra(){
    Quadra* qua=malloc(sizeof(Quadra));
    return qua;
}

void defineQuadra(char pCep[],double pX, double pY, double pW, double pH){
    Quadra quadra;
    strcpy(quadra.cep,pCep);
    quadra.x=pX;
    quadra.y=pY;
    quadra.w=pW;
    quadra.h=pH;
}

char* mudarCor(Quadra quadra, char cstrk[]){
    strcpy(quadra.cstrk,cstrk);
    return quadra.cep;
}

char* deslocaQuadra(Quadra *quadra, double dx, double dy){
    
        quadra->x=quadra->x+dx;
        quadra->y=quadra->y+dy;

        return quadra->cep;
    
    
}