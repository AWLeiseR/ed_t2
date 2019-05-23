#ifndef _HIDRANTE_H
#define _HIDRANTE_H
typedef void* Hidrante;

Hidrante* criaHidrante();

//define hidrante
void defineHidrante(Hidrante hidrante, int i, double pX, double pY);
//desloca hidrante e retorna um ponteiro para o id
char* deslocaHidrante(Hidrante hidrante, double dx, double dy);
#endif