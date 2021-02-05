#include "SDL2/SDL_rect.h"
#include "SDL2/SDL_render.h"
#include "TextureManager.hpp"
#include <SDL2/SDL.h>
#include <memory>
#include <string>
#ifndef GMAE_OBJECT_H
#define GMAE_OBJECT_H

//--------------------- LOAD PARAMETERS CLASS ----------------//
class LoadParams final
{
public:
    LoadParams(SDL_Rect rect, std::string textureID);

    ~LoadParams() {};
    std::string getID() const { return textureID; }
    SDL_Rect getRect() const { return rect; }

private:
    SDL_Rect rect;
    std::string textureID;
};

//------------------------- GAME OBJECT CLASS -----------------//

class GameObject
{

    // Refactor later on to not use those things in the loop

public:
    virtual void update() = 0;
    virtual void draw()   = 0;
    virtual ~GameObject() {};

protected:
};

//------------- SDL_GAME_OBJECT------------------//
class SDLgameObject : public GameObject
{
public:
    SDLgameObject(const LoadParams* lparam);

    virtual void draw();
    virtual void update() { }

protected:
    SDL_Rect rect;
    std::string m_textureID;
    int m_currentFrame;
    int m_currentRow;
};

#endif
