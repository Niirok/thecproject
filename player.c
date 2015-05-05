#include "prototypes.h"

Player player;

void initializePlayer(void){
	player.health = 100;
	player.score = 0;
	player.cdOra = 0;
	player.cdYell=0;player.active[1]=0; 
	player.cdRed=0;player.active[2]=0; 
	player.cdNBlu=0; player.active[3]=0;
	player.cdTur=0;player.active[4]=0;
	player.cdGree=0;player.active[5]=0;
	player.cdPur=0; player.active[6]=0;
	player.cdPin=0;player.active[7]=0;
	player.cdVio=0;player.active[8]=0;
	player.active[0]=1;
	
}

