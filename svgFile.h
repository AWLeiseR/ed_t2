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

void criaLinha();

#endif