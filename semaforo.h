#ifndef _SEMAFARO_H
#define _SEMAFARO_H
//define um semaforo
typedef void* Semaforo;
//aloca semaforo
Semaforo* criaSemaforo();
//define semaforo
Semaforo* defineSemaforo(Semaforo *semaforo,int i, double pX, double pY);

void defineCorSemaforo(Semaforo *semaforo, char pCfill[], char pCstrk[],double pSw);
//desloca o semaforo e retorna um ponteiro para o id 
char* deslocaSemaforo(Semaforo *semaforo, double dx, double dy);
#endif