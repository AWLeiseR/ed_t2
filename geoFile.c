void leituraGeo(char address[]){

    //char que recebe o identificador de tipo
    char letra;
    char comando[4];
    //string
    char linha[50];
    //inteiro que recebe o identificador das formas
    int id;
    int i=1000;
    double x,y;
    char *line_buf=NULL;
    size_t line_buf_size = 0;
    ssize_t line_size;

    //abre o arquivo svg
    arq=fopen(address,"r");
    //testa se o ponteiro é null
     if(arq==NULL){
        printf("\nNAO ENCONTRADO ARQUIVO %s\n",address);
        perror("");
        exit(1);
    }
   
    //printf("\t%s\n",address);
    //loop que varre o arquivo .geo
    while(1){
        fscanf(arq,"%s",comando)
        //pega a primeira letra do arq .geo de armazena em letra
        letra=comando[0];
//printf("%c",letra);
        
        //testa se a letra é 'c' 'r' 't' ou 'nx'
        switch (letra){

            //caso for 'c', circulo
            case 'c' :
                //pega um inteiro (identificador) e armazena em id
                fscanf(arq,"%d",&id);
                
                    //armazena id em forma[id].i
                    forma[id].i=id;
                    //le tres doubles responsaveis pelo centro(x,y) e raio depois duas strings responsaveis pelas cores de dentro e da borda
                    fscanf(arq,"%lf %lf %lf %s %s",&forma[id].r,&forma[id].cx,&forma[id].cy,forma[id].borda,forma[id].dentro);
                    
                    forma[id].tipo=letra;
                    //printf("%c %d %lf %lf %lf %s %s\n",forma[id].tipo,forma[id].i,forma[id].r,forma[id].cx,forma[id].cy,forma[id].borda,forma[id].dentro);
                
                break;

            //caso for 'r',  retangulo
            case 'r':
                //pega um inteiro (identificador) e armazena em id
                fscanf(arq,"%d",&id);
                
                //armazena id em forma[id].i
                forma[id].i=id;
                //le tquatro doubles responsaveis pel ancora(canto superio esquerdo) e comprimento e altura depois duas strings responsaveis pelas cores de dentro e da borda
                fscanf(arq,"%lf %lf %lf %lf %s %s",&forma[id].w,&forma[id].h,&forma[id].cx,&forma[id].cy,forma[id].borda,forma[id].dentro);
                forma[id].tipo=letra;
                //printf("%c %d %lf %lf %lf %lf %s %s\n",forma[id].tipo,forma[id].i,forma[id].w,forma[id].h,forma[id].cx,forma[id].cy,forma[id].borda,forma[id].dentro);
                
                 
               break;

            //caso for 'n',  nx
            case 'n':
                //pega o x
                letra=fgetc(arq);
                //pega o numero do nx  
                fscanf(arq,"%d",nx);
                //i recebe o conteudo de nx
                i=*nx;
                //printf("\t%d\n",i);
                //realoca o vetor de forma
                forma=(Formas *)realloc(forma,sizeof(Formas)*i);
                break;

            //caso for 't',  texto
            case 't':
                //pega as coordenadas do texto
                fscanf(arq,"%lf %lf",&x,&y);
                //pega a linha toda de testo
                line_size = getline(&line_buf, &line_buf_size, arq);
                //imprime no arquivo
                criaTexto(x,y,line_buf,arq3);
                criaTexto(x,y,line_buf,svgsemconsulta);
                break;

            case 'q':
                break;
            case 's':
                break;
            //default:
                //break;     
        }

        //testa se esta no final do arquivo
        if (feof(arq)){
            //printf("\nFIM\n");
            break; 
        }
    }
    //fecha o arquivo
    fclose(arq);
    //printf("FIM LEITURA GEO\n");
    //reetorna o ponteiro para formas
    return forma;
//printf("FIM LEITURA GEO\n");
}