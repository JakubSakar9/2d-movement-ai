#include <SDL2/SDL.h>
#include "Params.hpp"

class Renderer {
    public:
        SDL_Renderer *renderer;
        void DrawToScreen();
        void Update();
};