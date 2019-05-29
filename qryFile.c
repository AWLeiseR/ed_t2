#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lista.h"
#include"figuras.h"
#include"quadra.h"
#include"semaforo.h"
#include"hidrante.h"

void leituraQry(char pathqry[], char pathsaida[],char sufixogeo[],char sufixoqry[],ListaFiguras *listFig,ListaFiguras *listQua,ListaFiguras *listRad,ListaFiguras *listHid,ListaFiguras *listSem){
    Quadra *qua;
    Semaforo *se;
    Radio *ra;
    Hidrante *hid;
    //arquivo qry
    FILE *arq;
    //arquivo txt
    FILE *arq2;
    //arquivo svg
    //FILE *arq3;
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
    //double que recebe coordenadas dos comandos do qry
    double y;
    //double que recebe distancia entre dois pontos
    double dis;
    //double que recebe ponto medio entre dois pontos
    double mx;
    //double que recebe ponto medio entre dois pontos
    double my;
    double r;
    double dx;
    double dy;
    
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
    criaSvg(forma,arq3,nx);
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
            criaSvgbb(listFigs,pathsaida,sufixo,cor,sufixogeo);
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
            //testa se a forma na posição j é um retangulo
            if(forma[j].tipo == 'r'){
                //chama a função q retorna um inteiro para testar se o ponto esta dentro ou fora do retangulo
                res=pontoInteriorRetangulo(x,y,forma[j].cx,forma[j].cy,forma[j].w+forma[j].cx,forma[j].h+forma[j].cy);
                //chama a função que cria uma linha entre o ponto e o centro de massa do retangulo
                criaLinha(x,y,forma[j].w+forma[j].cx,forma[j].h+forma[j].cy,arq3);
            }
            //testa se a forma na posição j é um circulo
            else if(forma[j].tipo == 'c'){
                //chama a função q retorna um inteiro para testar se o ponto esta dentro ou fora do circulo
                res=pontoInternoCirculo(x,y,forma[j].cx,forma[j].cy,forma[j].r);
                //chama a função que cria uma linha entre o ponto e o centro de massa do circulo
                criaLinha(x,y,forma[j].cx,forma[j].cy,arq3);
            }
            //cria um circulo de raio pequeno se res for 1(dentro) manda como parameetro a cor green se nao 0 (fora) manda red
            criaCirculo(x,y,res?"green":"red",arq3);
            //escreve no arquivo o enunciado e na linha de baixo see esta dentro ou fora
            fprintf(arq2,"%s %d %lf %lf\n%s\n",letra,j,x,y,res? "interno" : "externo" );
        //d?:distancia entra o centro de massa das formas
        //confere se a string letra é igual a d?
        }else  if(strcmp("d?",letra)==0){
            //pega o identificador 'j' e o identificador 'k'
            fscanf(arq," %d %d",&j,&k);
            //printf(" %d %d",j,k);
            //testa se a forma j e a forma k sao circulos
           if(forma[j].tipo=='c' && forma[k].tipo=='c'){
                //chama a funçao distancia que calcula a distancia entre dois pontos e armazena o resultado em dis
                dis=distancia(forma[j].cx,forma[j].cy,forma[k].cx,forma[k].cy);
                //chama a função que cria uma linha entre o centro de massa dos dois circulos
                criaLinha(forma[j].cx,forma[j].cy,forma[k].cx,forma[k].cy,arq3);
                //escreve/transforma dis (double) em uma string
                sprintf(string,"%lf",dis);
                //calcula a coordenada x do ponto medio
                mx=(forma[j].cx+forma[k].cx)/2;
                //calcula a coordenada y do ponto medio
                my=(forma[j].cy+forma[k].cy)/2;

            //testa se a forma j e a forma k sao um retangulo e um circulo
            }else if(forma[j].tipo=='r'&&forma[k].tipo=='c'){
                //chama a funçao distancia que calcula a distancia entre dois pontos e armazena o resultado em dis
                dis=distancia(forma[j].cx+(forma[j].w/2),forma[j].cy+(forma[j].h/2),forma[k].cx,forma[k].cy);
                //chama a função que cria uma linha entre o centro de massa do retangulo e do circulo
                criaLinha(forma[j].cx+(forma[j].w/2),forma[j].cy+(forma[j].h/2),forma[k].cx,forma[k].cy,arq3);
                //escreve/transforma dis (double) em uma string
                sprintf(string,"%lf",dis);
                //calcula a coordenada x do ponto medio
                mx=(forma[j].cx+(forma[j].w/2)+forma[k].cx)/2;
                //calcula a coordenada y do ponto medio
                my=(forma[j].cy+(forma[j].h/2)+forma[k].cy)/2;
                
            //testa se a forma j e a forma k sao dois retangulos
            }else if(forma[j].tipo=='r' && forma[k].tipo=='r'){
                //chama a funçao distancia que calcula a distancia entre dois pontos e armazena o resultado em dis
                dis=distancia(forma[j].cx+(forma[j].w/2),forma[j].cy+(forma[j].h/2),forma[k].cx+(forma[k].w/2),forma[k].cy+(forma[k].h/2));
                //chama a função que cria uma linha entre o centro de massa dos dois retangulos
                criaLinha(forma[j].cx+(forma[j].w/2),forma[j].cy+(forma[j].h/2),forma[k].cx+(forma[k].w/2),forma[k].cy+(forma[k].h/2),arq3);
                //escreve/transforma dis (double) em uma string
                sprintf(string,"%lf",dis);
                //calcula a coordenada x do ponto medio
                mx=(forma[j].cx+(forma[j].w/2)+forma[k].cx+(forma[j].w/2))/2;
                //calcula a coordenada y do ponto medio
                my=(forma[j].cy+(forma[j].h/2)+forma[k].cy+(forma[j].h/2))/2;
                
            //testa se a forma j e a forma k sao um circulo e um retangulo
            }else if(forma[j].tipo=='c' && forma[k].tipo=='r'){
                //chama a funçao distancia que calcula a distancia entre dois pontos e armazena o resultado em dis
                dis=distancia(forma[j].cx,forma[j].cy,forma[k].cx+(forma[k].w/2),forma[k].cy+(forma[k].h/2));
                //chama a função que cria uma linha entre o centro de massa do circulo e do retangulo
                criaLinha(forma[j].cx,forma[j].cy,forma[k].cx+(forma[k].w/2),forma[k].cy+(forma[k].h/2),arq3);
                //escreve/transforma dis (double) em uma string
                sprintf(string,"%lf",dis);
                //calcula a coordenada x do ponto medio
                mx=(forma[j].cx+forma[k].cx+(forma[k].w/2))/2;
                //calcula a coordenada y do ponto medio
                my=(forma[j].cy+forma[k].cy+(forma[k].h/2))/2;
                
            }
            //escreve a distancia entre os dois pontos no arquivo svg no ponto meido
            criaTexto(mx,my,string,arq3);
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