#ifndef PROTOTYPES_H
#define PROTOTYPES_H
 
#include "structs.h"
 
/* Catalogue des prototypes des fonctions utilisées.
   On le complétera au fur et à mesure. */
 
extern void cleanMaps(void);
extern void cleanup(void);
extern void cleanPlayer(void);
extern void cleanShoot(void);
extern void cleanEnnemy(void);
extern void delay(unsigned int frameLimit);
extern void dimSwitch(Input *input);
extern Ennemy* createEnnemy(Name name);
extern void delay(unsigned int frameLimit);
extern void deleteEnnemy(Ennemy* ennemy);
extern eList deleteEn(int toDelete, eList list);
extern void drawEnnemy(eList list);
extern void drawGame(void);
extern void drawImage(SDL_Texture *image, int x, int y);
extern void drawMap(void);
extern void drawShoot(sList list);
extern void updateShoot(sList list);
extern void gestionInputs(Input *input);
extern Ennemy* getEnnemy(eList list, int i);
extern void getInput(Input *input);
extern void init(char *);
extern void initInputs(Input* i);
extern void initMaps(void);
extern void initializeNewShoot(void);
extern void initializePlayer(void);
extern void initShootSprite(void);
extern void initPlayerSprite(void);
extern void loadGame(void);
extern SDL_Renderer *getrenderer(void); 
extern SDL_Texture* getBackground(void);
extern SDL_Texture* loadImage(char* name);
extern void updateEnnemy(eList list,sList shlist);
extern void updatePlayer(Input *input);
extern Shoot* getShoot(int i);
extern int getShootNbr(void);
extern void resetShoot(void);
extern sList headAddShoot(sList list);
extern char* theFgets(char* s,int size, FILE* stream);
extern int newNiveau(char* fileName);
 
#endif
