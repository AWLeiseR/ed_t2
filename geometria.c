#include<math.h>
#include<stdio.h>



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


int pontoInternoCirculo(double px, double py, double cx, double cy, double r){
    double d = distancia (px,py,cx,cy);
    int res = d <= r? 1:0;
    return res;
}

int pontoInteriorRetangulo(double px, double py, double cx1, double cy1, double cx2, double cy2){
    if(px>=cx1 && px<=cx2 && py>=cy1 && py<=cy2)
        return 1;
    else
        return 0;
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

int sobreposicao(double x1, double y1, double r1, double x2, double y2,double r2,FILE *arq3){
    int res;
    double x,y,h,w;
    //calcula a distancia entre os rcentros
    dis=distancia(x1,y1,x2,y2);
    //soma so raios
    raios=r1+r2;
    //verifica se a distancia é menos ou igual ao soma dos raios
    if(dis<=raios)
        res=1;
    else
        res=0;

    w=max(x1,x2)-min(x1,x2)+r1+r2;
                    
    h=max(y1,y2)-min(y1,y2)+r1+r2;
    imprimiRetangulodash(min(x1,x2)-max(r1,r2),min(y1,y2)-max(r1,r2),w,h,cor,arq3,res);
    return res;
}
