#include "GameObject.hpp"
#include "Game.hpp"

void SDLgameObject::draw()
{
    TextureManager::instance().drawFrame(m_textureID, { static_cast<int>(position.xPos), static_cast<int>(position.yPos), frameWidth, frameHeight }, m_currentRow, m_currentFrame, Game::instance().getRenderer());
}

SDLgameObject::SDLgameObject(const LoadParams* lParam)

{
    position.xPos  = lParam->getX();
    position.yPos  = lParam->getY();
    frameWidth     = lParam->getFrameWidth();
    frameHeight    = lParam->getFrameHeight();
    m_textureID    = lParam->getID();
    m_currentFrame = 1;
    m_currentRow   = 1;
}

LoadParams::LoadParams(SDL_Rect rect, std::string textureID)
    : rect { rect }
    , textureID { textureID }
{
}