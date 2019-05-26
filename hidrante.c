#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char id[10];
    double x;
    double y;
    double sw;
    char cfill[20];
    char cstrk[20];
}Hidrante;


Hidrante* criaHidrante(){
    Hidrante *hid=malloc(sizeof(Hidrante));
    return hid;
}

void defineHidrante(Hidrante* hidrante, char i[], double pX, double pY){
    strcpy(hidrante->id,i);
    hidrante->x=pX;
    hidrante->y=pY;
}

void defineCorHidrante(Hidrante *hidrante, char pCfill[], char pCstrk[],double pSw){
    strcpy(hidrante->cfill,pCfill);
    strcpy(hidrante->cstrk,pCstrk);
    hidrante->sw=pSw;

}

char* deslocaHidrante(Hidrante *hidrante, double dx, double dy){
    
        hidrante->x=hidrante->x+dx;
        hidrante->y=hidrante->y+dy;

        return hidrante->id;
    
    
}