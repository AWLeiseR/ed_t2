#ifndef _SEMAFARO_H
#define _SEMAFARO_H
//define um semaforo
typedef void* Semaforo;
//define semaforo
void defineSemaforo(int i, double pX, double pY);
//desloca o semaforo e retorna um ponteiro para o id 
char* deslocaSemaforo(Semaforo semaforo, double dx, double dy);
#endif