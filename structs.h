#ifndef DEF_STRUCTS
#define DEF_STRUCTS
 
#include "defs.h"
 
/* Structures qui seront utilisées pour gérer le jeu */

typedef struct Input{ // Structure pour gérer l'input clavier

    int orange, yellow, red, navyblue, turquoise, green, purple,pink,violet,pause,mute,changeBack,aimX, aimY;
}Input;


 typedef struct Map
{
	SDL_Texture* dim1;
	SDL_Texture* dim2;
	int activemap;
}Map; 


typedef struct Player {

	int health, score, cdOra, cdYell, cdRed, cdNBlu, cdTur, cdGree, cdPur, cdPin, cdVio, viewX, viewY;

	int active[9];
}Player; 

typedef enum Name{
	octogone, rectangle, cross
}Name;

typedef struct Ennemy{
	
	Name name;
	int dimension;
	int lifetime;
	double speed;
	double posX;
	double posY;
	double progressX;
	double progressY;
	int timer;
	double appAngle;
	int appRadius;
	int id;
	int isDead;

	struct Ennemy* next;
}Ennemy;

typedef Ennemy* eList;//liste chainée d'ennemis

typedef struct Shoot{
	int dimension;// dimension of the shoot	
	int posX;
	int posY;
	int progressX;
	int progressY;
	int lifetime;
	struct Shoot* next;
}Shoot;

typedef Shoot* sList;
#endif

