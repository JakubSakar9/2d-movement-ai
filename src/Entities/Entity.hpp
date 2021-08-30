#pragma once

#include "../Utils/Vector2.hpp"

class Entity {
    public:
        virtual void render();
    private:
        Vector2 position;
        Vector2 velocity;
        Vector2 acceleration;
};