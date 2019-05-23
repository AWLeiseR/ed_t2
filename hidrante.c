#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char id[10];
    double x,y;
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

char* deslocaHidrante(Hidrante *hidrante, double dx, double dy){
    
        hidrante->x=hidrante->x+dx;
        hidrante->y=hidrante->y+dy;

        return hidrante->id;
    
    
}