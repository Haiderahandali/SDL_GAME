#include "Enemy.hpp"
#include <memory>
Enemy::Enemy(const LoadParams* lParam)
    : SDLgameObject(lParam)
{
}
void Enemy::update()
{
    rect.x += 1;
    rect.y += 1;
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}