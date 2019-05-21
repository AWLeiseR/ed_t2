#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int id;
    double x,y;
    char stroke[15];
    char fill[15];
    double stroke_width;
    double h,w;
}Retangulo;

void defineRetangulo(int i, double pX, double pY,char pStroke[],char pFill[],double pStroke_width,double pH, double pW){
    Retangulo rec;
    rec.id=i;
    rec.x=pX;
    rec.y=pY;
    strcpy(rec.stroke,pStroke);
    strcpy(rec.fill,pFill);
    rec.stroke_width=pStroke_width;
    rec.h=pH;
    rec.w=pW;
}

int pontoInteriorRetangulo(double px, double py, double cx1, double cy1, double cx2, double cy2){
    if(px>=cx1 && px<=cx2 && py>=cy1 && py<=cy2)
        return 1;
    else
        return 0;
} 

void deslocaRetangulo(double dx, double dy){
    double cx,cy;
    cx=cx+dx;
    cy=cy+dy;
}