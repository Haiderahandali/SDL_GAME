#include "Enemy.hpp"
#include "InputHandler.hpp"
Enemy::Enemy(const LoadParams* lParam)
    : SDLgameObject(lParam)
{
}

void Enemy::inputHandler()
{
    // if (InputHandler::instance().getMouseButtonState(LEFT))
    //     m_acceleration.xPos += 0.2;
    vec       = InputHandler::instance().getMousePosition();
    m_volicty = ((vec - position) - frameWidth / 2.0) / 100;
}
void Enemy::update()
{

    m_volicty.setX(0);
    m_volicty.setY(0);

    inputHandler();
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
    SDLgameObject::update();
}