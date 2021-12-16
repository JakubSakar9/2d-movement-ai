#pragma once

#ifdef __gnu_linux__
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#endif

#include <cstdlib>
#include <ctime>
#include <random>
#include <cstdio>

#include "Entity.hpp"
#include "Params.hpp"
#include "Vector2.hpp"

class Engine {
    public:
        static Engine *GetInstance(){
            return s_Instance = (s_Instance != nullptr) ? s_Instance : new Engine();
        }

        bool Init();
        bool Clean();
        void Quit();

        void Update();
        void Events();
        void Render();

        void RenderEntities();
        void UpdateEntities();
        void CreateEntities();

        inline bool IsRunning() {return m_IsRunning;}
        inline SDL_Renderer *GetRenderer() {return m_Renderer;}
    
    private:
        Engine() {}
        bool m_IsRunning;

        SDL_Window *m_Window;
        SDL_Renderer *m_Renderer;
        static Engine *s_Instance;

        Entity *en;
        Vector2 enVel;
};