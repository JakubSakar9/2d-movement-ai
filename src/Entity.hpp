#pragma once

#include "SDL2/SDL.h"

#include "Vector2.hpp"

class Entity {
    public:
        Entity(Vector2 origin, Vector2 _size, SDL_Color _color);
        void Render(SDL_Renderer *renderer);
        void Update(Vector2 transformPos, double transformRot);
    private:
        Vector2 position;
        double rotation;
        Vector2 size;
        Vector2 velocity;
        Vector2 acceleration;
        SDL_Color color;
};