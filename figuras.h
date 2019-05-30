#ifndef _FIGURAS_H
#define _FIGURAS_H
typedef void* Circulo;
//aloca o circulo
Circulo* criaCirculo();

void defineCirculo(Circulo circulo,int i,double pX,double pY, double pR,char pStroke[], char pFill[],double pStrokeWidth);


//desloca a figura em x e y
void deslocaCirculo(double dx, double dy);


//declaração de retangulo
typedef void* Retangulo;
//aloca um retangulo
Retangulo* criaRetangulo();

//define um retangulo
void defineRetangulo(Retangulo rec, double i, double pX, double pY, double pH, double pW, char pStroke[], char pFill[], double pStrokeWidth);



void deslocaRetangulo(double dx, double dy);

int getCirculoId(Circulo *cir);

double getCirculoX(Circulo *cir);

double getCirculoY(Circulo *cir);

double getCirculoR(Circulo *cir);

char* getCirculoCfill(Circulo *cir);

char* getCirculoCstrk(Circulo *cir);

double getRetanguloX(Retangulo *rec);

double getRetanguloY(Retangulo *rec);

double getRetanguloW(Retangulo *rec);

double getRetanguloH(Retangulo *rec);

int getRetanguloId(Retangulo *rec);

char* getRetanguloCfill(Retangulo *rec);

char* getRetanguloCstrk(Retangulo *rec);

#endif