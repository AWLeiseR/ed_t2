typedef struct{
    int id;
    double x,y;
}Radio;

void defineRadio(int i, double pX,double pY){
    Radio radio;
    radio.id=i;
    radio.x=pX;
    radio.y=pY;
}