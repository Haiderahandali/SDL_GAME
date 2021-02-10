#include <string>

class GameStates
{
public:
    virtual ~GameStates() { }
    virtual void render()                 = 0;
    virtual void update()                 = 0;
    virtual void onExit()                 = 0;
    virtual void onEnter()                = 0;
    virtual std::string getMenuID() const = 0;
};