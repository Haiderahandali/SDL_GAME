#include "Player.hpp"

Player::Player(const LoadParams* lParam)
    : SDLgameObject(lParam)
{
    m_currentFrame = 5;
}

void Player::update()
{
    rect.x -= 1;
}