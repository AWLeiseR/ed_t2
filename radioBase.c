#include<stdlib.h>
#include<string.h>
#include <stdio.h>
typedef struct{
    char id[10];
    double x;
    double y;
    double sw;
    char cfill[20];
    char cstrk[20];
}Radio;

Radio* criaRadio(){
    Radio *radio=malloc(sizeof(radio));
}
void defineRadio(Radio *radio,char i[], double pX,double pY){
    
    strcpy(radio->id,i);
    radio->x=pX;
    radio->y=pY;
}

void defineCorRadio(Radio *radio, char pCfill[], char pCstrk[],double pSw){
    strcpy(radio->cfill,pCfill);
    strcpy(radio->cstrk,pCstrk);
    radio->sw=pSw;

}

char* deslocaRadio(Radio *radio, double dx, double dy){
    radio->x=radio->x+dx;
    radio->y=radio->y+dy;

    return radio->id;
}