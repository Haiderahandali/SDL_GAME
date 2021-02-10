#include "PlayState.hpp"
#include <cstdio>

void PlayState::update()
{
}
void PlayState::render()
{
}
bool PlayState::onEnter()
{
    printf("Entering Play State \n");
    return true;
}
bool PlayState::onExit()
{
    printf("exiting Play State");
    return true;
}