#include "GameObject.hpp"
#include "Game.hpp"
#include <cstdio>

void SDLgameObject::draw()
{
    TextureManager::instance().drawFrame(m_textureID, rect, m_currentRow, m_currentFrame, Game::instance().getRenderer());
}

SDLgameObject::SDLgameObject(const LoadParams* lParam)
    : rect { lParam->getRect() }
    , m_textureID { lParam->getID() }
{
    m_currentFrame = 1;
    m_currentRow   = 1;
}

LoadParams::LoadParams(SDL_Rect rect, std::string textureID)
    : rect { rect }
    , textureID { textureID }
{
}