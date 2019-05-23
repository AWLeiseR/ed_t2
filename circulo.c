#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int id;
    double x;
    double y;
    double r;
    char stroke[15];
    char fill[15];
    double stroke_width;
    
}Circulo;

Circulo* criaCirculo(){
    Circulo *cir=malloc(sizeof(Circulo));
    return cir;

}
void defineCirculo(Circulo *circulo,int i,double pX,double pY, double pR,char pStroke[], char pFill[],double pStroke_width){
    
    circulo->id=i;
    circulo->x=pX;
    circulo->y=pY;
    circulo->r=pR;
   strcpy(circulo->stroke,pStroke);
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