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

#endif
