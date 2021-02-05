#include "SDL2/SDL_error.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_rect.h"
#include "SDL2/SDL_render.h"
#include "SDL2/SDL_surface.h"
#include <TextureManager.hpp>
#include <cstdio>

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
}

bool TextureManager::load(std::string imagePath, std::string imageID, SDL_Renderer* g_Renderer)
{
    bool success = true;

    SDL_Surface* tempSurface = IMG_Load(imagePath.c_str());
    if (tempSurface == NULL)
    {
        printf("Error loading surface: %s\n", SDL_GetError());
        success = false;
        return success;
    }
    //-------------------------------------------------------------//
    SDL_Texture* texture = SDL_CreateTextureFromSurface(g_Renderer, tempSurface);
    if (texture == NULL)
    {
        printf("Error converting Surface to Texture: %s\n", SDL_GetError());
        success = false;
        return success;
    }

    //------------------------------------------------------------------//
    SDL_FreeSurface(tempSurface);
    m_textureMap[imageID] = texture;

    return success;
}

void TextureManager::draw(std::string textureID, SDL_Rect pos, SDL_Renderer* g_Renderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect desRect;

    srcRect.x = 0;
    srcRect.y = 0;

    srcRect.w = desRect.w = pos.w;
    srcRect.h = desRect.h = pos.h;

    desRect.x = pos.x;
    desRect.y = pos.y;

    SDL_RenderCopyEx(g_Renderer, m_textureMap[textureID], &srcRect, &desRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string textureID, SDL_Rect pos, int currentRow, int currentFrame, SDL_Renderer* g_Renderer, SDL_RendererFlip flip)
{

    SDL_Rect srcRect;
    SDL_Rect desRect;

    srcRect.w = desRect.w = pos.w;
    srcRect.h = desRect.h = pos.h;

    srcRect.x = pos.w * currentFrame;
    srcRect.y = pos.h * (currentRow - 1);

    desRect.x = pos.x;
    desRect.y = pos.y;

    SDL_RenderCopyEx(g_Renderer, m_textureMap[textureID], &srcRect, &desRect, 0, 0, flip);
}

void TextureManager::textureClean()
{
    for (auto& tex : m_textureMap)
    {
        SDL_DestroyTexture(tex.second);
        tex.second = NULL;
    }
}