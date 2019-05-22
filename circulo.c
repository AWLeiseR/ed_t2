#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int id;
    double x,y;
    double r;
    char stroke[15];
    char fill[15];
    double stroke_width;
    
}Circulo;

void defineCirculo(int i,double pX,double pY, double pR,char pStroke[], char pFill[],double pStroke_width){
    Circulo circulo;
    circulo.id=i;
    circulo.x=pX;
    circulo.y=pY;
    circulo.r=pR;
    strcpy(circulo.stroke,pStroke);
}

/*int pontoInternoCirculo(double px, double py, double cx, double cy, double r){
    double d = distancia (px,py,cx,cy);
    int res = d <= r? 1:0;
    return res;
}*/

void deslocaCirculo(double dx, double dy){
  double cx,cy;
    cx=cx+dx;
    cy=cy+dy;
}