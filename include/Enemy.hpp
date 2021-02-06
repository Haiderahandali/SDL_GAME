#ifndef ENEMY_H
#define ENEMY_H
#include "GameObject.hpp"

class Enemy final : public SDLgameObject
{
public:
    Enemy(const LoadParams* lParam);
    virtual void update() override;
};

#endif