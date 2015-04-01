#include "rectangle.h"
#include <math.h>
#include <stdlib.h>

Rectangle rectangleCreate(){
  Rectangle r= (Rectangle) malloc(sizeof(Rectangle));
  r->radius =1;
  r->angle = 1;
  r->speed = 1;
  r->dimension = 1;
  return r;
}
int main(){
  return 0;
}
void rectangleMove(Rectangle r){
  r -> radius += r -> speed;
}
void rectangleDimension(Rectangle r){
  r-> dimension =(r->dimension+1)%2;
}

void rectangleFree(Rectangle r){
  free(r);
}
