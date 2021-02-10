#pragma once
#include "GameStates.hpp"
#include <memory>
#include <vector>
class GameStateMachine
{
public:
    GameStateMachine() {};
    ~GameStateMachine() {

    };
    void update();
    void render();

    void pushState(std::unique_ptr<GameStates>);
    void changeState(std::unique_ptr<GameStates>);
    void popState();

private:
    std::vector<std::unique_ptr<GameStates>> m_gameStates;
};