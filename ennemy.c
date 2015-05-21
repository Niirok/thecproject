#include "prototypes.h"

Ennemy ennemy;
eList ennList; 
SDL_Texture* ennemiSprite;

double randspeed(){
	return (rand()/(double)RAND_MAX)*(1.15-0.85)+0.85;
}

int randAngle(){
	return rand()%360;
}

Ennemy* createEnnemy(Name name){
	Ennemy* e=malloc(sizeof(Ennemy));
	e-> dimension = 1;//randomiser
	e -> speed=(double)ENEMY_SPEED_BASE*randspeed();
	e -> name=name;
	e -> appRadius = RADIUS;
	e -> appAngle = randAngle()*2*M_PI/360;
	e -> timer = TIMER;
	e -> posX = (double)PLR_X + RADIUS*cos(e->appAngle);
	e -> posY = (double)PLR_Y + RADIUS*sin(e->appAngle);
	e -> progressX = (double)(e->speed)*cos(e->appAngle);
	e -> progressY =(double)(e->speed)*sin(e->appAngle);	
	return e;
}

eList headAddEnneny(eList list){
	Ennemy* e = malloc(sizeof(Ennemy));
	e = createEnnemy(octogone);
	e ->next = list;
	return e;
}


void deleteEnnemy(Ennemy* ennemy){
	free(ennemy);
}

void drawEnnemy(eList list){
	Ennemy* e = list;

	while( e != NULL){
			SDL_Rect src;
			src.x = 0;
			src.y = 0;
			src.w = MONSTER_WIDTH;
			src.h = MONSTER_HEIGTH;
		
			SDL_Rect dest;
			dest.x = e->posX;
			dest.y = e->posY;
			dest.w = 25; 
			dest.h = 30;

			SDL_RenderCopyEx(getrenderer(), ennemiSprite, &src, &dest,0, 0, SDL_FLIP_NONE);
			e=e->next;
	}	
}

void updateEnnemy(eList list){
	Ennemy* e = list;
	while	(e != NULL){
		e->timer-=1;
		printf("diminution du timer");
		if (e->timer < 0){
			e->posX-=e->progressX;
			e->posY-=e->progressY;
		}
		e=e->next;	
	}
}

void initEnnemySprites(void){
	ennemiSprite=loadImage("tuk.png");
}

