typedef struct{
    char id[10];
    double x,y;
}Radio;

void defineRadio(int i, double pX,double pY){
    Radio radio;
    radio.id=i;
    radio.x=pX;
    radio.y=pY;
}

char* deslocaRadio(Radio *radio, double dx, double dy){
    radio->x=radio->x+dx;
    radio->y=radio->y+dy;

    return radio->id;
}