#include <SDL2/SDL.h>
#include <cstdlib>
#include <vector>

#include "Entity.hpp"
#include "Vector2.hpp"

class EntityManager {
    public:
        inline EntityManager(int genSize)
            : generationSize{genSize}, currentGeneration(0), bestTime(0) {}
        void StartGeneration();
        void EndGeneration();

        //These two functions should be removed later, as multithreding will be implemented
        void RenderEntities(SDL_Renderer *renderer);
        void UpdateEntities();

        std::vector<Entity *> generation;
    private:
        int generationSize;
        int currentGeneration;
        float bestTime;
        SDL_Color RandColor();
};