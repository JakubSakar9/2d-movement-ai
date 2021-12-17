#include "EntityManager.hpp"

void EntityManager::StartGeneration() {
    Vector2 entityPosition = Vector2(400.0, 300.0);
    Vector2 entitySize = Vector2(20.0, 20.0);
    for(int i = 0; i < generationSize; i++) {
        Entity *en = new Entity(entityPosition, entitySize, RandColor());
        generation.emplace_back(en);
        //When multithreading is implemented, thread will zbe started here
    }
}

void EntityManager::EndGeneration() {
    //TBI
}

SDL_Color EntityManager::RandColor() {
    uint8_t r = 100 + ( std::rand() % ( 255 - 100 + 1 ));
    uint8_t g = 100 + ( std::rand() % ( 255 - 100 + 1 ));
    uint8_t b = 100 + ( std::rand() % ( 255 - 100 + 1 ));
    return {r, g, b};
}

void EntityManager::RenderEntities(SDL_Renderer *renderer) {
    for(int i = 0; i < generationSize; i++) {
        generation[i]->Render(renderer);
    }
}

void EntityManager::UpdateEntities() {
    for(int i = 0; i < generationSize; i++) {
        Vector2 velDiff = RandVector(2.0);
        generation[i]->Update(velDiff);
    }
}