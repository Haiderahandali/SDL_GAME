#pragma once
enum button_state
{
    MOUSE_OUT     = 0,
    MOUSE_ON      = 1,
    MOUSE_CLICKED = 2
};
#include "GameObject.hpp"

class MenuButton : public SDLgameObject
{
public:
    virtual ~MenuButton() { }
    MenuButton(const LoadParams* lparam);
    virtual void draw() override;
    virtual void update() override;
};