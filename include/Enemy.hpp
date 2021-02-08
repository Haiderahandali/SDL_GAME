#ifndef ENEMY_H
#define ENEMY_H
#include "GameObject.hpp"

class Enemy final : public SDLgameObject
{
public:
    Enemy(const LoadParams* lParam);
    virtual void update() override;
    void inputHandler();

private:
    Vector2d vec; //delete later it is
    // just to test how the player should follow the mouse
};

#endif