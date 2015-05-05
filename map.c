#include "prototypes.h"
#include "structs.h" 
#include <SDL2/SDL.h>
 
Map map1;
Map map2;
int mapChange=0; 
Input* i; 
void initMaps(void) {
	// Charge l'image du fond (background)
	map1.background = loadImage("Dim1.bmp");
	map2.background = loadImage("Dim2.bmp");
}

 // Todo gérer le multi background après l'implé du switch via touch
SDL_Texture* getBackground() {
	/*if(i -> changeBack==1){
		if(mapChange == 0){
			mapChange=1;		
		}
		if(mapChange == 1){
			mapChange=0;		
		}	
	
		if(mapChange == 0){	
			return map1.background;
		}

		else{return map2.background;}
	}
	*/
	if(mapChange == 0){	
		return map1.background;
	}

	else{return map2.background;}

}
 
 
void cleanMaps(void){
	// Libère la texture du background
	if (map1.background != NULL)	{
		SDL_DestroyTexture(map1.background);
		map1.background = NULL;
	}
	if (map2.background != NULL)	{
		SDL_DestroyTexture(map2.background);
		map2.background = NULL;
	}
 
}