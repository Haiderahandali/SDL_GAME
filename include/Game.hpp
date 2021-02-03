#include "SDL2/SDL_rect.h"
#include "SDL2/SDL_render.h"
#include "SDL2/SDL_surface.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstddef>
#include <stdio.h>
#include <string>
#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game();
    ~Game();

    SDL_Surface* loadSurface(std::string const& path);

    //---------------//
    bool init();
    bool loadMedia();

    //---------------//
    void render();
    void update();
    void handleEvents() { }
    void clean();

private:
    //------------------ SDL Window, Renderer, Surface and Texture -----------------------//
    SDL_Renderer* g_Renderer = NULL;
    SDL_Surface* g_Surface   = NULL;
    SDL_Texture* g_Texture   = NULL;
    SDL_Window* g_Window     = NULL;

    //----------- SDL-Rect-------//

    SDL_Rect m_desRect { 0, 0, 0, 0 };
    SDL_Rect m_srcRect { 0, 0, 0, 0 };

    const int m_frameWidth  = 82;
    const int m_frameHeight = 100;

    int m_frameLocationX = 0;
    int m_frameLocationY = 0;
};
#endif