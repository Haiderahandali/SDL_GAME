#include "MenuState.hpp"
#include "Game.hpp"
#include "GameObject.hpp"
#include "GameStates.hpp"
#include "InputHandler.hpp"
#include "MenuButton.hpp"
#include "PlayState.hpp"
#include <sys/_types/_size_t.h>

const std::string MenuState::m_MenuID = "Main Menu";

bool MenuState::onEnter()
{
    printf("Entering the Menu State \n");
    if (!TextureManager::instance().load("../../res/TestButton.png", "TestButton", Game::instance().getRenderer()))
    {
        return false;
    }
    if (!TextureManager::instance().load("../../res/QuitButton.jpg", "QuitButton", Game::instance().getRenderer()))
    {
        printf("ERROR............\n");
        return false;
    }

    else
    {
        auto test_temp = std::make_unique<LoadParams>(SDL_Rect { 0, 0, 180, 150 }, "TestButton");
        auto quit_temp = std::make_unique<LoadParams>(SDL_Rect { 300, 300, 340, 100 }, "QuitButton");

        std::unique_ptr<GameObject> testButton = std::make_unique<MenuButton>(test_temp.get(), &s_menuToPlay);
        std::unique_ptr<GameObject> quitButton = std::make_unique<MenuButton>(quit_temp.get(), &s_exitFromMenu);

        m_menuObject.push_back(std::move(quitButton));
        m_menuObject.push_back(std::move(testButton));

        return true;
    }
}
void MenuState::update()
{

    for (auto& x : m_menuObject)
        x->update();
}

void MenuState::render()
{
    for (auto& x : m_menuObject)
        x->draw();
}

bool MenuState::onExit()
{
    printf("Exiting the Menu State\n");
    return true;
}

void MenuState::s_menuToPlay()
{
    printf(" button was clicked %d times\n", ++MenuState::number_of_clicks);
    auto& tempStateMachine = Game::instance().getStateMachineRef();
    tempStateMachine->changeState(std::make_unique<PlayState>());
}
void MenuState::s_exitFromMenu()
{
    printf("Exit Button was Clicked\n");
}
int MenuState::number_of_clicks { 0 };
