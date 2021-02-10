#include "MenuState.hpp"

const std::string MenuState::m_MenuID = "Main Menu";

void MenuState::update()
{
}

void MenuState::render()
{
}

bool MenuState::onExit()
{
    printf("Main Menu was Was Exited \n");
    return true;
}

bool MenuState::onEnter()
{
    printf("Main Menu was Initliasised \n");
    return true;
}