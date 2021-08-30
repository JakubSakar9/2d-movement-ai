#include <SDL2/SDL.h>

#include "Core/Engine.hpp"
 
int main(int argc, char ** argv) {
    Engine::GetInstance()->Init();

    while(Engine::GetInstance()->IsRunning()){
        //Main program loop
        Engine::GetInstance()->Events();
        Engine::GetInstance()->Update();
        Engine::GetInstance()->Render();
    }

    Engine::GetInstance()->Clean();
 
    return 0;
}