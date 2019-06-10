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

int sobreposicaoCirculoCirculo(double x1, double y1, double r1, double x2, double y2,double r2,char cor[],FILE *arq3){
    int res;
    double x,y,h,w;
    //calcula a distancia entre os rcentros
    dis=distancia(x1,y1,x2,y2);
    //soma so raios
    raios=r1+r2;
    //verifica se a distancia é menos ou igual ao soma dos raios
    if(dis<=raios)
        res=1;
    else
        res=0;

    w=max(x1,x2)-min(x1,x2)+r1+r2;
                    
    h=max(y1,y2)-min(y1,y2)+r1+r2;
    imprimiRetangulodash(min(x1,x2)-max(r1,r2),min(y1,y2)-max(r1,r2),w,h,cor,arq3,res);
    return res;
}

int sobreposicaoCirculoRetangulo(double x1, double y1, double r1, double x2, double y2,double h2,double w2,char cor[],FILE *arq3){
    int res;
    double w,h;
    if(cx1<cx2+w2 && cx1+w1>cx2 && cy1<cy2+h2 && cy1+h1>cy2)
        res=1;
    w=max(cx1+w1,cx2+w2)-min(cx1,cx2);   
    h=max(cy1+h1,cy2+h2)-min(cy1,cy2);
    imprimiRetangulodash(min(cx1,cx2),min(cy1,cy2),w,h,cor,arq3,res);
    return res;
}

int sobreposicaoRetanguloRetangulo(double x1, double y1, double h1, double w1, double x2, double y2,double h2,double w2,char cor[],FILE *arq3){
    int res;
    double w,h;
    res=collision(cx1,cy1,w1,h1,cx2,cy2,r2);
    w=max(cx1+w1,cx2+r2)-min(cx1,cx2-r2);    
    h=max(cy1+h1,cy2+r2)-min(cy1,cy2-r2);
    imprimiRetangulodash(min(cx1,cx2-r2),min(cy1,cy2-r2),w,h,cor,arq3,res);
    return res;
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