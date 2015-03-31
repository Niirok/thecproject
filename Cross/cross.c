#include "cross.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>


Cross* crossCreate(double appangle){
	srand(time(NULL));
	Cross* cr = malloc(sizeof(Cross));
	cr -> angle = appangle;
	cr -> radius = (500/cos(appangle))+1;
	cr -> angularSpeed = rand()%(12-5)+5;
	cr -> radiusReduc = rand()%(8-3)+3;
	cr -> dimension = 1;
	return cr;
}

void crossFree(Cross* cr){ 
	free(cr);}

void crossMove(Cross* cr){
	cr -> angle += cr->angularSpeed;
	cr -> radius -= cr->radiusReduc;
} 