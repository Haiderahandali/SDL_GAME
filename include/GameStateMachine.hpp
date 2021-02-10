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
    std::vector<std::unique_ptr<GameStates>> m_gameStates;
};