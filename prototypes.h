#ifndef PROTOTYPES_H
#define PROTOTYPES_H
 
#include "structs.h"
 
/* Catalogue des prototypes des fonctions utilisées.
   On le complétera au fur et à mesure. */
 
extern void cleanMaps(void);
extern void cleanup(void);
extern void delay(unsigned int frameLimit);
extern void drawGame(void);
extern void drawImage(SDL_Texture *image, int x, int y);
//extern void drawMap(int);
extern void gestionInputs(Input *input);
extern void getInput(Input *input);
extern void init(char *);
extern void initInputs(Input* i);
extern void initMaps(void);
extern  void loadGame(void);
extern SDL_Renderer *getrenderer(void); //todo corrigé le place * dans le pointeur
extern SDL_Texture* getBackground();
extern SDL_Texture* loadImage(char* name);


extern void initialazePlayer(void); 

 
 
#endif