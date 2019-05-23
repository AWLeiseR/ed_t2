
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

    fprintf(arq,"<circle cx=\"%lf\" cy=\"%lf\" r=\"5\" stroke=\"%s\" stroke-width=\"1\" fill=\"%s\" />",x,y,cor,cor);
}

//imprimi ponto(circulo de raio 1 ou 0)
void criaPonto(FILE* arq){
    fprintf(arq,"<circle cx=\"%lf\" cy=\"%lf\" r=\"1\" stroke=\"%s\" stroke-width=\"1\" fill=\"%s\" />",x,y,cor,cor);
}

void criaLinha(double x1,double y1,double x2, double y2, FILE *arq){
   fprintf(arq," <line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"black\" stroke-width=\"2\" />",x1,y1,x2,y2);
}

void criaRetangulodash(double x, double y, double w, double h, char stroke[], FILE *arq, int res){
    if(res)
        fprintf(arq,"<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke=\"%s\" stroke-dasharray=\"5\" stroke-width:\"2\" />",x,y,w,h,stroke);
    else
     fprintf(arq,"<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke=\"%s\" stroke-width:\"2\" />",x,y,w,h,stroke);
}

void criaTexto(double x, double y, char texto[], FILE *arq){
    fprintf(arq,"<text x=\"%lf\" y=\"%lf\" fill=\"black\">%s</text>",x,y,texto);
}

void criaSvgbb(Formas forma[],char *dirsaida,char sufixo[],char cor[],int nx,char sufixogeo[]){
    FILE *svg;

    char *saida;

    int j;
    if(nx==0)
        nx=1000;
    saida=(char *) malloc((strlen(dirsaida)+strlen(sufixo)+strlen(sufixogeo)+7)*sizeof(char));

    sprintf(saida,"%s/%s-%s.svg",dirsaida,sufixogeo,sufixo);

    svg=fopen(saida,"w");
    if(svg==NULL){
        perror("");
        exit(1);
    }

    fprintf(svg,"<svg>");

    for(j=0;j<=nx;j++){
        switch (forma[j].tipo){

            case 'c':
                fprintf(svg,"<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" stroke-width=\"1\" fill=\"%s\" />",forma[j].cx,forma[j].cy,forma[j].r,forma[j].borda,forma[j].dentro);
                fprintf(svg,"<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\"  fill=\"none\" stroke=\"%s\" stroke-width:\"1\" />",forma[j].cx-forma[j].r,forma[j].cy-forma[j].r,forma[j].r*2,forma[j].r*2,cor);
                break;

            case 'r':
                fprintf(svg,"<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\"  stroke-width:\"2\" />",forma[j].cx,forma[j].cy,forma[j].w,forma[j].h,forma[j].borda,forma[j].dentro);
                fprintf(svg,"<ellipse cx=\"%lf\" cy=\"%lf\" rx=\"%lf\" ry=\"%lf\" fill=\"none\" stroke=\"%s\" stroke-width\"2\" />",forma[j].cx+(forma[j].w/2),forma[j].cy+(forma[j].h/2),forma[j].w/2,forma[j].h/2,cor);
                break;
                }
            }
    fprintf(svg,"</svg>");

    fclose(svg);
}