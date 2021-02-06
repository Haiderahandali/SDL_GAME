#ifndef PLAYER_H
#define PLAYER_H
#include "GameObject.hpp"
#include <memory>
#include <string>

class Player final : public SDLgameObject
{

public:
    Player(const LoadParams* lParam);
    Player(const std::unique_ptr<LoadParams> lParam);

    virtual void update() override;
};

#endif