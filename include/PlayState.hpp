#pragma once
#include "GameObject.hpp"
#include "GameStates.hpp"
#include <string_view>

class PlayState : public GameStates
{
public:
    virtual ~PlayState() { }
    virtual void update() override;
    virtual void render() override;
    virtual bool onEnter() override;
    virtual bool onExit() override;
    virtual std::string_view getStateID() const override { return m_PlayStateID; }

private:
    static constexpr inline std::string_view m_PlayStateID = "Play State ID";
    std::vector<std::unique_ptr<GameObject>> m_gameObjects;
};