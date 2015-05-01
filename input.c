#include "prototypes.h"
#include <SDL2/SDL.h>
 
void gestionInputs(Input *input){
    getInput(input);
    
    if(input->shoot==1){/*gerer le tir en fonction de la couleur jaune ou orange*/}
    if(input->m==1){/*mute le jeu*/}
    if(input->p==1){/*pause le jeu tant que cette valeur est de 1*/}
    if(input->yellow==1){/*laser,check jaune, si disponible, activation*/}
    if(input->red==1){/*heal,check red, si disponible, activation*/}
    if(input->navyblue==1){/*slow, check navyblue, si disponible, activation*/}
    if(input->turquoise==1){/*ally,check turquoise, si disponible, activation*/}
    if(input->green==1){/*full circle,check green, si disponible, activation*/}
    if(input->purple==1){/*nuke,check purple si disponible, activation*/}
    if(input->pink==1){/*freeze total, check pink, si disponible, activation*/}
    if(input->violet==1){/* invincible, check violet, si disponible, activation*/}   
}
 
 
void getInput(Input *input){

    SDL_Event event;
 
    /* Keymapping : gère les appuis sur les touches et les enregistre
    dans la structure input */
 
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
 
            case SDL_QUIT:
                exit(0);
            break;
            
            case SDL_MOUSEBUTTONDOWN:
								switch (event.button.button)
								{
										case SDL_BUTTON_LEFT:
											input->shoot = 1;
										break;
										
										default:
										break;
								 }
						break;
						
						case SDL_MOUSEBUTTONUP:
								switch (event.button.button)
								{
										case SDL_BUTTON_LEFT:
											input->shoot = 0;
										break;
										
										default:
										break;
								 }
						break;
							
            case SDL_KEYDOWN:
            
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        exit(0);
                    break;
 
                    case SDLK_a:
                        input->color2 = 1;
                    break;
 
                    case SDLK_e:
                        input->color3 = 1;
                    break;
 
                    case SDLK_q:
                        input->color4 = 1;
                    break;
 
                    case SDLK_s:
                        input->color5 = 1;
                    break;
 
                    case SDLK_d:
                        input->color6 = 1;
                    break;
 
                    case SDLK_w:
                        input->color7 = 1;
                    break;
 
                    case SDLK_x:
                        input->color8 = 1;
                    break;
 
                    case SDLK_c:
                        input->color9 = 1;
                    break;
                    
                    case SDLK_p:
                    	if (input->pause == 0){
                        input->pause = 1;
                        }else{ input-> pause = 0;}
                    break;
                    
                    case SDLK_m:
                    	if (input->mute == 0){
                        input->mute = 1;
                        }else{ input-> mute = 0;}
                    break;
 
 										case SDLK_SPACE:
                        input->changeBack = 1;
                    break;
 
                    default:
                    break;
                }
           break;
        }
    }
}
