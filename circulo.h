#ifndef _CIRCULO_H
#define _CIRCULO_H

typedef void* Circulo;
//retorna 1 se o ponto for interior e 0 se for externo
int pontoInternoCirculo(double px, double py, double cx, double cy, double r);
//desloca a figura em x e y
void deslocaCirculo(double dx, double dy);
#endif