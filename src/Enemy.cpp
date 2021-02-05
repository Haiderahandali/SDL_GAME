#include "Enemy.hpp"
#include <memory>
Enemy::Enemy(const LoadParams* lParam)
    : SDLgameObject(lParam)
{
}
void Enemy::update()
{
    position.xPos += 1;
    position.yPos += 1;
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}