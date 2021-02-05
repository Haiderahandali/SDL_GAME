#include "GameObject.hpp"
#include <string>
#ifndef PLAYER_H
#define PLAYER_H
class Player final : public GameObject
{

public:
    virtual void load(SDL_Rect Rect, std::string textureID) override;
    virtual void update() override;
};

#endif