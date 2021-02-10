#include "GameStates.hpp"
class MenuState : public GameStates
{
public:
    void update() override;
    void onEnter() override;
    void onExit() override;
    void render() override;

    virtual std::string getMenuID() const override
    {
        return m_MenuID;
    }

private:
    static const std::string m_MenuID;
};
