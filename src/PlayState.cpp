#include "PlayState.hpp"
#include "Enemy.hpp"
#include "Game.hpp"
#include <cstdio>

void PlayState::update()
{
    for (auto& x : m_gameObjects)
        x->update();
}
void PlayState::render()
{
    for (auto& x : m_gameObjects)
        x->draw();
}
bool PlayState::onEnter()
{
    printf("Entering Play State \n");

    if (!TextureManager::instance().load("../../res/Run.png", "Run", Game::instance().getRenderer()))
        return false;
    else
    {
        auto loadE = std::make_unique<LoadParams>(SDL_Rect { 0, 0, 82, 100 }, "Run");
        m_gameObjects.push_back(std::make_unique<Enemy>(loadE.get()));
        return true;
    }
}
bool PlayState::onExit()
{
    printf("Exiting Play State \n");
    return true;
}