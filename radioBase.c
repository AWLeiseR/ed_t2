#include<stdlib.h>
#include<string.h>
#include <stdio.h>
typedef struct{
    char id[10];
    double x,y;
}Radio;

Radio* criaRadio(){
    Radio *radio=malloc(sizeof(radio));
}
void defineRadio(Radio *radio,char i[], double pX,double pY){
    
    strcpy(radio->id,i);
    radio->x=pX;
    radio->y=pY;
}

char* deslocaRadio(Radio *radio, double dx, double dy){
    radio->x=radio->x+dx;
    radio->y=radio->y+dy;

    return radio->id;
}