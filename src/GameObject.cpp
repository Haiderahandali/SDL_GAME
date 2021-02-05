#include "GameObject.hpp"
#include "Game.hpp"

void SDLgameObject::draw()
{
    TextureManager::instance().drawFrame(m_textureID, { static_cast<int>(position.xPos), static_cast<int>(position.yPos), frameWidth, frameHeight }, m_currentRow, m_currentFrame, Game::instance().getRenderer());
    if (strcmp(SDL_GetError(), ""))
        printf("Error before update %s\n", SDL_GetError());
}

SDLgameObject::SDLgameObject(const LoadParams* lParam)

{
    position.xPos = lParam->getX();
    position.yPos = lParam->getY();
    frameWidth    = lParam->getFrameWidth();
    frameHeight   = lParam->getFrameHeight();

    m_currentFrame = 1;
    m_currentRow   = 1;
}

LoadParams::LoadParams(SDL_Rect rect, std::string textureID)
    : rect { rect }
    , textureID { textureID }
{
}