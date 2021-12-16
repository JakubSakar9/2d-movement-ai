#include <cmath>
#include <stdio.h>

#include "Entity.hpp"
#include "Params.hpp"

Entity::Entity(Vector2 origin, Vector2 _size, SDL_Color _color)
    : position{origin}, size{_size}, color{_color} {}

void Entity::Render(SDL_Renderer *renderer) {
    //Init rectangle
    SDL_Rect entityRect;
    entityRect.x = floor(position.x);
    entityRect.y = floor(position.y);
    entityRect.w = floor(size.x);
    entityRect.h = floor(size.y);

    //Render rectangle
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
    SDL_RenderDrawRect(renderer, &entityRect);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
}

void Entity::Update(Vector2 newVel) {
    velocity = newVel;
    fprintf(stderr, "(%f, %f)\n", position.x, position.y);
    position = position + velocity * TIME_UNIT;
}