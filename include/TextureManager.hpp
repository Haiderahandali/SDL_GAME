#include "SDL2/SDL_rect.h"
#include "SDL2/SDL_render.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <map>
#include <string>

#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H
class TextureManager
{
private:
    std::map<std::string, SDL_Texture*> m_textureMap;

    TextureManager();

public:
    //--------------- Creating the static instance ----------------//

    static TextureManager& instance()
    {
        static TextureManager singleton;

        return singleton;

    }

    //--------- Deleting the consturctor and the assignment operator to make it a singleton ---------//
    TextureManager(const TextureManager&) = delete;
    TextureManager operator=(const TextureManager&) = delete;
    //-----------------------------------------------------------------------------------------------//

    ~TextureManager();

    void draw(std::string textureID, SDL_Rect pos, SDL_Renderer* g_Renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    void drawFrame(std::string textureID, SDL_Rect pos, int currentRow, int currentFrame, SDL_Renderer* g_Renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    bool load(std::string imagePath, std::string imageID, SDL_Renderer* g_Renderer);

    void textureClean();
};

#endif