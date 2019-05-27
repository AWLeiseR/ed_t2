#ifndef _SVGFILE_H
#define _SVGFILE_H

//imprimir o cabecalho do svg
void cabecalho(FILE* arq);

//imprimir o rodape do svg
void rodape(FILE* arq);

//imprimi retangulo
void criaRetangulo(FILE* arq);

//imprimi Circulo
void criaCirculo(FILE* arq);

//imprimi ponto(circulo de raio 1 ou 0)
void criaPonto(FILE* arq);

void criaLinha(double x1,double y1,double x2, double y2, FILE *arq);

void criaRetangulodash(double x, double y, double w, double h, char stroke[], FILE *arq, int res);

void criaTexto(double x, double y, char texto[], FILE *arq);

void criaSvgbb(ListaFiguras *,char *dirsaida,char sufixo[],char cor[],int nx,char sufixogeo[]);

void criaSvg(ListaFiguras *listFig,ListaFiguras *listQua,ListaFiguras *listRad,ListaFiguras *listHid,ListaFiguras *listSem,char saida[]);

#endif