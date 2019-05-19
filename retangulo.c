int pontoInteriorRetangulo(double px, double py, double cx1, double cy1, double cx2, double cy2){
    if(px>=cx1 && px<=cx2 && py>=cy1 && py<=cy2)
        return 1;
    else
        return 0;
} 

void deslocaRetangulo(double dx, double dy){
    cx=cx+dx;
    cy=cy+dy;
}