#ifndef _HIDRANTE_H
#define _HIDRANTE_H
typedef void* Hidrante;

Hidrante* criaHidrante();

//define hidrante
void defineHidrante(Hidrante *hidrante, char i[], double pX, double pY);

void defineCorHidrante(Hidrante *hidrante, char pCfill[], char pCstrk[],double pSw);
//desloca hidrante e retorna um ponteiro para o id
char* deslocaHidrante(Hidrante *hidrante, double dx, double dy);
#endif