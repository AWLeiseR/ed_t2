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

void defineQuadra(Quadra *quadra, char pCep[],double pX, double pY, double pW, double pH,char pCfill[], char pCstrk[],double pSw){
    
    strcpy(quadra->cep,pCep);
    quadra->x=pX;
    quadra->y=pY;
    quadra->w=pW;
    quadra->h=pH;
    strcpy(quadra->cfill,pCfill);
    strcpy(quadra->cstrk,pCstrk);
    quadra->sw=pSw;
}


char* mudarCor(Quadra *quadra, char cstrk[]){
    strcpy(quadra->cstrk,cstrk);
    return quadra->cep;
}

char* deslocaQuadra(Quadra *quadra, double dx, double dy){
    
        quadra->x=quadra->x+dx;
        quadra->y=quadra->y+dy;

        return quadra->cep;  
}

char* getQuadraCep(Quadra *qua){
    return qua->cep;
}

double getQuadraX(Quadra *qua){
    return qua->x;
}

double getQuadraY(Quadra *qua){
    return qua->y;
}

char* getQuadraCfill(Quadra *qua){
    return qua->cfill;
}

char* getQuadraCstrk(Quadra *qua){
    return qua->cstrk;
}

void setQuadraX(Quadra *qua, double pX){
    qua->x=pX;
}

void setQuadraY(Quadra *qua, double pY){
    qua->y=pY;
}

void setQuadraCfill(Quadra *qua, char pCfill[]){
    qua->cfill=pCfill;
}

void setQuadraCstrk(Quadra *qua, char pCstrk[]){
    qua->cstrk=pCstrk;
}