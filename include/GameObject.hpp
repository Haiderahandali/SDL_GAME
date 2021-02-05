#include "TextureManager.hpp"
#include "Vector.hpp"
#include "Vendors.hpp"

#ifndef GMAE_OBJECT_H
#define GMAE_OBJECT_H

//--------------------- LOAD PARAMETERS CLASS ----------------//
class LoadParams final
{
public:
    LoadParams(SDL_Rect rect, std::string textureID);

    ~LoadParams();
    std::string getID() const { return textureID; }
    SDL_Rect getRect() const { return rect; }
    int getX() const { return rect.x; }
    int getY() const { return rect.y; }
    int getFrameWidth() const { return rect.w; }
    int getFrameHeight() const { return rect.h; }

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
    Vector2d position;

    std::string m_textureID;
    int frameWidth;
    int frameHeight;
    int m_currentFrame;
    int m_currentRow;
};

#endif
