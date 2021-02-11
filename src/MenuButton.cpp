#include "MenuButton.hpp"
#include "GameObject.hpp"
#include "InputHandler.hpp"

MenuButton::MenuButton(const LoadParams* lparam, void (*callback)())
    : SDLgameObject(lparam)
    , m_callback(callback)
{
    m_currentFrame = MOUSE_OUT;
}
void MenuButton::draw()
{
    SDLgameObject::draw();
}

void MenuButton::update()
{
    //get mouse position inside a frame
    Vector2d mousePosition = InputHandler::instance().getMousePosition();
    if (mousePosition.getX() > position.getX()
        && mousePosition.getX() < mousePosition.getX() + frameWidth
        && mousePosition.getY() > position.getY()
        && mousePosition.getY() < position.getY() + frameHeight)
    {
        m_currentFrame = MOUSE_ON;
        if (InputHandler::instance().m_mouseButtonStates[LEFT])
        {
            m_currentFrame = MOUSE_CLICKED;
            if (m_buttonReleased)
                m_callback();
            m_buttonReleased = false;
        }
        else
        {
            m_buttonReleased = true;
            m_currentFrame   = MOUSE_ON;
        }
    }

    else
    {
        m_currentFrame = MOUSE_OUT;
    }
}
