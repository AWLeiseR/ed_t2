typedef struct{
    int id;
    double x,y;
}Semaforo;

void defineSemaforo(int i, double pX, double pY){
    Semaforo semaforo;
    semaforo.id=i;
    semaforo.x=pX;
    semaforo.y=pY;
}