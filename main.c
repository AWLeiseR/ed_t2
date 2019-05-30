#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "geofile.h"
#include "qryFile.h"
#include "figuras.h"
#include "quadra.h"
#include "semaforo.h"
#include "hidrante.h"
#include "radioBase.h"
#include "svgFile.h"



char* trataBarra(char path[]){
    int i,j,x,y,barra;
    char letra;
    char *sufixo;
    //armazena o tamanho de path
    i=strlen(path);
    //armazena o tamanho de path em uma segunda variavel 
    j=i;
    //pega a ultima letra de path
    letra=path[i];
    //while que ira percorrer toda a string path
    while(i>=0){
        //analiza se o caractere pego é igual a '/'
        if(letra=='/'){
        //caso for acrescenta um a i pois o path[i] sera a posição de / e quermos pegar o proximo
            i++;
            //variavel de controle indica que foi achado um /
            barra=1;
            break;        
        }else{
            //indica que nao foi achado um /
            barra=0;
        }
        //decrementa i para pegar o caractere anterior
        i--;
        //pega o caractere anterior
        letra=path[i];
        
    }
    //se foi encontrado barra
    if(barra){
        //ve a diferença entre o valor total e o numero de iterações feitas, e é adicionado 1 por causa do /0
        y=j-i+1;
        //alocação 
        sufixo=(char*) malloc(y*sizeof(char));
        //passagem do path para o sufixo, com a parte determinada
        for(x=0;x<=y;x++){
            sufixo[x]=path[i];
            i++; 
        }       
    }else{
     //caso nao foi encontrado uma barra simplemente aloca e copiaa o conteudo de path
           sufixo=(char*) malloc(j*sizeof(char));
           strcpy(sufixo,path); 
    }
    //tira o .extensão da string  
    sufixo=strtok(sufixo,".");
    //restorna sufixo;
    return sufixo;  
}

 

