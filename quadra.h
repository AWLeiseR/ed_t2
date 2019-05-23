#ifndef _QUADRA_H
#define _QUADRA_H
typedef void* Quadra;

Quadra* criaQuadra();

//define uma quadrass
void defineQuadra(char pCep[],double pX, double pY, double pW, double pH);
//muda a cor do stroke e retorna um ponteiro para o cep
char* mudarCor(Quadra quadra, char cstrk[]);
//desloca a quadra e retorna um ponteiro para cep
char* deslocaQuadra(Quadra quadra, double dx, double dy)

#endif