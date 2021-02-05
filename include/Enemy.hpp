#include "GameObject.hpp"
#include "SDL2/SDL_rect.h"
#ifndef ENEMY_H
#define ENEMY_H
class Enemy final : public SDLgameObject
{
public:
    Enemy(const LoadParams* lParam);
    virtual void update() override;
};

#endif