int pontoInternoCirculo(double px, double py, double cx, double cy, double r){
    double d = distancia (px,py,cx,cy);
    int res = d <= r? 1:0;
    return res;
}

void deslocaCirculo(double dx, double dy){
    cx=cx+dx;
    cy=cy+dy;
}