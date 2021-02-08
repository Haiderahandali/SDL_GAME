#ifndef GAME_H
#define GAME_H
#include "Enemy.hpp"
#include "GameObject.hpp"
#include "InputHandler.hpp"
#include "Player.hpp"
#include "Vendors.hpp"
#include <TextureManager.hpp>

const int FPS = 120;

float const DELAY = 1000.0 / FPS;

class Game
{
public:
    ~Game();

    SDL_Surface* loadSurface(std::string const& path);
    static Game& instance()
    {
        static Game singleton;
        return singleton;
    }
    //---------------//
    bool init();
    bool loadMedia();
    bool isRunning()
    {
        return running;
    }

    //---------------//
    void render();
    void update();
    void handleEvents();
    void clean();

    SDL_Renderer* getRenderer() const
    {
        return g_Renderer;
    }
    void quit() { running = false; }

private:
    Game();

    std::unique_ptr<Player> m_player;
    std::unique_ptr<Enemy> m_enemy;

    std::vector<std::unique_ptr<GameObject>> gObjects;
    //------------------ SDL Window, Renderer, Surface and Texture -----------------------//
    SDL_Renderer* g_Renderer = NULL;
    SDL_Surface* g_Surface   = NULL;
    SDL_Texture* g_Texture   = NULL;
    SDL_Window* g_Window     = NULL;

    //----------- SDL-Rect-------//

    // SDL_Rect m_desRect { 0, 0, 0, 0 };
    // SDL_Rect m_srcRect { 0, 0, 0, 0 };

    const int m_frameWidth  = 82;
    const int m_frameHeight = 100;
    int m_currentFrame      = 0;

    //--------------------------------//
    bool running = true;
    // int m_frameLocationX = 0;
    // int m_frameLocationY = 0;
};
#endif
