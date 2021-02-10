#include "MenuState.hpp"
#include "Game.hpp"
#include "GameObject.hpp"
#include "MenuButton.hpp"
#include <cstdio>
#include <memory>

const std::string MenuState::m_MenuID = "Main Menu";

bool MenuState::onEnter()
{
    printf("Entering the Menu State \n");
    if (!TextureManager::instance().load("/Users/aliabdulkareem/dev/Game/res/NewGameButton.png", "Menu", Game::instance().getRenderer()))
        return false;
    else
    {
        auto temp                        = std::make_unique<LoadParams>(SDL_Rect { 200, 200, 180, 200 }, "Menu");
        std::unique_ptr<GameObject> menu = std::make_unique<MenuButton>(temp.get());
        m_gameObjects.push_back(std::move(menu));
        return true;
    }
}
void MenuState::update()
{
    for (auto& x : m_gameObjects)
        x->update();
}

void MenuState::render()
{
    for (auto& x : m_gameObjects)
        x->draw();
}

bool MenuState::onExit()
{
    printf("Exiting the Menu State\n");
    return true;
}
