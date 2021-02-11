#pragma once
#include "GameObject.hpp"
#include "GameStates.hpp"
#include <memory>
#include <string_view>
class MenuState : public GameStates
{
public:
    virtual ~MenuState() { }
    void update() override;

    void render() override;
    bool onEnter() override;
    bool onExit() override;

    virtual std::string_view getStateID() const override
    {
        return m_MenuID;
    }

private:
    static const std::string m_MenuID;
    std::vector<std::unique_ptr<GameObject>> m_gameObjects;

    static void s_menuToPlay();
    static void s_exitFromMenu();
    static int number_of_clicks;
};
