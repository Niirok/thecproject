#ifndef PROTOTYPES_H
#define PROTOTYPES_H
 
#include "structs.h"
 
/* Catalogue des prototypes des fonctions utilisées.
   On le complétera au fur et à mesure. */
 
extern void cleanMaps(void);
extern void cleanup(void);
extern Ennemy* createEnnemy(Name name);
extern void delay(unsigned int frameLimit);
extern void deleteEnnemy(Ennemy* ennemy);
extern void drawGame(void);
extern void drawImage(SDL_Texture *image, int x, int y);
extern void drawMap(void);
extern void dimSwitch(Input *input);
extern void gestionInputs(Input *input);
extern void getInput(Input *input);
extern void init(char *);
extern void initInputs(Input* i);
extern void initMaps(void);
extern void initializePlayer(void);
extern void loadGame(void);
extern SDL_Renderer *getrenderer(void); //todo corrigé le place * dans le pointeur
extern SDL_Texture* getBackground();
extern SDL_Texture* loadImage(char* name);
extern void updateEnnemy(Ennemy* ennemy);
extern void updatePlayer(Input *input);
char* theFgets(char* s,int size, FILE* stream);
int newNiveau(char* fileName);
 
#endif
