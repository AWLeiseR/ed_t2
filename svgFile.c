
//imprimir o cabecalho do svg
void cabecalho(FILE* arq){
    fprintf(arq,"<svg>");
}

//imprimir o rodape do svg
void rodape(FILE* arq){
    fprintf(arq,"<svg>");
}

//imprimi retangulo
void criaRetangulo(FILE* arq){
    fprintf(arq,"<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke=\"%s\" stroke-width=\"2\" />",x,y,w,h,stroke);
}

//imprimi Circulo
void criaCirculo(FILE* arq){

    fprintf(arq3,"<circle cx=\"%lf\" cy=\"%lf\" r=\"5\" stroke=\"%s\" stroke-width=\"1\" fill=\"%s\" />",x,y,cor,cor);
}

//imprimi ponto(circulo de raio 1 ou 0)
void criaPonto(FILE* arq){
    fprintf(arq3,"<circle cx=\"%lf\" cy=\"%lf\" r=\"1\" stroke=\"%s\" stroke-width=\"1\" fill=\"%s\" />",x,y,cor,cor);
}

void criaLinha(){
    
}