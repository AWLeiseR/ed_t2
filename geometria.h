#ifndef __GEOMETRIA_H
#define __GEOMETRIA_H

//calcula/retorna distancia entre dois pontos
double distancia (double x1, double y1, double x2, double y2);
//verifica se as formas estao sobre postas
int sobreposicao(Formas forma1,Formas forma2,FILE *arq3);
//calcula o maior numero ente n1 e n2
double max(double n1,double n2);
//calcula o menor numero ente n1 e n2
double min(double n1,double n2);
//verirfica se ha colisao ou nao, retorna 1 para sim e 0 para nao
int collision(double recX,double recY,double recW,double recH,double cX,double cY,double cR);

#endif