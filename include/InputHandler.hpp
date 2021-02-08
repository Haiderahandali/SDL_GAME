#pragma once
#include "Vector.hpp"
#include <vector>

enum mouse_buttons
{
    LEFT   = 0,
    MIDDLE = 1,
    RIGHT  = 2
};
class InputHandler
{
public:
    static InputHandler& instance()
    {
        static InputHandler s_instance;
        return s_instance;
    }
    inline bool getMouseButtonState(int buttonNumber)
    {
        return m_mouseButtonStates[buttonNumber];
    }

    void update();
    inline Vector2d const& getMousePosition() const { return m_mousePosition; }

private:
    Vector2d m_mousePosition;
    std::vector<bool> m_mouseButtonStates;
    InputHandler();
    ~InputHandler();
};