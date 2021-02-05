#include "Player.hpp"

Player::Player(const LoadParams* lParam)
    : SDLgameObject(lParam)
{
    m_currentFrame = 5;
}

void Player::update()
{
    position.xPos -= 1;
}