#ifndef _SVGFILE_H
#define _SVGFILE_H

//imprimir o cabecalho do svg
void cabecalho(FILE* arq);

//imprimir o rodape do svg
void rodape(FILE* arq);

//imprimi retangulo
void imprimirRetangulo(FILE* arq);

//imprimi Circulo
void imprimirCirculo(FILE* arq);

//imprimi ponto(circulo de raio 1 ou 0)
void imprimirPonto(FILE* arq);

#endif