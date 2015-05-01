#ifndef PROTOTYPES_H
#define PROTOTYPES_H
 
#include "structs.h"
 
/* Catalogue des prototypes des fonctions utilisées.
   On le complétera au fur et à mesure. */
 
extern void cleanup();
extern void delay(unsigned int frameLimit);
extern void drawGame();
extern void gestionInputs(Input *input);
extern void getInput(Input *input);
extern SDL_Renderer *getrenderer();
extern void init(char *);
 
 
#endif