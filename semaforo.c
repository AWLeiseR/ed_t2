typedef struct{
    char id[10];
    double x;
    double y;
}Semaforo;

void defineSemaforo(int i, double pX, double pY){
    Semaforo semaforo;
    semaforo.id=i;
    semaforo.x=pX;
    semaforo.y=pY;
}

char* deslocaSemaforo(Semaforo semaforo, double dx, double dy){
    semaforo.x=x+dx;
    semaforo.y=y+dy;

    return semaforo.id;
}