#include "prototypes.h"
Ennemy ennemy;
SDL_Texture* ennemiSprite;

Ennemy* createEnnemy(Name name){
	Ennemy* ennemy=malloc(sizeof(Ennemy));
	ennemy -> health=1;
	ennemy -> speed=1;
	ennemy -> name=name;
	ennemy -> posX=42;
	ennemy -> posY=42;
}

void deleteEnnemy(Ennemy* ennemy){
	free(ennemy);
}

void updateEnnemy(Ennemy* ennemy){
	float dist;	
	float alpha;
	switch(ennemy -> name){
		case octogone:
		dist= sqrt(pow(ennemy->posX-PLR_X,2)+pow(ennemy->posY-PLR_Y,2))-60*ennemy->speed;
		alpha= atan(abs(ennemy->posX-PLR_X)/abs(ennemy->posY-PLR_Y));
		ennemy->posX=sin(alpha)*dist;
		ennemy->posY=cos(alpha)*dist;

		break;
	}
}

void initEnnemySprites(void){
	ennemiSprite=loadImage("tuk.png");
}

