#include "Game.hpp"
#include "SDL2/SDL_events.h"
#include "SDL2/SDL_keyboard.h"

int main(int argc, char const* argv[])
{
    //----------------- USE LEO SUGGESTION LATER FOR STRING_VIEWS ----------------//
    //----------------------------------------------------------//

    auto& game = Game::instance();

    if (!game.init())
    {
        printf("ERROR Init %s%d\n", argv[1], argc);
        return -1;
    }

    //--------------------------------------BEGIN GAME LOOP-------------------------------------//
    //--------------------------------------BEGIN GAME LOOP ------------------------------------//

    while (game.isRunning())
    {

        game.render();
        game.update();
        game.handleEvents();
        SDL_Delay(10);
    }

    //-----------------------------------------END OF GAME LOOP ---------------------------------------//
    //-----------------------------------------END OF GAME LOOP ---------------------------------------//

    //--------------- Clean UP RESOURCES -------------------//
    //--------------- Clean UP RESOURCES -------------------//

    game.clean();

    return 0;
}