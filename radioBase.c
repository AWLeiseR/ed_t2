#include<stdlib.h>
#include<string.h>
#include <stdio.h>
typedef struct{
    char id[30];
    double x;
    double y;
    double sw;
    char cfill[20];
    char cstrk[20];
}Radio;

Radio* criaRadio(){
    Radio *radio=malloc(sizeof(radio));
}
void defineRadio(Radio *radio,char i[], double pX,double pY, char pCfill[], char pCstrk[],double pSw){
    
    strcpy(radio->id,i);
    radio->x=pX;
    radio->y=pY;
     strcpy(radio->cfill,pCfill);
    strcpy(radio->cstrk,pCstrk);
    radio->sw=pSw;
}

char* deslocaRadio(Radio *radio, double dx, double dy){
    radio->x=radio->x+dx;
    radio->y=radio->y+dy;

    return radio->id;
}

char* getRadioId(Radio *radio){
    return radio->id;
}

double getRadioX(Radio *radio){
    return radio->x;
}

double getRadioY(Radio *radio){
    return radio->y;
}

char* getRadioCfill(Radio *radio){
    return radio->cfill;
}

char* getRadioCstrk(Radio *radio){
    return radio->cstrk;
}

void setSemaforoX(Semaforo *se, double pX){
    se->x=pX;
}

void setSemaforoY(Semaforo *se, double pY){
    se->y=pY;
}

void setSemaforoCfill(Semaforo *se, char pCfill[]){
    se->cfill=pCfill;
}

void setSemaforoCstrk(Semaforo *se, char pCstrk[]){
    se->cstrk=pCstrk;
}