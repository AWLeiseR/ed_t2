#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    char id[10];
    double x;
    double y;
    double sw;
    char cfill[20];
    char cstrk[20];
}Semaforo;

Semaforo* criaSemaforo(){
    Semaforo *semaforo=malloc(sizeof(Semaforo));
}

void defineSemaforo(Semaforo *semaforo, char i[], double pX, double pY, char pCfill[], char pCstrk[],double pSw){
    strcmp(semaforo->id,i);
    semaforo->x=pX;
    semaforo->y=pY;
      strcpy(semaforo->cfill,pCfill);
    strcpy(semaforo->cstrk,pCstrk);
    semaforo->sw=pSw;

}

char* deslocaSemaforo(Semaforo *semaforo, double dx, double dy){
    semaforo->x=semaforo->x+dx;
    semaforo->y=semaforo->y+dy;

    return semaforo->id;
}

char* getSemaforoId(Semaforo *se){
    return se->id;
}

double getSemaforoX(Semaforo *se){
    return se->x;
}

double getSemaforoY(Semaforo *se){
    return se->y;
}

char* getSeamforoCfill(Semaforo *se){
    return se->cfill;
}

char* getSeamforoCstrk(Semaforo *se){
    return se->cstrk;
}