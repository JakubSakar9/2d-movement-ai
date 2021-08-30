#include <SDL2/SDL.h>
 
int main(int argc, char ** argv)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
    }
    else{
        SDL_Log("SDL initialized successfully");
    }
    SDL_Quit();
 
    return 0;
}