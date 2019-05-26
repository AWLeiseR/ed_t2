#ifndef _FIGURAS_H
#define _FIGURAS_H
typedef void* Circulo;
//aloca o circulo
Circulo* criaCirculo();

void defineCirculo(Circulo circulo,int i,double pX,double pY, double pR,char pStroke[], char pFill[],double pStrokeWidth);

//retorna 1 se o ponto for interior e 0 se for externo
//int pontoInternoCirculo(double px, double py, double cx, double cy, double r);
//desloca a figura em x e y
void deslocaCirculo(double dx, double dy);


//declaração de retangulo
typedef void* Retangulo;
//aloca um retangulo
Retangulo* criaRetangulo();

//define um retangulo
void defineRetangulo(Retangulo rec, double i, double pX, double pY, double pH, double pW, char pStroke[], char pFill[], double pStrokeWidth);

//retorna 1 se o ponto for interior e 0 se for externo
int pontoInteriorRetangulo(double px, double py, double cx1, double cy1, double cx2, double cy2);

void deslocaRetangulo(double dx, double dy);

#endif