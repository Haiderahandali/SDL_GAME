#include "GameObject.hpp"
#include <cstdio>

GameObject::GameObject()
{
}
void GameObject::load(SDL_Rect rect, std::string textureID)
{

    m_SDLRect.x    = rect.x;
    m_SDLRect.y    = rect.y;
    m_SDLRect.w    = rect.w;
    m_SDLRect.h    = rect.h;
    m_textureID    = textureID;
    m_currentRow   = 1;
    m_currentFrame = 0;
}

void GameObject::draw(SDL_Renderer* g_Renderer)
{
    TextureManager::instance().drawFrame(m_textureID, m_SDLRect,
        m_currentRow, m_currentFrame, g_Renderer);
}

void GameObject::update()
{
    m_SDLRect.x += 1;
}