#include "GameStateMachine.hpp"

void GameStateMachine::changeState(std::unique_ptr<GameStates> State)
{
    if (!m_gameStates.empty())

    {

        if (m_gameStates.back()->getStateID() == State->getStateID())
        {
            printf("it is the same state\n");
            return;
        }
        else
        {
            if (m_gameStates.back()->onExit())
                m_gameStates.pop_back();
        }
    }

    m_gameStates.push_back(std::move(State));
    m_gameStates.back()->onEnter();
}

void GameStateMachine::popState()
{
    if (!m_gameStates.empty())
    {
        m_gameStates.back()->onExit();
        m_gameStates.pop_back();
    }
}
void GameStateMachine::pushState(std::unique_ptr<GameStates> State)
{
    m_gameStates.emplace_back(std::move(State));
    m_gameStates.back()->onEnter();
}

void GameStateMachine::update()
{
    if (!m_gameStates.empty())
        m_gameStates.back()->update();
}
void GameStateMachine::render()
{
    if (!m_gameStates.empty())
        m_gameStates.back()->render();
}