#include "prototypes.h"

void initInputs(Input* input){
	input->orange=0;
	input->yellow=0;
	input->red=0;
	input->navyblue=0;
	input->turquoise=0;
	input->green=0;
	input->purple=0;
	input->pink=0;
	input->violet=0;
	input->pause=0;
	input->mute=0;
	input->changeBack=0;
	input->aimX=0;
	input->aimY=0;
}
 
void gestionInputs(Input *input){
    getInput(input);
}
 
 
void getInput(Input *input){

    SDL_Event event;
    int x,y;
	  while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
 
            case SDL_QUIT:
                exit(0);
            break;
            
            case SDL_MOUSEBUTTONDOWN:
								switch (event.button.button){
										case SDL_BUTTON_LEFT:
											input->orange = 1;
										break;
										
										default:
										break;
								 }
						break;
						
						case SDL_MOUSEBUTTONUP:
								switch (event.button.button)
								{
										case SDL_BUTTON_LEFT:
											input->orange = 0;
										break;
										
										default:
										break;
								 }
						break;
						
						case SDL_KEYUP:
								switch (event.key.keysym.sym){
 
                    case SDLK_a:
                        input->yellow = 0;
										break;
 
                    case SDLK_q:
                        input->navyblue = 0;
                    break;
 
                    case SDLK_s:
                        input->turquoise = 0;
                    break;
 
                    case SDLK_d:
                        input->green = 0;
                    break;
 
                    case SDLK_w:
                        input->purple = 0;
                    break;
 
                    case SDLK_x:
                        input->pink = 0;
                    break;
 
                    case SDLK_c:
                        input->violet = 0;
                    break;
                    
                    case SDLK_SPACE:
                        input->changeBack = 0;
                    break;
                 
                    default:
                    break; 
                  }  

            case SDL_KEYDOWN:
            
                switch (event.key.keysym.sym){
                
                    case SDLK_ESCAPE:
                        exit(0);
                    break;
 
                    case SDLK_a:
                        input->yellow = 1;
										break;
 
                    case SDLK_q:
                        input->navyblue = 1;
                    break;
 
                    case SDLK_s:
                        input->turquoise = 1;
                    break;
 
                    case SDLK_d:
                        input->green = 1;
                    break;
 
                    case SDLK_w:
                        input->purple = 1;
                    break;
 
                    case SDLK_x:
                        input->pink = 1;
                    break;
 
                    case SDLK_c:
                        input->violet = 1;
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
											if(input->changeBack == 0){
                        input->changeBack = 1;
											}else{input->changeBack =0;}
                    break;
 
                    default:
                    break;
                }
           break;
        }
    }
    SDL_GetMouseState(&x,&y);
    input->aimX = x;
    input->aimY = y;
}
