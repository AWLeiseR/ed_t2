#ifndef _RADIOBASE_H
#define _RADIOBASE_H
typedef void* Radio;
//aloca um radio
Radio* criaRadio();
//define uma torre radio
void defineRadio(Radio *radio,char i[], double px, double pY);

void defineCorRadio(Radio *radio, char pCfill[], char pCstrk[],double pSw);
//desloca radio e retorna um ponteiro para o id
char* deslocaRadio(Radio *radio, double dx, double dy);
#endif