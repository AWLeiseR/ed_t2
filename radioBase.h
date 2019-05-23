#ifndef _RADIOBASE_H
#define _RADIOBASE_H
typedef void* Radio;
//define uma torre radio
void defineRadio(int i, double px, double pY);
//desloca radio e retorna um ponteiro para o id
char* deslocaRadio(Radio radio, double dx, double dy);
#endif