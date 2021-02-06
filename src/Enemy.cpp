#include "Enemy.hpp"
Enemy::Enemy(const LoadParams* lParam)
    : SDLgameObject(lParam)
{
}
void Enemy::update()
{
    m_acceleration.xPos = 0.2;
    m_currentFrame      = int(((SDL_GetTicks() / 100) % 6));
    SDLgameObject::update();
}