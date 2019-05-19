#include<math.h>
#include"lista.h"
#include"circulo.h"
#include"retangulo.h"


/*calcula a distancia euclidiana entre os pontoos (x1,y1) e (x2,y2)*/
double distancia (double x1, double y1, double x2, double y2){
    double dx = x2 - x1;
    double dy = y2 - y1;

    double dist = sqrt(dx*dx + dy * dy);
    return dist;
}

double max(double n1,double n2){
    if(n1>n2)
        return n1;
    else
        return n2;
}

double min(double n1,double n2){
    if(n1<n2)
        return n1;
    else
        return n2;
}
int collision(double recX,double recY,double recW,double recH,double cX,double cY,double cR){
    double deltaX;
    double deltaY;
    
    deltaX=cX-max(recX,min(cX,recX+recW));
    deltaY=cY-max(recY,min(cY,recY+recH));
    if((deltaX*deltaX+deltaY*deltaY)<=(cR*cR))
        return 1;
    else
        return 0;
}

int sobreposicao(Formas forma1,Formas forma2, FILE *arq3){
    double cx1, cy1,cx2,cy2,r1,r2,w1,h1,w2,h2;
    char tipo1, tipo2;
    //res(resultado),dis(distancia),raios(soma dos raios ou so o raio)
    int res,dis,raios;
    double w,h;
    char cor[]="red";
    //verifica se as duas formas sao circulos
    if(tipo1=='c'&&tipo2=='c'){
        //calcula a distancia entre os rcentros
        dis=distancia(cx1,cy1,cx2,cy2);
        //soma so raios
        raios=r1+r2;
        //verifica se a distancia é menos ou igual ao soma dos raios
        if(dis<=raios)
            res=1;
        else
            res=0;

        w=max(cx1,cx2)-min(cx1,cx2)+r1+r2;
            
        h=max(cy1,cy2)-min(cy1,cy2)+r1+r2;
        criaRetangulodash(min(cx1,cx2)-max(r1,r2),min(cy1,cy2)-max(r1,r2),w,h,cor,arq3,res);
            
    //verifica se as formas sao um retangulo e um circulo
    }else if(tipo1=='r'&& tipo2=='c'){
        res=collision(cx1,cy1,w1,h1,cx2,cy2,r2);
        w=max(cx1+w1,cx2+r2)-min(cx1,cx2-r2);    
       h=max(cy1+h1,cy2+r2)-min(cy1,cy2-r2);
        criaRetangulodash(min(cx1,cx2-r2),min(cy1,cy2-r2),w,h,cor,arq3,res);
    //verifica se as formas sao um circulo e um retangulo    
    }else if(tipo1=='c'&& tipo2=='r'){
        res=collision(cx2,cy2,w2,h2,cx1,cy1,r1);
        w=max(cx2+w2,cx1+r1)-min(cx2,cx1-r1);    
        h=max(cy2+h2,cy1+r1)-min(cy2,cy1-r1);
        criaRetangulodash(min(cx2,cx1-r1),min(cy2,cy1-r1),w,h,cor,arq3,res);
    //verifica se as duas formas sao retangulos
    }else if(tipo1=='r'&& tipo2=='r'){
        if(cx1<cx2+w2 && cx1+w1>cx2 && cy1<cy2+h2 && cy1+h1>cy2)
          res=1;
         w=max(cx1+w1,cx2+w2)-min(cx1,cx2);   
       h=max(cy1+h1,cy2+h2)-min(cy1,cy2);
       criaRetangulodash(min(cx1,cx2),min(cy1,cy2),w,h,cor,arq3,res);
          
    }

    return res;
}
