#pragma once

#include "../Utils/Vector2.hpp"

class Entity {
    public:
        void render();
        void update(Vector2 transformPos, float transformRot);
    private:
        Vector2 position;
        Vector2 velocity;
        Vector2 acceleration;
};