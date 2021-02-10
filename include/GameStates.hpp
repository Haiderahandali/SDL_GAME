#include <string>

class GameStates
{
public:
    virtual void render()             = 0;
    virtual void update()             = 0;
    virtual void onExit()             = 0;
    virtual void onEnter()            = 0;
    virtual std::string getID() const = 0;
};