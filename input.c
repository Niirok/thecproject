#include "structs.h"
 
void getInput(Input *input)
{
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
 
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        exit(0);
                    break;
 
                    case SDLK_a:
                        input->color1 = 1;
                    break;
 
                    case SDLK_z:
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

					case SDLK_m:
                        input->mute = 1;
                    break;

					case SDLK_p:
                        input->pause = 1;
                    break;
 
                    default:
                    break;
                }
            break;
 
            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                    case SDLK_a:
                        input->color1 = 0;
                    break;
 
                    case SDLK_z:
                        input->color2 = 0;
                    break;
 
                    case SDLK_e:
                        input->color3 = 0;
                    break;
 
                    case SDLK_q:
                        input->color4 = 0;
                    break;
 
                    case SDLK_s:
                        input->color5 = 0;
                    break;
 
                    case SDLK_d:
                        input->color6 = 0;
                    break;
 
                    case SDLK_w:
                        input->color7 = 0;
                    break;

                    case SDLK_x:
                        input->color8 = 0;
                    break;

					case SDLK_c:
                        input->color9 = 0;
                    break;

					case SDLK_m:
                        input->mute = 0;
                    break;

					case SDLK_p:
                        input->pause = 0;
                    break;
 
                    default:
                    break;
                }
            break;
 
        }
 
    }
}
void gestionInputs(Input *input)
{
    //On gère le clavier (on rajoutera plus tard la gestion
    //des joysticks)
    getInput(input);
}