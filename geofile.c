#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void leituraGeo(char address[]){
    FILE* arq;
    //char que recebe o identificador de tipo
    char letra;
    char comando[4];
    //string
    char linha[50];
    char cep[11];
    //inteiro que recebe o identificador das formas
    int id;
    int numQua,numHid,numSem,numRa;
    int i=1000;
    double x,y,w,h;    
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
        fscanf(arq,"%s",comando);
        //pega a primeira letra do arq .geo de armazena em letra
        // 'c', circulo
            if(strcmp("c",comando)==0){

                //pega um inteiro (identificador) e armazena em id
                //fscanf(arq,"%d",&id);
                
                    //armazena id em forma[id].i
                    
                    //le tres doubles responsaveis pelo centro(x,y) e raio depois duas strings responsaveis pelas cores de dentro e da borda
                    //fscanf(arq,"%lf %lf %lf %s %s",&forma[id].r,&forma[id].cx,&forma[id].cy,forma[id].borda,forma[id].dentro);
                    
                    
                    //printf("%c %d %lf %lf %lf %s %s\n",forma[id].tipo,forma[id].i,forma[id].r,forma[id].cx,forma[id].cy,forma[id].borda,forma[id].dentro);
                

            }else if(strcmp("r",comando)==0){//'r',  retangulo
                //pega um inteiro (identificador) e armazena em id
                //fscanf(arq,"%d",&id);
                
                //armazena id em forma[id].i
               
                //le tquatro doubles responsaveis pel ancora(canto superio esquerdo) e comprimento e altura depois duas strings responsaveis pelas cores de dentro e da borda
                //fscanf(arq,"%lf %lf %lf %lf %s %s",&forma[id].w,&forma[id].h,&forma[id].cx,&forma[id].cy,forma[id].borda,forma[id].dentro);
                
                //printf("%c %d %lf %lf %lf %lf %s %s\n",forma[id].tipo,forma[id].i,forma[id].w,forma[id].h,forma[id].cx,forma[id].cy,forma[id].borda,forma[id].dentro);
                

            }else if(strcmp("nx",comando)){// 'nx'
                
                //pega o numero do nx  
                fscanf(arq,"%d %d %d %d %d",i,numQua,numHid,numSem,numRa);
                //i recebe o conteudo de nx
                //i=*nx;
                //printf("\t%d\n",i);
                //realoca o vetor de forma
                
            }else if(strcmp("t",comando)){//caso for 't',  texto
            
                /*//pega as coordenadas do texto
                fscanf(arq,"%lf %lf",&x,&y);
                //pega a linha toda de testo
                line_size = getline(&line_buf, &line_buf_size, arq);
                //imprime no arquivo
                criaTexto(x,y,line_buf,arq3);
                criaTexto(x,y,line_buf,svgsemconsulta);*/
            }else if(strcmp("q",comando)==0){
                fscanf(arq,"%s %lf %lf %lf %lf",cep,x,y,w,h);
                printf("\nquadra\n");

            }else if(strcmp("h",comando)==0){
                fscanf(arq,"%d %lf %lf",id,x,y);
                printf("\nHidrante\n");
                
            }else if(strcmp("s",comando)==0){
                fscanf(arq,"%d %lf %lf",id,x,y);
                printf("\nSemafaro\n");

            }else if(strcmp("rb",comando)==0){
                fscanf(arq,"%d %lf %lf",id,x,y);
                printf("\nRadio-Base\n");

            }else if(strcmp("cq",comando)==0){
                printf("\ncores 1\n");

            }else if(strcmp("ch",comando)==0){
                printf("\ncores 2\n");

            }else if(strcmp("cr",comando)==0){
                printf("\ncores 3\n");
                
            }else if(strcmp("cs",comando)==0){
                printf("\ncores 4\n");

            }else if(strcmp("sw",comando)==0){
                printf("\nEspessura\n");

            }
            //testa se esta no final do arquivo
            if (feof(arq)){
                //printf("\nFIM\n");
                break; 
            }                    
        }

        
       
    
    //fecha o arquivo
    fclose(arq);
    printf("FIM LEITURA GEO\n");
    //reetorna o ponteiro para formas
    //return void;
//printf("FIM LEITURA GEO\n");
}