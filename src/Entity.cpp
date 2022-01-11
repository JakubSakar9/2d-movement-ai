#include <cmath>
#include <stdio.h>

#include "Entity.hpp"

Entity::Entity(Vector2 origin, Vector2 _size, SDL_Color _color)
    : position{origin}, size{_size}, color{_color} {}

void Entity::Render(SDL_Renderer *renderer) {
    //Init rectangle
    Vector2 e1 = Vector2(velocity.x, velocity.y);
    Vector2 e2 = Vector2(-velocity.y, velocity.x);
    Vector2 e1n = ((float) size.x * (1 / e1.Norm())) * e1;
    Vector2 e2n = ((float) size.y * (1 / e2.Norm())) * e2;
    Vector2 lt = Vector2(position.x, position.y);
    Vector2 rt = Vector2(position.x + e1n.x, position.y + e1n.y);
    Vector2 ld = Vector2(position.x + e2n.x, position.y + e2n.y);
    Vector2 rd = Vector2(position.x + e1n.x + e2n.x, position.y + e1n.y + e2n.y);

    //Render rectangle
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
    SDL_RenderDrawLine(renderer, lt.x, lt.y, rt.x, rt.y);
    SDL_RenderDrawLine(renderer, lt.x, lt.y, ld.x, ld.y);
    SDL_RenderDrawLine(renderer, rt.x, rt.y, rd.x, rd.y);
    SDL_RenderDrawLine(renderer, ld.x, ld.y, rd.x, rd.y);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
}

void Entity::Update(Vector2 velDiff) {
    velocity = velocity + velDiff;

    Vector2 unboundPosition = position + TIME_UNIT * velocity;
    if(unboundPosition.x < 0 || unboundPosition.x > SCREEN_WIDTH - size.x)
        velocity.x *= -1;
    
    if(unboundPosition.y < 0 || unboundPosition.y > SCREEN_HEIGHT - size.y)
        velocity.y *= -1;

    position = position + TIME_UNIT * velocity;
}