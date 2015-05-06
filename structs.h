#ifndef DEF_STRUCTS
#define DEF_STRUCTS
 
#include "defs.h"
 
/* Structures qui seront utilisées pour gérer le jeu */

typedef struct Input{ // Structure pour gérer l'input clavier

    int orange, yellow, red, navyblue, turquoise, green, purple,pink,violet,pause,mute,changeBack,aimx, aimy;
} Input;

typedef struct Player {

	int health, score, cdOra, cdYell, cdRed, cdNBlu, cdTur, cdGree, cdPur, cdPin, cdVio;
	int active[9];
} Player;

typedef struct Shoot{
	int dimension;// dimension of the shoot	
	const int speed;
	int posX;
	int posY;
	int progressX;
	int progressY;
}Shoot;

/*début des fonctions de la structure shoot*/

shoot shoot(int x, int y);
int maxAbs (int x, int y); 
#endif