int main(int argc, char *argv[]){
    //comeca com um pq o argc[0] e o nome do arquivo chamado
    ListaFiguras *listFig;
    ListaFiguras *listQua;
    ListaFiguras *listSem;
    ListaFiguras *listHid;
    ListaFiguras *listRad;
    listFig=createLista(1000);
    listQua=createLista(1000);
    listSem=createLista(1000);
    listHid=createLista(1000);
    listRad=createLista(1000);
    Quadra *qua;
    int i=1;
    //nome do arquivo .geo
    char *nomegeo=NULL;
    //diretorio de base
    char *dirbase=NULL;
    //nome do arquivo query
    char *nomeqry=NULL;
    //diretorio principal
    char *dirsaida=NULL;
    //caminho p/ o arq geo
    char *pathgeo=NULL;
    //caminho p/ o arq qry
    char *pathqry=NULL;
    //sufixo do arquivo geo
    char *sufixogeo=NULL;
    //sufixo do arquivo qry
    char *sufixoqry=NULL;
    char *saidasvg;
   
    char *semcunsulta;

    char nomesvg[]=".svg";

    double cx1,cy1,h1,w1;


    //varre os parametros digitados no terminal
   while(i<argc){
        //-e:dir base(opcional)
        //verifica se argv é igual a -e
        if (strcmp("-e",argv[i])==0){
            //acrescenta 1 na variavel i para pegar o proximo parametro
            i++;
            //aloca memoria do tamanho de argv + mais 1 para o /0
            dirbase= (char *)malloc((strlen(argv[i])+1)*sizeof(char));
            //copia argv para dirbase
            strcpy(dirbase,argv[i]);

        //-f:nome do arq.geo
        //verifica se argv é igual a -f
        }else if (strcmp("-f",argv[i])==0){
            //acrescenta 1 na variavel i para pegar o proximo parametro
            i++;
            //aloca memoria do tamanho de argv + mais 1 para o /0
            nomegeo = (char *)malloc((strlen(argv[i])+1)*sizeof(char));
            sufixogeo = (char *)malloc((strlen(argv[i])+1)*sizeof(char));
            //copia argv para nomegeo
            strcpy(nomegeo,argv[i]);
            sufixogeo=trataBarra(nomegeo);

        //-q:nome do arquivo qry
        //verifica se argv é igual a -q
        }else if (strcmp("-q",argv[i])==0){
            //acrescenta 1 na variavel i para pegar o proximo parametro
            i++;
            //aloca memoria do tamanho de argv + mais 1 para o /0
            nomeqry = (char *)malloc((strlen(argv[i])+1)*sizeof(char));
            sufixoqry = (char *)malloc((strlen(argv[i])+1)*sizeof(char));
            //copia argv para nomeqry
            strcpy(nomeqry,argv[i]);            
            sufixoqry=trataBarra(nomeqry);

        //-o:diretorio de saida
        //verifica se argv é igual a -o
        }else if (strcmp("-o",argv[i])==0){
            //acrescenta 1 na variavel i para pegar o proximo parametro
            i++;
            //aloca memoria do tamanho de argv + mais 1 para o /0
            dirsaida = (char *)malloc((strlen(argv[i])+1)*sizeof(char));
            //copia argv para dirsaida
            strcpy(dirsaida,argv[i]);
        }
        //acrescenta mais 1 para pegar o proximo parametro
        i++;
    }


    //verifica se o ponteiro dirbase foi preenchido ou nao
    if(dirbase == NULL && nomeqry == NULL){
        //aloca memoria do tamanho de nomegeo +1
         pathgeo = (char *)malloc((strlen(nomegeo)+1)*sizeof(char));
         saidasvg=(char*)malloc((strlen(nomegeo)+(strlen(nomesvg)+1)*sizeof(char)));
        //pathqry = (char *)malloc((strlen(nomeqry)+1)*sizeof(char));
        //sprintf escreve dentro de pathgeo
        sprintf(pathgeo,"%s",nomegeo);
        //sprintf(pathqry,"%s",nomeqry);
    }else if(nomeqry == NULL){
        pathgeo = (char *)malloc((strlen(nomegeo)+strlen(dirbase)+2)*sizeof(char));
        saidasvg=(char*)malloc((strlen(nomegeo)+(strlen(nomesvg)+strlen(dirbase)+1)*sizeof(char)));
        sprintf(pathgeo,"%s/%s",dirbase,nomegeo);
    }else if(dirbase == NULL){
        
        pathgeo = (char *)malloc((strlen(nomegeo)+1)*sizeof(char));
        pathqry = (char *)malloc((strlen(nomeqry)+1)*sizeof(char));
        saidasvg=(char*)malloc((strlen(nomegeo)+strlen(nomesvg)+1)*sizeof(char));
        sprintf(pathgeo,"%s",nomegeo);
        sprintf(pathqry,"%s",nomeqry);
    }else{
        //aloca memoria do tamanho de nomegeo+dirbase
        pathgeo = (char *)malloc((strlen(nomegeo)+strlen(dirbase)+2)*sizeof(char));
        pathqry = (char *)malloc((strlen(nomeqry)+strlen(dirbase)+2)*sizeof(char));
        saidasvg=(char*)malloc((strlen(nomegeo)+strlen(nomesvg)+1)*sizeof(char));
        //sprintf escreve dentro de pathgeo
        sprintf(pathgeo,"%s/%s",dirbase,nomegeo);
        sprintf(pathqry,"%s/%s",dirbase,nomeqry);
    }
    sprintf(saidasvg,"%s%s",nomegeo,nomesvg);
    printf("\ngeo=%s  %s",nomegeo,sufixogeo);
    printf("\nqry=%s  %s",nomeqry,sufixoqry);

    printf("\npaths=%s  %s",pathqry,pathgeo);
    printf("\nsaida=%s",saidasvg);
    
    leituraGeo(saidasvg,pathgeo,listFig,listQua,listSem,listHid,listRad);
    //imprimir(listFig);
    Quadra quadra=(Quadra)qua;
    //qua=criaQuadra();
    qua=getQuadra(listQua,0);
    printf("\n%lf %lf\n",getQuadraX(qua),getQuadraX(qua));
    printf("\ns*");
                cx1=getQuadraX(qua);
                cy1=getQuadraY(qua);
                w1=getQuadraW(qua);
                h1=getQuadraH(qua);
                 //printf("%lf %lf %lf %lf\n", cx1,cy1,w1,h1);
    if(nomeqry!=NULL){
        leituraQry(pathqry,dirsaida,sufixogeo,sufixoqry,listFig,listQua,listRad,listHid,listSem);
    }
    
   // criaSvg(listFig,listQua,listRad,listHid,listSem,saidasvg);
    
    
    
    //freeList(listFig);
    //freeList(listHid);
    //freeList(listQua);
    //freeList(listRad);
    //freeList(listSem);
    free(nomegeo);
    free(nomeqry);
    free(dirbase);
    free(dirsaida);
    free(pathgeo);
    free(pathqry);

    return 0;
}