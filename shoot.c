#include "prototypes.h"

int shootNbr;
Map map;
Player player;
SDL_Texture* shootSprite;
Shoot tabShoot[MAXSHOOT];


Shoot* getShoot(int i){
	 return &tabShoot[i];
}

int getShootNbr(){
	 return shootNbr;
}

void resetShoot(void){
	shootNbr = 0;
}

void initShootSprite(void){
	shootSprite = loadImage("shoot.png");
}

void cleanShoot(void){
	if(shootSprite != NULL){
		SDL_DestroyTexture(shootSprite);
		shootSprite = NULL;
	}
}

void initializeNewShoot(){
	if (shootNbr < MAXSHOOT){
		tabShoot[shootNbr].dimension = map.activemap;
		tabShoot[shootNbr].posX = PLR_X;
		tabShoot[shootNbr].posY = PLR_Y;
		/* Hauteur et largeur de notre monstre (rajouté dans les defs ;) ) */
		//tabShoot[shootNbr].w = MONSTER_WIDTH;
		//tabShoot[shootNbr].h = MONSTER_HEIGTH;

	float Dx = player.viewX - PLR_X;
	float Dy = player.viewY - PLR_Y; 
	float angle = atan2f(Dy,Dx)*180/M_PI;

	tabShoot[shootNbr].progressX = SHOOT_SPEED*cos(angle);
	tabShoot[shootNbr].progressY = SHOOT_SPEED*sin(angle);
	printf("nombre de missile : %d \n",shootNbr);
	shootNbr++;
	if(shootNbr==MAXSHOOT){
		shootNbr =0;	
	}
	}
}


void updateShoot(){
	int i;
	for (i = 0; i < shootNbr; i++){//On passe en boucle tous les shoot du tableau
		/*if (tabShoot[i].posX<510||tabShoot[i].posY<510){//gestion du tir hors cadre
			//gestion de la disparition d'un sprite
 				}*/
		
	tabShoot[i].posX = tabShoot[i].posX + tabShoot[i].progressX;
	tabShoot[i].posY = tabShoot[i].posY + tabShoot[i].progressY;
 }
}
 
//On détecte les collisions avec les ennemis
//if (collide(getShoot(), &monster[i]) == 1){//traitement}

/* int collide(GameObject *player, GameObject *monster)
{
//On teste pour voir s'il n'y a pas collision, si c'est le cas, on renvoie 0
if ((player->x >= monster->x + monster->w)
|| (player->x + player->w <= monster->x)
|| (player->y >= monster->y + monster->h)
|| (player->y + player->h <= monster->y)
)
return 0;
 
//Sinon, il y a collision. Si le joueur est au-dessus du monstre (avec une marge
//de 10 pixels pour éviter les frustrations dues au pixel perfect), on renvoie 2.
//On devra alors tuer le monstre et on fera rebondir le joueur.
else if (player->y + player->h <= monster->y + 10)
{
player->dirY = -JUMP_HEIGHT;
return 2;
}
 
//Sinon, on renvoie 1 et c'est le joueur qui meurt...
else
return 1;
}
*/ 

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

/*void shootFree(Shoot* s){
	free(s);
}
*/

/*
void initializeShoot(Shoot* s){
	s->dimension = map.activemap;
	s->posX = PLR_X;
	s->posY = PLR_Y;
	
	float Dx = player.viewX - PLR_X;
	float Dy = player.viewY - PLR_Y; 
	float angle = atan2f(Dy,Dx)*180/M_PI;

	s->progressX = SHOOT_SPEED*cos(angle);
	s->progressY = SHOOT_SPEED*sin(angle);
}*/

/*void orangeShoot(){
	if(shootNbr <MAXSHOOT){
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
}*/



