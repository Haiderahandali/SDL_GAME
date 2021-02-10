#include "MenuState.hpp"
#include <cstdio>

const std::string MenuState::m_MenuID = "Main Menu";

bool MenuState::onEnter()
{
    printf("Entering the Menu State \n");
    return true;
}
void MenuState::update()
{
}

void MenuState::render()
{
}

bool MenuState::onExit()
{
    printf("Exiting the Menu State\n");
    return true;
}
