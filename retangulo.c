#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int id;
    double x;
    double y;
    char stroke[15];
    char fill[15];
    double strokeWidth;
    double h;
    double w;
}Retangulo;

Retangulo* criaRetangulo(){
    Retangulo *retangulo=malloc(sizeof(Retangulo));
}
void defineRetangulo(Retangulo *rec, double i, double pX, double pY, double pH, double pW, char pStroke[], char pFill[], double pStrokeWidth){
    printf("%lf,%lf,%lf,%s,%s,%lf,%lf",i,pX,pY,pStroke,pFill,pH,pW);
    rec->id=i;
    rec->x=pX;
    rec->y=pY;
   printf(">%s< \n",pStroke);
    strcpy(rec->stroke,pStroke);
    strcpy(rec->fill,pFill);
    rec->strokeWidth=pStrokeWidth;
    rec->h=pH;
    //rec->w=10.0;
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