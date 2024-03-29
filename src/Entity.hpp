#pragma once

#include "SDL2/SDL.h"

#include "Params.hpp"
#include "Vector2.hpp"

class Entity {
    public:
        Entity(Vector2 origin, Vector2 _size, SDL_Color _color);
        void Render(SDL_Renderer *renderer);
        void Update(Vector2 velDiff);
    private:
        Vector2 position;
        float rotation;
        Vector2 size;
        Vector2 velocity;
        SDL_Color color;
};