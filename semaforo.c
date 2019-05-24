typedef struct{
    char id[10];
    double x;
    double y;
}Semaforo;

Semaforo* criaSemaforo(){
    Semaforo *semaforo=malloc(sizeof(Semaforo));
}

void defineSemaforo(Semaforo *semaforo, char i[], double pX, double pY){
    strcmp(semaforo->id,i);
    semaforo->x=pX;
    semaforo->y=pY;
}

char* deslocaSemaforo(Semaforo *semaforo, double dx, double dy){
    semaforo->x=semaforo->x+dx;
    semaforo->y=semaforo->y+dy;

    return semaforo->id;
}