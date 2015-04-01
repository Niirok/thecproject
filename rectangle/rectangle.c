#include "rectangle.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

Rectangle rectangleCreate(){
  Rectangle r= (Rectangle) malloc(sizeof(Rectangle));
  srand(time(NULL));
  r->radius =rand()%600;
  r->angle = rand()%(7);
  r->speed = 8;
  r->dimension = rand()%2;
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
