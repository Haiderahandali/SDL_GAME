#include "Player.hpp"

void Player::load(SDL_Rect Rect, std::string textureID)
{
    GameObject::load(Rect, textureID);
    m_currentFrame = 3;
}

void Player::update()
{
    m_SDLRect.x -= 1;
}