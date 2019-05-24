#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lista.h"
#include"circulo.h"
#include"retangulo.h"
#include"quadra.h"
#include"semaforo.h"
#include"hidrante.h"
#include"radioBase.h"

void leituraGeo(char address[]){
    ListaFiguras *listRec;
    ListaFiguras *listCir;
    ListaFiguras *listQua;
    ListaFiguras *listSem;
    ListaFiguras *listHid;
    ListaFiguras *listRad;
    Circulo *cir;
    Retangulo *rec;
    Quadra *qua;
    Semaforo *se;
    Hidrante *hidrante;
    Radio *radio;
    Texto *texto;
    FILE* arq;
    //char que recebe o identificador de tipo
    char cfill[20], cstrk[20];
    char comando[4];
    //string
    char linha[50];
    char cep[11];
    char i[10];
    //inteiro que recebe o identificador das formas
    int id;
    int numQua,numHid,numSem,numRa;
    int i=1000;
    double x,y,w,h,r;
    double cw, rw, sw;    
    char *line_buf=NULL;
    size_t line_buf_size = 0;
    ssize_t line_size;
    listRec=createLista();
    listCir=createLista();
    listQua=createLista();
    listSem=createLista();
    listHid=createLista();
    listRad=createLista();
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
        //pega o comando do arquivo geo
        fscanf(arq,"%s",comando);
        // 'c', circulo
        if(strcmp("c",comando)==0){
            //lea tres doubles responsaveis pelo centro(x,y) e raio depois duas strings responsaveis pelas cores de dentro e da borda
            fscanf(arq,"%d %lf %lf %lf %s %s",&id,&r,&x,&y,cstrk,cfill);
            cir=criaCirculo();
            defineCirculo(cir,id,x,y,r,cstrk,cfill,2);
            insert(listCir,cir);                    
                //printf("%c %d %lf %lf %lf %s %s\n",forma[id].tipo,forma[id].i,forma[id].r,forma[id].cx,forma[id].cy,forma[id].borda,forma[id].dentro);
        }else if(strcmp("r",comando)==0){//'r',  retangulo               
                //le tquatro doubles responsaveis pel ancora(canto superio esquerdo) e comprimento e altura depois duas strings responsaveis pelas cores de dentro e da borda
                fscanf(arq,"%d %lf %lf %lf %lf %s %s",&id,&w,&h,&x,&y,cstrk,cfill);
                rec=criaRetangulo();
                defineRetangulo(rec,id,x,y,h,w,cstrk,cfill);
                inser(listRec,cir);
                //printf("%c %d %lf %lf %lf %lf %s %s\n",forma[id].tipo,forma[id].i,forma[id].w,forma[id].h,forma[id].cx,forma[id].cy,forma[id].borda,forma[id].dentro);
        }else if(strcmp("nx",comando)){// 'nx'
                //pega o numero do nx  
                fscanf(arq,"%d %d %d %d %d",i,numQua,numHid,numSem,numRa);
              
                
        }else if(strcmp("t",comando)){//caso for 't',  texto
            
                /*//pega as coordenadas do texto
                fscanf(arq,"%lf %lf",&x,&y);
                //pega a linha toda de testo
                line_size = getline(&line_buf, &line_buf_size, arq);
                //imprime no arquivo
                criaTexto(x,y,line_buf,arq3);
                criaTexto(x,y,line_buf,svgsemconsulta);*/
        }else if(strcmp("q",comando)==0){
            fscanf(arq,"%s %lf %lf %lf %lf",cep,&x,&y,&w,&h);
            qua=criaQuadra();
            defineQuadra(qua,cep,x,y,w,h);
            insert(listQua,qua);

            printf("\nquadra\n");

        }else if(strcmp("h",comando)==0){
            fscanf(arq,"%s %lf %lf",i,&x,&y);
            hidrante=criahidrante();
            defineHidrante(hidrante,i,x,y);
            insert(listHid,hidrante);
            printf("\nHidrante\n");
                
        }else if(strcmp("s",comando)==0){
            fscanf(arq,"%s %lf %lf",i,&x,&y);
            se=criaSemaforo();
            defineSemaforo(se,i,x,y);
            insert(listSem,se);
            printf("\nSemafaro\n");

        }else if(strcmp("rb",comando)==0){
            fscanf(arq,"%d %lf %lf",&id,&x,&y);
            printf("\nRadio-Base\n");

        }else if(strcmp("cq",comando)==0){
            fscanf(arq,"%s %s %lf", cfill, cstrk, &sw);
            printf("\ncores 1\n");

        }else if(strcmp("ch",comando)==0){
            fscanf(arq,"%s %s %lf", cfill, cstrk, &sw);
            printf("\ncores 2\n");

        }else if(strcmp("cr",comando)==0){
            fscanf(arq,"%s %s %lf", cfill, cstrk, &sw);
            printf("\ncores 3\n");
                
        }else if(strcmp("cs",comando)==0){
            fscanf(arq,"%s %s %lf", cfill, cstrk, &sw);
            printf("\ncores 4\n");

        }else if(strcmp("sw",comando)==0){
            fscanf(arq,"%lf %lf",&cw, &rw);
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