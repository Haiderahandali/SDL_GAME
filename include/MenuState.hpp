#include "GameStates.hpp"
class MenuState : public GameStates
{
public:
    void update() override;
    void onEnter() override;
    void onExit() override;
    void render() override;

    inline virtual std::string getID() const override
    {
        return m_MenuID;
    }

private:
    static const std::string m_MenuID;
};

const std::string MenuState::m_MenuID = "Main Menu";