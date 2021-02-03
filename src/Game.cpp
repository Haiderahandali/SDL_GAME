#include "Game.hpp"
#include "SDL2/SDL.h"
#include "SDL2/SDL_error.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_render.h"
#include "SDL2/SDL_surface.h"
#include "SDL2/SDL_timer.h"
#include "SDL2/SDL_video.h"
#include <cstddef>
#include <cstdio>
#include <cstring>

//-----------------//
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

Game::Game()
{
}

Game::~Game()
{
}

//------------------Init SDL and Our Game Core ----------------------------//
// ------------------------------------------------------------------------//

bool Game::init()
{

    bool success = true;

    //Frame Init
    m_frameLocationX = m_frameWidth;
    m_frameLocationY = m_frameHeight;

    m_srcRect.w = m_desRect.w = m_frameLocationX;
    m_srcRect.h = m_desRect.h = m_frameLocationY;

    printf("current frame between [%d , %d] \n", m_srcRect.x, m_srcRect.w);

    if (SDL_Init(SDL_INIT_VIDEO != 0))
    {
        printf("ERROR COULDN'T Init SDL: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        g_Window = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (g_Window == NULL)
        {
            printf("ERORR Could not create window%s \n", SDL_GetError());
            success = false;
        }
        else
        {
            g_Renderer = SDL_CreateRenderer(g_Window, -1, 0);
            if (!loadMedia())
            {
                printf("ERROR MeDIA WAS NOT LOADED\n");
                success = false;
            }
        }
    }
    return success;
}

//------------------Load the Surface and return it ------------------------//
// ------------------------------------------------------------------------//

SDL_Surface* Game::loadSurface(std::string const& path)
{

    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
        printf("Error loading sufrace%s \n", SDL_GetError());

    return loadedSurface;
}

// ----------------------------------------------------------------------//
//------------------Loading Files from PC to SDL ------------------------//

bool Game::loadMedia()
{
    bool load = true;
    g_Surface = loadSurface("../../res/Run.png");
    if (g_Surface == NULL)
    {
        printf("Error couldn't load Surface\n");
        load = false;
    }

    g_Texture = SDL_CreateTextureFromSurface(g_Renderer, g_Surface);
    if (g_Texture == NULL)
    {
        load = false;
        printf("Could not Load texture from surface %s\n", SDL_GetError());
    }

    //freeing the Surface as we created a texture and no longer need it
    SDL_FreeSurface(g_Surface);
    g_Surface = NULL;
    return load;
}

void Game::render()
{

    SDL_SetRenderDrawColor(g_Renderer, 0XFF, 0XFF, 0XFF, 0XFF);

    SDL_RenderClear(g_Renderer);

    SDL_RenderCopy(g_Renderer, g_Texture, &m_srcRect, &m_desRect);
    //SDL_RenderCopyEx(g_Renderer, g_Texture, &m_srcRect, &m_desRect, 0, 0, SDL_FLIP_HORIZONTAL);

    SDL_RenderPresent(g_Renderer);
}

void Game::clean()
{
    // The order is important, it is the reverse order of creation
    SDL_DestroyTexture(g_Texture);
    SDL_DestroyRenderer(g_Renderer);
    SDL_DestroyWindow(g_Window);

    g_Window   = NULL;
    g_Renderer = NULL;
    g_Texture  = NULL;

    if (strcmp(SDL_GetError(), ""))
        printf("Error before quiting %s\n", SDL_GetError());
    SDL_Quit();
}

void Game::update()
{
    m_frameLocationX = m_frameWidth * int((SDL_GetTicks() / 96) % 6);
    m_srcRect.x      = m_frameLocationX;
}
