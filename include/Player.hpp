#include "GameObject.hpp"
#include <string>
#ifndef PLAYER_H
#define PLAYER_H
class Player final : public SDLgameObject
{

public:
    Player(const LoadParams* lParam);
    virtual void update() override;
};

#endif