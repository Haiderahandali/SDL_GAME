#include "Enemy.hpp"
void Enemy::update()
{
    m_SDLRect.x += 1;
    m_SDLRect.y += 1;
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}