#ifndef _CIRCULO_H
#define _CIRCULO_H

typedef void* Circulo;
//aloca o circulo
Circulo* criaCirculo();

void defineCirculo(Circulo circulo,int i,double pX,double pY, double pR,char pStroke[], char pFill[],double pStroke_width);

//retorna 1 se o ponto for interior e 0 se for externo
//int pontoInternoCirculo(double px, double py, double cx, double cy, double r);
//desloca a figura em x e y
void deslocaCirculo(double dx, double dy);
#endif