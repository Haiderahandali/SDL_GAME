#pragma once
#include <stdio.h>
#include <string>
#include <string_view>

class GameStates
{
public:
    virtual ~GameStates() { }
    virtual void render()                       = 0;
    virtual void update()                       = 0;
    virtual bool onExit()                       = 0;
    virtual bool onEnter()                      = 0;
    virtual std::string_view getStateID() const = 0;
};