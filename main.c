#include <SDL2/SDL.h>
#include <stdbool.h>
#include "paramdef.h"
#include "draw.c"
#include "input.c"

Input input; // prise en compte des touches claviers

SDL_Window* window = NULL;	// The window 

SDL_Surface* screen = NULL;	//The window surface 

SDL_Event event; //The event structure 

_Bool running = true;	//Flag booleen de boucle de jeu

SDL_Surface* image = NULL;	//to put the loaded image 

int main( int argc, char* args[] )
{
	unsigned int frameLimit = SDL_GetTicks() + 16;
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    printf( "SDL2 could not initialize! SDL2_Error: %s\n", SDL_GetError() );
  } else {
    window = SDL_CreateWindow(
      WINDOW_TITLE,
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      SCREEN_WIDTH,
      SCREEN_HEIGHT,
      SDL_WINDOW_SHOWN);

    screen = SDL_GetWindowSurface( window );
    image = SDL_LoadBMP( "sdl.bmp" );
    while( running ) {
      while( SDL_PollEvent( &event ) != 0 ) {
        if( event.type == SDL_QUIT ) {
          running = false;
        }
			delay(frameLimit);
      frameLimit = SDL_GetTicks() + 16;
      }

      SDL_BlitSurface( image, NULL, screen, NULL );
      SDL_UpdateWindowSurface( window );
    }
  }
  SDL_FreeSurface( image );
  SDL_DestroyWindow( window );
  SDL_Quit();
  return 0;
}
