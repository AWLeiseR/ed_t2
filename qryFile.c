#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lista.h"
#include"figuras.h"
#include"quadra.h"
#include"semaforo.h"
#include"hidrante.h"
#include"svgFile.h"

void leituraQry(char pathqry[], char pathsaida[],char sufixogeo[],char sufixoqry[],ListaFiguras *listFig,ListaFiguras *listQua,ListaFiguras *listRad,ListaFiguras *listHid,ListaFiguras *listSem){
    Quadra *qua;
    Semaforo *se;
    Radio *ra;
    Hidrante *hid;
    Retangulo *re1;
    Retangulo *re2;
    Circulo *cir1;
    Circulo *cir2;
    //arquivo qry
    FILE *arq;
    //arquivo txt
    FILE *arq2;
    //arquivo svg
    FILE *arq3;
    //pega os comandos do qry
    char letra[3];
    //argumentos de bb
    char palavra[50];
    //numero para printar no meio da linha i?
    char string[20];
    //string com o caminho para arq2
    char *saida;
    //string para cep, metricas
    char comando[3];
    char tipo1,tipo2;
    char id[10];
    char cstrk[20];
    //ponteiro para pegar o sufixo de bb
    char *sufixo;
    //ponteiro para pegar cor usada em bb
    char *cor;
    //nome de saida do txt
    char nometxt[]=".txt";   
    //recebe inteiro que indentifia uma forma
    int k;
    //recebe inteiro que indentifia uma forma
    int j;
    //recebe os valores 1 ou 0, 1 para dentro da forma e 0 para fora
    int res;
    //recebe os valores 1 ou 0, 1 para dsobreposiçao da forma e 0 para nao sobreposição
    int sobre;
    //double que recebe coordenadas dos comandos do qry
    double x;
    double y;
    double w;
    double h;
    double r;
    //double que recebe distancia entre dois pontos
    double dis;
    //double que recebe ponto medio entre dois pontos
    double mx;
    //double que recebe ponto medio entre dois pontos
    double my;
    double dx;
    double dy;
    double cx1,cy1,h1,w1,r1,cx2,cy2,h2,w2,r2;
    //abre o arq qry só pra leitura
    arq=fopen(pathqry,"r");
    //testa se esta null
    if(arq==NULL){
        printf("\nNAO ENCONTRADO ARQUIVO %s\n",pathqry);
        perror("");
        exit(1);
    }

    //cria um vetor de char do tamannho de pathsaida e de nometxt +2 por causa do / e do /0 
    saida=(char *) malloc(strlen(pathsaida)+strlen(nometxt)+strlen(sufixogeo)+strlen(sufixoqry)*sizeof(char)+2);
    //escreve dentro do vetor de char adcionando o /
    sprintf(saida,"%s/%s%s%s",pathsaida,sufixogeo,sufixoqry,nometxt);

    //abre o e cria o arquivo txt de saida
    arq2=fopen(saida,"w");
    //testa se o ponteiro é null
     if(arq2==NULL){
        printf("\nNAO ENCONTRADO ARQUIVO %s\n",saida);
        perror("");
        exit(1);
    }
    
    //escreve no arq3 as formas do struct
    //criaSvg(forma,arq3,nx);
    //pega os dois caracteres responsaveis pelos comandos
    fscanf(arq,"%s",letra);
    
    //loop para varer o arquivo qry
    while(1){
        //testa se ja chegou ao fim do arquivo
        if(feof(arq))
            break;
        
       //comando bb: faz um retangulo em volta dos circulos e faz um circulo dentro dos retangulos PRODUZ UM ARQUIVO SEPARADO
       //verifica se letra é = a bb
        if(strcmp("bb",letra)==0){
            //le o string seguinte e armazena em palavra
            fscanf(arq,"%s",palavra);
            //cria uma string com o tamanho de palavra +1(por causa do /0)
            sufixo=(char *)malloc(strlen(palavra)*sizeof(char)+1);
            //copia o q esta dentro de palavra para sufixo
            strcpy(sufixo,palavra);
            //le a proxima string e armazena em palavra
            fscanf(arq,"%s",palavra);
            //cria uma string do tamanho da string escrita em palavra
            cor=(char *)malloc(strlen(palavra)*sizeof(char)+1);
            //copia o que esta em palavra para cor
            strcpy(cor,palavra);
            //chama função que cria um svg separado, enviando a struct forma, pathsaida, sufixo para o nome do arquivo e cor que sera usada nas boradas das formas
            imprimiSvgbb(listFig,pathsaida,sufixo,cor,sufixogeo);
            free(cor);
            free(sufixo);
        //o?:Sobreposição de formas FAZER!!
        //confere se a string letra é igual a o?
        }else  if(strcmp("o?",letra)==0){
            //pega os dois inteiros (identificadores) seguintes e armazena em 'j' e 'k' respectivamente
            fscanf(arq," %d %d",&j,&k);
            sobre=sobreposicao(listFig,j,k,arq3);
            //escreve no arquivo txt o enuciado
            fprintf(arq2,"%s %d %d\n%s\n",letra,j,k, sobre? "SIM":"NAO");
        //i?:Ponto dentro ou fora formas
        //confere se a string letra é igual a i?
        }else  if(strcmp("i?",letra)==0){
            //pega o identificador 'j' e as duas coordenadas 'x' e 'y' seguintes
            fscanf(arq," %d %lf %lf",&j,&x,&y);
            //printf(" %d %lf %lf",j,x,y);
            tipo1=getTipo(listFig,j);
            //testa se a forma na posição j é um retangulo
            if(tipo1 == 'r'){
                re1=getRetangulo(listFig,j);
                cx1=getRetanguloX(re1);
                cy1=getRetanguloY(re1);
                w1=getRetanguloW(re1);
                h1=getRetanguloH(re1);
                //chama a função q retorna um inteiro para testar se o ponto esta dentro ou fora do retangulo
                res=pontoInteriorRetangulo(x,y,cx1,cy1,w1+cx1,h1+cy1);
                //chama a função que cria uma linha entre o ponto e o centro de massa do retangulo
                imprimiLinha(x,y,w1+cx1,h1+cy1,arq3);
            }
            //testa se a forma na posição j é um circulo
            else if(forma[j].tipo == 'c'){
                cir1=getCirculo(listFig,j);
                 cx1=getCirculoX(cir1);
                cy1=getCirculoY(cir1);
                r1=getCirculoR(cir1);
                //chama a função q retorna um inteiro para testar se o ponto esta dentro ou fora do circulo
                res=pontoInternoCirculo(x,y,cx1,cy1,r1);
                //chama a função que cria uma linha entre o ponto e o centro de massa do circulo
                imprimiLinha(x,y,cx1,cy1,arq3);
            }
            //cria um circulo de raio pequeno se res for 1(dentro) manda como parameetro a cor green se nao 0 (fora) manda red
            imprimiCirculo(arq3,x,y,r,cstrk,res?"green":"red");
            //escreve no arquivo o enunciado e na linha de baixo see esta dentro ou fora
            fprintf(arq2,"%s %d %lf %lf\n%s\n",letra,j,x,y,res? "interno" : "externo" );
        //d?:distancia entra o centro de massa das formas
        //confere se a string letra é igual a d?
        }else  if(strcmp("d?",letra)==0){
            //pega o identificador 'j' e o identificador 'k'
            fscanf(arq," %d %d",&j,&k);
            //printf(" %d %d",j,k);
            tipo1=getTipo(listFig,j);
            tipo2=getRipo(listFig,k);
            //testa se a forma j e a forma k sao circulos
           if(tipo1=='c' && tipo2=='c'){
                cir1=getCirculo(listFig,j);
                cx1=getCirculoX(cir1);
                cy1=getCirculoY(cir1);
                r1=getCirculoR(cir1);
                cir2=getCirculo(listFig,k);
                cx2=getCirculoX(cir2);
                cy2=getCirculoY(cir2);
                r2=getCirculoR(cir2);
                //chama a funçao distancia que calcula a distancia entre dois pontos e armazena o resultado em dis
                dis=distancia(cx1,cy1,cx2,cy2);
                //chama a função que cria uma linha entre o centro de massa dos dois circulos
                imprimiLinha(cx1,cy1,cx2,cy2,arq3);
                //escreve/transforma dis (double) em uma string
                sprintf(string,"%lf",dis);
                //calcula a coordenada x do ponto medio
                mx=(cx1+cx2)/2;
                //calcula a coordenada y do ponto medio
                my=(cy1+cy2)/2;

            //testa se a forma j e a forma k sao um retangulo e um circulo
            }else if(tipo1=='r'&&tipo2=='c'){
                 re1=getRetangulo(listFig,j);
                cx1=getretanguloX(re1);
                cy1=getRetanguloY(re1);
                w1=getRetanguloW(re1);
                h1=getRetanguloH(re1);

                cir1=getCirculo(listFig,k);
                cx2=getCirculoX(cir1);
                cy2=getCirculoY(cir1);
                r2=getCirculoR(cir1);
                //chama a funçao distancia que calcula a distancia entre dois pontos e armazena o resultado em dis
                dis=distancia(cx1+(w1/2),cy1+(h1/2),cx2,cy2);
                //chama a função que cria uma linha entre o centro de massa do retangulo e do circulo
                criaLinha(cx1+(w1/2),cy1+(h1/2),cx2,cy2,arq3);
                //escreve/transforma dis (double) em uma string
                sprintf(string,"%lf",dis);
                //calcula a coordenada x do ponto medio
                mx=(cx1+(w1/2)+cx2)/2;
                //calcula a coordenada y do ponto medio
                my=(cy1+(h1/2)+cy2)/2;
                
            //testa se a forma j e a forma k sao dois retangulos
            }else if(tipo1=='r' && tipo2=='r'){
                 re1=getRetangulo(listFig,j);
                cx1=getretanguloX(re1);
                cy1=getRetanguloY(re1);
                w1=getRetanguloW(re1);
                h1=getRetanguloH(re1);

                re2=getRetangulo(listFig,k);
                cx2=getretanguloX(re2);
                cy2=getRetanguloY(re2);
                w2=getRetanguloW(re2);
                h2=getRetanguloH(re2);
                //chama a funçao distancia que calcula a distancia entre dois pontos e armazena o resultado em dis
                dis=distancia(cx1+(w1/2),cy1+(h1/2),cx2+(w2/2),cy2+(h2/2));
                //chama a função que cria uma linha entre o centro de massa dos dois retangulos
                imprimiLinha(cx1+(w1/2),cy1+(h1/2),cx2+(w2/2),cy2+(h2/2),arq3);
                //escreve/transforma dis (double) em uma string
                sprintf(string,"%lf",dis);
                //calcula a coordenada x do ponto medio
                mx=(cx1+(w1/2)+cx2+(w1/2))/2;
                //calcula a coordenada y do ponto medio
                my=(cy1+(h1/2)+cy2+(h1/2))/2;
                
            //testa se a forma j e a forma k sao um circulo e um retangulo
            }else if(tipo1=='c' && tipo2=='r'){
                cir1=getCirculo(listFig,j);
                cx1=getCirculoX(cir1);
                cy1=getCirculoY(cir1);
                r1=getCirculoR(cir1);

                re2=getRetangulo(listFig,k);
                cx2=getretanguloX(re2);
                cy2=getRetanguloY(re2);
                w2=getRetanguloW(re2);
                h2=getRetanguloH(re2);
                //chama a funçao distancia que calcula a distancia entre dois pontos e armazena o resultado em dis
                dis=distancia(cx1,cy1,cx2+(w2/2),cy2+(h2/2));
                //chama a função que cria uma linha entre o centro de massa do circulo e do retangulo
                imprimiLinha(cx1,cy1,cx2+(w2/2),cy2+(h2/2),arq3);
                //escreve/transforma dis (double) em uma string
                sprintf(string,"%lf",dis);
                //calcula a coordenada x do ponto medio
                mx=(cx1+cx2+(w2/2))/2;
                //calcula a coordenada y do ponto medio
                my=(cy1+cy2+(h2/2))/2;
                
            }
            //escreve a distancia entre os dois pontos no arquivo svg no ponto meido
            imprimiTexto(mx,my,string,arq3);
            //escreve no arquivo txt o enunciado e a resposta na linha seguinte
            fprintf(arq2,"%s %d %d \n%lf\n",letra,j,k,dis);
        }else if(strcmp("dq",letra)==0){
            fscanf(arq,"%s %s %lf",comando, id,dis);
            fprintf(arq2,"%s%s %s %lf",comando, id,dis,letra);

        }else if(strcmp("del",letra)==0){
            scanf(arq,"%s",comando);
            fprintf(arq2,"%s",letra);
            
        }else if(strcmp("cdq",letra)==0){
            scanf(arq,"%lf %lf %lf %s",x,y,r,cstrk);
            fprintf(arq2,"%s%lf %lf %lf %s",x,y,r,cstrk,letra);
        }else if(strcmp("crd?",letra)==0){
            scanf(arq,"%s",comando);
            res=buscaChar(listQua,comando);
            if(res!=-1){
                qua=getQuadra(listQua,res);
                x=getQuadraX(qua);
                y=getQuadraY(qua);  
            }else{
                res=buscaChar(listHid,comando);
                if(res!=-1){
                    hid=getHidrante(listHid,res);
                    x=getHidX(qua);
                    y=getHidY(qua);
                }else{
                    res=buscaChar(listRad,comando);
                    if(res!=-1){
                        ra=getRadio(listRad,res);
                        x=getRadioX(ra);
                        y=getRadioY(ra);
                    }else{
                        res=buscaChar(listSem,comando);
                        if(res!=-1){
                            se=getSemaforo(listSem,res);
                            x=getSemaforoX(se);
                            y=getSemaforoY(se);
                        }

                    }
                    

                }
                
            }
            
            fprintf(arq2,"%s %s\n %lf %lf\n",letra,comando,x,y);
        }else if(strcmp("trns",letra)==0){
            scanf(arq,"%lf %lf %lf %lf %lf %lf",x,y,w,h,dx,dy);
            fprintf(arq2,"%s",letra);
        }
        //pega a proxima letra (requisição)                
       fscanf(arq,"%s",letra);
    }
    
    //escreve no arquivo svg o roda pé
    fprintf(arq3,"<svg>");
    
    //fecha os arquivos
    fclose(arq);
    fclose(arq2);
    fclose(arq3);
    
    //desaloca as memorias
    free(saida);
}