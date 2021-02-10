#pragma once
#include "GameStates.hpp"
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
};
