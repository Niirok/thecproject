		Mix_CloseAudio();
    Mix_Quit();
 
    //On fait le ménage et on remet les pointeurs à NULL
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(screen);
    screen = NULL;
 
    //On quitte SDL_TTF 2
    TTF_Quit();
 
    //On quitte la SDL 
    SDL_Quit();