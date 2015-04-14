#include "prototypes.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
 
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
 
 
void drawGame(void)
{
 
    // Remplis le renderer de noir, efface l'écran et l'affiche.
    //SDL_RenderPresent() remplace SDL_Flip de la SDL 1.2
 
    SDL_SetRenderDrawColor(getrenderer(), 0, 0, 0, 255);
    SDL_RenderClear(getrenderer());
    SDL_RenderPresent(getrenderer());
 
    // Délai pour laisser respirer le proc
    SDL_Delay(1);
}
 
 
void delay(unsigned int frameLimit)
{
    // Gestion des 60 fps (images/stories/seconde)
    unsigned int ticks = SDL_GetTicks();
 
    if (frameLimit < ticks)
    {
        return;
    }
 
    if (frameLimit > ticks + 16)
    {
        SDL_Delay(16);
    }
 
    else
    {
        SDL_Delay(frameLimit - ticks);
    }
}