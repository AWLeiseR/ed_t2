#ifndef _RETANGULO_H
#define _RETANGULO_H
//declaração de retangulo
typedef void* Retangulo;

//define um retangulo
void defineRetangulo(int i, double pX, double pY,char pStroke[],char pFill[],double pStroke_width,double pH, double pW);

//retorna 1 se o ponto for interior e 0 se for externo
int pontoInteriorRetangulo(double px, double py, double cx1, double cy1, double cx2, double cy2);

void deslocaRetangulo(double dx, double dy);
#endif