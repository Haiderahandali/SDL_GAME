#pragma once
#include "GameStates.hpp"
#include <memory>
#include <vector>
class GameStateMachine
{
public:
    GameStateMachine() {};
    ~GameStateMachine() {};

    void pushState(GameStates* State);
    void changeState(GameStates* State);
    void popState();

private:
    std::vector<GameStates*> m_gameStates;
};