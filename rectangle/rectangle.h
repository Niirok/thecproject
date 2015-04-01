#ifndef RECTANGLE_H
#define RECTANGLE_H

struct Rectangle{
   int radius;
   double angle;
   int speed;// vitesse du rectangle
   int dimension;
};
typedef struct Rectangle * Rectangle;
Rectangle rectanglenCreate();
int main();
void rectangleMove(Rectangle r);
void rectangleDimension(Rectangle r);
void rectangleFree(Rectangle r);
#endif
