#include "Enemy.hpp"
#include "InputHandler.hpp"
Enemy::Enemy(const LoadParams* lParam)
    : SDLgameObject(lParam)
{
}

void Enemy::inputHandler() { }
void Enemy::update()
{
    m_volicty.setX(0);
    m_volicty.setY(0);
    m_acceleration.xPos = 0.2;
    m_currentFrame      = int(((SDL_GetTicks() / 100) % 6));
    SDLgameObject::update();
}