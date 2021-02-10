#pragma once
#include "Vector.hpp"
#include "Vendors.hpp"
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
    void update();

    bool onKeyDown(SDL_Scancode key);
    bool onKeyUp(SDL_Scancode key);
    inline Vector2d const& getMousePosition() const { return m_mousePosition; }
    std::vector<bool> m_mouseButtonStates;

private:
    // private functions to handle different event types
    // handle keyboard events

    // handle mouse events
    void onMouseMove(SDL_Event& event);
    void onMouseButtonDown(SDL_Event& event);
    void onMouseButtonUp(SDL_Event& event);

    inline bool getMouseButtonState(int buttonNumber)
    {
        return m_mouseButtonStates[buttonNumber];
    }

    Uint8 const* m_keystates;

private:
    Vector2d m_mousePosition;

    InputHandler();
    ~InputHandler();
};