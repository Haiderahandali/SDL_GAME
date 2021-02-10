#include "MenuButton.hpp"
#include "GameObject.hpp"
#include "InputHandler.hpp"

MenuButton::MenuButton(const LoadParams* lparam)
    : SDLgameObject(lparam)
{
    m_currentFrame = MOUSE_OUT;
    frameWidth     = 180;
    frameHeight    = 200;
}
void MenuButton::draw()
{
    SDLgameObject::draw();
}

void MenuButton::update()
{
    //get mouse position inside a frame
    Vector2d mousePosition = InputHandler::instance().getMousePosition();
    if (mousePosition.getX() > position.getX() && mousePosition.getX() < mousePosition.getX() + frameWidth
        && mousePosition.getY() > position.getY() && mousePosition.getY() < position.getY() + frameHeight)
    {
        m_currentFrame = MOUSE_ON;
        if (InputHandler::instance().m_mouseButtonStates[LEFT])
            m_currentFrame = MOUSE_CLICKED;
    }
    else
    {
        m_currentFrame = MOUSE_OUT;
    }
}