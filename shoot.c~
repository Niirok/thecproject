#include "prototypes.h"

Shoot s;
Map map;
Player player;
SDL_Texture* shootSprite;
Shoot* tabShoot[15];
int firstIndex, lastIndex,currentIndex, isEmpty;

void initTabShoot(){
		int i;
		lastIndex = 0;
		currentIndex = 0;
		for(i=0;i<14;i++)
				tabShoot[i]=NULL;
		isEmpty=0;
		//tabShoot=malloc(15*sizeof(Shoot));
	}

void initShootSprite(void){
	shootSprite = loadImage("shoot.png");
}

void shootFree(Shoot* s){
	free(s);
}

void cleanShoot(void){
	if(shootSprite != NULL){
		SDL_DestroyTexture(shootSprite);
		shootSprite = NULL;
	}
}


void initializeShoot(Shoot* s){
	s->dimension = map.activemap;
	s->posX = PLR_X;
	s->posY = PLR_Y;
	
	float Dx = player.viewX - PLR_X;
	float Dy = player.viewY - PLR_Y; 
	float angle = atan2f(Dy,Dx)*180/M_PI;

	s->progressX = SHOOT_SPEED*cos(angle);
	s->progressY = SHOOT_SPEED*sin(angle);
}

void drawShoot(Shoot* s){

	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.w = 8;
	src.h = 8;
	
	
	SDL_Rect dest;
	dest.x = s->posX;
	dest.y = s->posY;
	dest.w = 8; 
	dest.h = 8;

SDL_RenderCopyEx(getrenderer(), shootSprite, &src, &dest,0, 0, SDL_FLIP_NONE);
}

void drawTabShoot(){
	int i;

	for(i=0;i<14;i++){
		if(tabShoot[i]!=NULL)
			drawShoot(tabShoot[i]);
		}
}

void updateShoot(Shoot* s){
	if(isEmpty!=0){
	s->posX = s->posX + s->progressX;
	s->posY = s->posY + s->progressY;
/*	s->posX = s->posX + s->progressX;
	s->posY = s->posY+s->progressY;
	if(s->posX <500 && s->posY<500)
		shootFree(s);*/
	}
}
void updateTabShoot(){
	int i;

	for(i=0;i<14;i++)
		updateShoot(tabShoot[i]);
	printf("je suce des grosses bites de poney");
	fflush(stdin);
	
}
void orangeShoot(){
	if(currentIndex <14){
		Shoot* s;
		s = malloc(sizeof(Shoot));
		initializeShoot(s);
		tabShoot[currentIndex] = s;
		currentIndex++;
		isEmpty=1;

	}else{
		currentIndex = 0;
		Shoot* s;
		s=malloc(sizeof(Shoot));
		initializeShoot(s);
		tabShoot[currentIndex] = s;
		currentIndex++;
	}
}



