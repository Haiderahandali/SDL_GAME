#include "InputHandler.hpp"
#include "Game.hpp"
#include "SDL2/SDL_events.h"

InputHandler::InputHandler()
{
    m_mouseButtonStates.reserve(3);
    for (int i = 0; i < 3; ++i)
        m_mouseButtonStates.emplace_back(false);
}

InputHandler::~InputHandler() { }

void InputHandler::update()
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        // -------- mouse event Hanlder ----------//

        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            if (e.button.button == SDL_BUTTON_LEFT)
                m_mouseButtonStates[LEFT] = true;

            if (e.button.button == SDL_BUTTON_MIDDLE)
                m_mouseButtonStates[MIDDLE] = true;
            if (e.button.button == SDL_BUTTON_RIGHT)
                m_mouseButtonStates[RIGHT] = true;
        }
        if (e.type == SDL_MOUSEBUTTONUP)
        {

            if (e.button.button == SDL_BUTTON_LEFT)
                m_mouseButtonStates[LEFT] = false;

            if (e.button.button == SDL_BUTTON_MIDDLE)
                m_mouseButtonStates[MIDDLE] = false;
            if (e.button.button == SDL_BUTTON_RIGHT)
                m_mouseButtonStates[RIGHT] = false;
        }
        if (e.type == SDL_MOUSEMOTION)
        {
            m_mousePosition.setX(e.motion.x);
            m_mousePosition.setY(e.motion.y);
        }

        if (e.type == SDL_QUIT)
        {
            Game::instance().quit();
        }

        /*















        */
    }
}