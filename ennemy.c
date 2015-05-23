#include "prototypes.h"

Ennemy ennemy;
eList ennList; 
SDL_Texture* ennemiSprite;
Player player;

double randspeed(){
	return (rand()/(double)RAND_MAX)*(1.15-0.85)+0.85;
}

double randAngle(){
	return (rand()%360)*2*M_PI/360;
}

int randDim(){
	return (rand()%2)+1;
}

Ennemy* createEnnemy(Name name){
	Ennemy* e=malloc(sizeof(Ennemy));
	e-> dimension = randDim();
	e -> speed=(double)ENEMY_SPEED_BASE*randspeed();
	e -> name=name;
	e -> appRadius = RADIUS;
	e -> appAngle = randAngle();
	e -> timer = TIMER;
	e -> lifetime = MONSTER_LIFETIME;
	e -> posX = (double)(PLR_X + RADIUS*cos(e->appAngle));
	e -> posY = (double)(PLR_Y + RADIUS*sin(e->appAngle));
	e -> progressX = e->speed*cos(e->appAngle);
	e -> progressY =e->speed*sin(e->appAngle);	
	return e;
}

eList headAddEnneny(eList list){
	eList e = malloc(sizeof(Ennemy));
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
			e->lifetime-=1;
		}//afjout supression sui lifetime ==0
		e=e->next;	
	}
}

eList getEnnemy(eList list, int indice){
    int i;
    for(i=0; i<indice && list != NULL; i++){
        list = list->next;
		}
    if(list == NULL){
        return NULL;
    }else{
        return list;
    }
}

eList deleteEn(Ennemy* toDelete,eList list){
	Ennemy* e = list;
	Ennemy* last = list;
	eList toReturn;
	int done = 0;
	while(e!=NULL && done == 0){
		if(e==toDelete){
			if(e==list){
				list=toDelete->next;
				deleteEnnemy(toDelete);
				done=1;
				return list;
			}else{
			if(e->next==NULL){
				last->next==NULL;
				deleteEnnemy(toDelete);
				done=1;
				return list;				
			}else{
				last->next = e->next;
				deleteEnnemy(toDelete);
				done=1;
				return list;
			}
		}
		last=e;
		e=e->next;
	}
	}
} 

void initEnnemySprites(void){
	ennemiSprite=loadImage("tuk.png");
}

