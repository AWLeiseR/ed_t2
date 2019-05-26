typedef struct{
    char id[10];
    double x;
    double y;
    double sw;
    char cfill[20];
    char cstrk[20];
}Semaforo;

Semaforo* criaSemaforo(){
    Semaforo *semaforo=malloc(sizeof(Semaforo));
}

void defineSemaforo(Semaforo *semaforo, char i[], double pX, double pY){
    strcmp(semaforo->id,i);
    semaforo->x=pX;
    semaforo->y=pY;
}

void defineCorSemaforo(Semaforo *semaforo, char pCfill[], char pCstrk[],double pSw){
    strcpy(semaforo->cfill,pCfill);
    strcpy(semaforo->cstrk,pCstrk);
    semaforo->sw=pSw;

}

char* deslocaSemaforo(Semaforo *semaforo, double dx, double dy){
    semaforo->x=semaforo->x+dx;
    semaforo->y=semaforo->y+dy;

    return semaforo->id;
}