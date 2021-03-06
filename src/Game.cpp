#include "Game.hpp"
#include "GameStateMachine.hpp"
#include "InputHandler.hpp"
#include "MenuButton.hpp"
#include "MenuState.hpp"
#include "PlayState.hpp"
#include "Vendors.hpp"
#include <memory>

//-----------------//
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

Game::Game()
{

    //----------------------------- TEXTURE MANAGER CREATION -------------------//
    //------------Without initialising it, the map will be not created, giving seg. fault ---//

    //texture_manager = TextureManager::instace();
}

Game::~Game()
{
}

//----------------------------- TEXTURE MANAGER CREATION -------------------//

//------------------Init SDL and Our Game Core ----------------------------//
// ------------------------------------------------------------------------//

bool Game::init()
{

    bool success = true;

    // auto loadP = std::make_unique<LoadParams>(SDL_Rect { 300, 300, 82, 100 }, "Run");
    // auto loadE = std::make_unique<LoadParams>(SDL_Rect { 0, 0, 82, 100 }, "Run");

    // m_enemy = std::make_unique<Enemy>(loadE.get());

    //gObjects.emplace_back(std::move(m_player));

    //Frame Init
    // m_frameLocationX = m_frameWidth;
    // m_frameLocationY = m_frameHeight;

    // m_srcRect.w = m_desRect.w = m_frameLocationX;
    // m_srcRect.h = m_desRect.h = m_frameLocationY;

    if (SDL_Init(SDL_INIT_VIDEO != 0))
    {
        printf("ERROR COULDN'T Init SDL: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        g_Window = SDL_CreateWindow("My 2D Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (g_Window == NULL)
        {
            printf("ERORR Could not create window%s \n", SDL_GetError());
            success = false;
        }
        else
        {
            g_Renderer = SDL_CreateRenderer(g_Window, -1, 0);
            // if (!TextureManager::instance().load("../../res/Run.png", "Run", g_Renderer))
            // {
            //     printf("ERROR texture_manager failed to load image\n");
            //     success = false;
            // }
        }
    }

    m_GameStateMachine = std::make_unique<GameStateMachine>();
    m_GameStateMachine->changeState(std::make_unique<PlayState>());
    return success;
}

//------------------Load the Surface and return it ------------------------//
// ------------------------------------------------------------------------//

// SDL_Surface* Game::loadSurface(std::string const& path)
// {

//     SDL_Surface* loadedSurface = IMG_Load(path.c_str());
//     if (loadedSurface == NULL)
//         printf("Error loading sufrace%s \n", SDL_GetError());

//     return loadedSurface;
// }

// ----------------------------------------------------------------------//
//------------------Loading Files from PC to SDL ------------------------//

// bool Game::loadMedia()
// {
//     bool load = true;
//     g_Surface = loadSurface("../../res/Run.png");
//     if (g_Surface == NULL)
//     {
//         printf("Error couldn't load Surface\n");
//         load = false;
//     }

//     g_Texture = SDL_CreateTextureFromSurface(g_Renderer, g_Surface);
//     if (g_Texture == NULL)
//     {
//         load = false;
//         printf("Could not Load texture from surface %s\n", SDL_GetError());
//     }

//     //freeing the Surface as we created a texture and no longer need it
//     SDL_FreeSurface(g_Surface);
//     g_Surface = NULL;
//     return load;
// }

void Game::render()
{

    SDL_SetRenderDrawColor(g_Renderer, 0X00, 0X00, 0X00, 0XFF);
    SDL_RenderClear(g_Renderer);

    //   TextureManager::instance().drawFrame("Run", { 0, 120, m_frameWidth, m_frameHeight }, 1, m_currentFrame, g_Renderer);
    // TextureManager::instance().draw("Run", { 0, 0, m_frameWidth * 6, m_frameHeight }, g_Renderer);

    // for (auto& g : gObjects)
    // {

    //     g->draw();
    // }
    m_GameStateMachine->render();

    //SDL_RenderCopyEx(g_Renderer, g_Texture, &m_srcRect, &m_desRect, 0, 0, SDL_FLIP_HORIZONTAL);

    SDL_RenderPresent(g_Renderer);
}

void Game::clean()
{
    // The order is important, it is the reverse order of creation

    //SDL_DestroyTexture(g_Texture);
    TextureManager::instance().textureClean();
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
    //m_currentFrame = int((SDL_GetTicks() / 100) % 6);
    m_GameStateMachine->update();
}
void Game::handleEvents()
{
    InputHandler::instance().update();

    if (InputHandler::instance().onKeyDown(SDL_SCANCODE_RETURN))
    {
        m_GameStateMachine->changeState(std::make_unique<MenuState>());
    }
    if (InputHandler::instance().onKeyDown(SDL_SCANCODE_RSHIFT))
    {
        m_GameStateMachine->changeState(std::make_unique<PlayState>());
    }
}

/*instance







*/