#include "prototypes.h"

Ennemy ennemy;
eList ennList;
sList shList; 
SDL_Texture* ennemiSpritedim;
SDL_Texture* ennemiSpritenotdim;
Player player;
Map map;

int collide(Ennemy* e, sList list)
{
	Shoot* s = list;
	int isHit = 0; 
	while(s!=NULL){
		//On teste pour voir s'il n'y a pas collision, si c'est le cas, on renvoie 0
		if(e->dimension == s->dimension){
			if(s->posX>= e->posX && s->posX<= e->posX +30 && s->posY >= e->posY && s->posY <= e->posY + 25){
				printf("detection de collision");
				return 1;
			}
		}
		s=s->next;
	}
	return 0;
}

double randspeed(){
	return (rand()/(double)RAND_MAX)*(1.15-0.85)+0.85;
}

double randAngle(){
	return (rand()%360)*2*M_PI/360;
}

int randDim(){
	return (rand()%2)+1;
}

int getID(Ennemy* e){
	return e->id;
}

Ennemy* createEnnemy(Name name){
	static int idg =0;
	Ennemy* e=malloc(sizeof(Ennemy));
	e->id =idg;
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
	idg++;	
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

			if (e->dimension == map.activemap){
			SDL_RenderCopyEx(getrenderer(), ennemiSpritedim, &src, &dest,0, 0, SDL_FLIP_NONE);
			}else{SDL_RenderCopyEx(getrenderer(), ennemiSpritenotdim, &src, &dest,0, 0, SDL_FLIP_NONE);}
			e=e->next;
	}	
}

void updateEnnemy(eList list,sList shList){
	Ennemy* e = list;
	int i =0;
	while	(e != NULL){
		e->timer-=1;
		//printf("diminution du timer");
		if (e->timer < 0){
			e->posX-=e->progressX;
			e->posY-=e->progressY;
			e->lifetime-=1;
			if(collide(e,shList)==1){
				list= deleteEn(getID(e),list);
			}	
		}//afjout supression sui lifetime ==0
		e=e->next;
		i++;	
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

eList deleteEn(int idToDelete,eList list){
	eList l1=malloc(sizeof(Ennemy));
	eList l2= malloc (sizeof(Ennemy));
	if (list!=NULL){
		if(list->id==idToDelete){
			l2= list;
			list =list->next;
			free(l2);
		}else{
			l1=list;
			l2=list->next;
			while (l2!=NULL){
				if(l2->id!=idToDelete){
					l1=l2;
					l2=l2->next;					
				}else{
					l1->next=l2->next;		
					free(l2);
				}
			}
		}	
	}//else{free(list);return NULL;}
	return list;
} 

void initEnnemySprites(void){
	ennemiSpritedim=loadImage("tuk.png");
	ennemiSpritenotdim=loadImage("tuk2.png");
}

void cleanEnnemy(){
	if(ennemiSpritedim!=NULL){
		SDL_DestroyTexture(ennemiSpritedim);
		ennemiSpritedim=NULL;	
	}
	if(ennemiSpritenotdim!=NULL){
		SDL_DestroyTexture(ennemiSpritenotdim);
		ennemiSpritenotdim=NULL;	
	}

}

