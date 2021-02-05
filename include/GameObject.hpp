#include "SDL2/SDL_rect.h"
#include "SDL2/SDL_render.h"
#include "TextureManager.hpp"
#include <SDL2/SDL.h>
#include <string>
#ifndef GMAE_OBJECT_H
#define GMAE_OBJECT_H

class GameObject
{

    // Refactor later on to not use those things in the loop

public:
    GameObject();
    virtual void load(SDL_Rect Rect, std::string textureID);
    virtual void update();
    virtual void draw(SDL_Renderer* g_Renderer);
    virtual ~GameObject() = default;

protected:
    SDL_Rect m_SDLRect;
    int m_currentFrame;
    int m_currentRow;
    std::string m_textureID;
};

#endif
