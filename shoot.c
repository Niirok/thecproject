#include "prototypes.h"

Map map;
Player player;
SDL_Texture* shootSprite;
sList tabShoot;

sList deleteTail(sList list){
	if (list== NULL)
		return NULL;
	if(list->next ==NULL){
		free(list);
		return NULL;
	}
	Shoot* tmp = list;
	Shoot* ptmp = list;

	while(tmp->next !=NULL){
		ptmp = tmp;
		tmp = tmp->next;
	}
	ptmp->next = NULL;
	free (tmp);
	return list;
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

void updateShoot(sList list){
	Shoot* first = list;	
	Shoot* s = list;
	while(s != NULL){
		s->lifetime-=1;
		s->posX+=s->progressX;
		s->posY+=s->progressY;
		//if (collide(getShoot(), &monster[i]) == 1){//traitement}
		if(s->lifetime == 0){
			printf("nombre de missile --");
			tabShoot = deleteTail(tabShoot);
		}
		s = s->next;
	}
}

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

void drawShoot(sList list){
	Shoot* s = list;
	while(s != NULL){
		SDL_Rect src;
		src.x = 0;
		src.y = 0;
		src.w = SHOOT_SIZE;
		src.h = SHOOT_SIZE;
	
	
		SDL_Rect dest;
		dest.x = s->posX;
		dest.y = s->posY;
		dest.w = SHOOT_SIZE; 
		dest.h = SHOOT_SIZE;

		SDL_RenderCopyEx(getrenderer(), shootSprite, &src, &dest,0, 0, SDL_FLIP_NONE);
		s=s->next;
	}	
}

void shootFree(Shoot* s){
	free(s);
}

sList headAddShoot(sList list){

	float Dx = player.viewX - PLR_X;
	float Dy = player.viewY - PLR_Y;
	float angle = atan2f(Dy,Dx);
	Shoot* s = malloc(sizeof(Shoot));
	s->dimension = map.activemap;
	s->posX = PLR_X;
	s->posY = PLR_Y;
	s->progressX = SHOOT_SPEED*cos(angle);
	s->progressY = SHOOT_SPEED*sin(angle);
	s->lifetime = SHOOT_LIFETIME;
	s->next = list;
	return s;
}

