#include "GameStateMachine.hpp"

void GameStateMachine::changeState(std::unique_ptr<GameStates> State)
{
    if (!m_gameStates.empty())

    {

        if (!(m_gameStates.back()->getStateID() == State->getStateID()))
        {

            if (m_gameStates.back()->onExit())
                m_gameStates.pop_back();
        }
        else
            printf("it is the same state\n");
    }
    else
    {
        m_gameStates.emplace_back(std::move(State));
        m_gameStates.back()->onEnter();
    }
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