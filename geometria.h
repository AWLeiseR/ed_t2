#ifndef __GEOMETRIA_H
#define __GEOMETRIA_H


//retorna 1 se o ponto for interior e 0 se for externo
int pontoInteriorRetangulo(double px, double py, double cx1, double cy1, double cx2, double cy2);
//retorna 1 se o ponto for interior e 0 se for externo
int pontoInternoCirculo(double px, double py, double cx, double cy, double r);
//calcula/retorna distancia entre dois pontos
double distancia (double x1, double y1, double x2, double y2);
//verifica se as formas estao sobre postas
int sobreposicaoCirculoCirculo(double x1, double y1, double r1, double x2, double y2,double r2,char cor[],FILE *arq3);

int sobreposicaoCirculoRetangulo(double x1, double y1, double r1, double x2, double y2,double h2,double w2,char cor[],FILE *arq3);

int sobreposicaoRetanguloRetangulo(double x1, double y1, double h1, double w1, double x2, double y2,double h2,double w2,char cor[],FILE *arq3);
//calcula o maior numero ente n1 e n2
double max(double n1,double n2);
//calcula o menor numero ente n1 e n2
double min(double n1,double n2);
//verirfica se ha colisao ou nao, retorna 1 para sim e 0 para nao
int collision(double recX,double recY,double recW,double recH,double cX,double cY,double cR);

#endif