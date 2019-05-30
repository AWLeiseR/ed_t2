#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"geometria.h"


typedef struct{
    int id;
    double x;
    double y;
    double r;
    char stroke[15];
    char fill[15];
    double strokeWidth;
    
}Circulo;

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

Circulo* criaCirculo(){
    Circulo *cir=malloc(sizeof(Circulo));
    return cir;

}

Retangulo* criaRetangulo(){
    Retangulo *retangulo=malloc(sizeof(Retangulo));
}

void defineCirculo(Circulo *circulo,int i,double pX,double pY, double pR,char pStroke[], char pFill[],double pStrokeWidth){
    
    circulo->id=i;
    circulo->x=pX;
    circulo->y=pY;
    circulo->r=pR;
   strcpy(circulo->stroke,pStroke);
}

void defineRetangulo(Retangulo *rec, double i, double pX, double pY, double pH, double pW, char pStroke[], char pFill[], double pStrokeWidth){
    //printf("%lf,%lf,%lf,%s,%s,%lf,%lf",i,pX,pY,pStroke,pFill,pH,pW);
    rec->id=i;
    rec->x=pX;
    rec->y=pY;
   //printf(">%s< \n",pStroke);
    strcpy(rec->stroke,pStroke);
    strcpy(rec->fill,pFill);
    rec->strokeWidth=pStrokeWidth;
    rec->h=pH;
    //rec->w=10.0;
}



void deslocaCirculo(double dx, double dy){
  double cx,cy;
    cx=cx+dx;
    cy=cy+dy;
}

void deslocaRetangulo(double dx, double dy){
    double cx,cy;
    cx=cx+dx;
    cy=cy+dy;
}

int getCirculoId(Circulo *cir){
    return cir->id;
}

double getCirculoX(Circulo *cir){
    return cir->x;
}

double getCirculoY(Circulo *cir){
    return cir->y;
}

double getCirculoR(Circulo *cir){
    return cir->r;
}

char* getCirculoCfill(Circulo *cir){
    return cir->stroke;
}

char* getCirculoCstrk(Circulo *cir){
    return cir->fill;
}

int getRetanguloId(Retangulo *rec){
    return rec->id;
}

double getRetanguloX(Retangulo *rec){
    return rec->x;
}

double getRetanguloY(Retangulo *rec){
    return rec->y;
}

double getRetanguloH(Retangulo *rec){
    return rec->h;
}

double getRetanguloW(Retangulo *rec){
    return rec->w;
}

char* getRetanguloCfill(Retangulo *rec){
    return rec->stroke;
}

char* getRetanguloCstrk(Retangulo *rec){
    return rec->fill;
}