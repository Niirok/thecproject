#ifndef DEF_DEFS
#define DEF_DEFS
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <SDL2/SDL.h>
 
/* On inclut les libs supplémentaires */
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
 
// Taille de la fenêtre : 500x500 pixels 
#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 500

#define PLR_X 250
#define PLR_Y 250
#define PLAYER_WIDTH 40
#define PLAYER_HEIGTH 40
#define CDORA 500
#define REDORA 15
#define SHOOT_SPEED 8
#define SHOOT_SIZE 4
#define MAXSHOOT 14
#define SHOOT_LIFETIME 150
#define TIMER 180
#define MONSTER_LIFETIME 1200
#define RADIUS 370
#define ENEMY_SPEED_BASE 0.5

//Nombre max de monstres à l'écran
#define ENEMY_MAX 20
 
//Dimensions du monstre
#define MONSTER_WIDTH 400
#define MONSTER_HEIGTH 479
#define SECOND 150
 
#endif
