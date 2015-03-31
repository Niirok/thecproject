#ifndef CROSS_H
#define CROSS_H

typedef struct Cross {
    double angle;
    int radius;
    int angularSpeed;
    int radiusReduc;
    int dimension;
}Cross;

Cross* crossCreate(double angle);
void crossFree(Cross* cr);
void crossMove(Cross* cr);

#endif /* POINT_H */