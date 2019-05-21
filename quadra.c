typedef struct{
    char cep[20];
    double x;
    double y;
    double w;
    double h;
}Quadra;

void setQuadra(char pCep[],double pX, double pY, double pW, double pH){
    Quadra quadra;
    strcpy(quadra.cep,pCep);
    quadra.x=pX;
    quadra.y=pY;
    quadra.w=pW;
    quadra.h=pH;
}