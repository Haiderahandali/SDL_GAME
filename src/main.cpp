#include "Game.hpp"
#include "SDL2/SDL_events.h"
#include "SDL2/SDL_keyboard.h"

int main(int argc, char const* argv[])
{

    Game* game = new Game;

    // -------------- Initialiasation of the Game -----------------//
    if (!game->init())
    {
        printf("ERROR Init %s%d\n", argv[1], argc);
        return -1;
    }

    //--------------------------------------BEGIN GAME LOOP-------------------------------------//
    //--------------------------------------BEGIN GAME LOOP ------------------------------------//

    bool quit = false;

    while (!quit)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            switch (e.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            default:
                break;
            }
        }
        game->render();
        game->update();
    }

    //-----------------------------------------END OF GAME LOOP ---------------------------------------//
    //-----------------------------------------END OF GAME LOOP ---------------------------------------//

    //--------------- Clean UP RESOURCES -------------------//
    //--------------- Clean UP RESOURCES -------------------//

    game->clean();

    return 0;
}