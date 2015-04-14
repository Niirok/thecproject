#include "prototypes.h"
 
 
//Déclaration des variables / structures utilisées par le jeu 

Input input; // prise en compte du duo clavier souris
 
 
int main(int argc, char *argv[])
{
    unsigned int frameLimit = SDL_GetTicks() + 16;
    int ongoing;
 
    // Initialisation de la SDL 
    init("ColorPoc");
 
    // Appelle la fonction cleanup à la fin du programme 
    atexit(cleanup);
 
    ongoing = 1;
 
    // Boucle infinie, principale, du jeu 
    while (ongoing == 1)
    {
        //Gestion des inputs clavier
        gestionInputs(&input);
 
        //On dessine tout
        drawGame();
 
        // Gestion des 60 fps (1000ms/60 = 16.6 -> 16 
        delay(frameLimit);
        frameLimit = SDL_GetTicks() + 16;
    }
 
    // On quitte
    exit(0);
 
}