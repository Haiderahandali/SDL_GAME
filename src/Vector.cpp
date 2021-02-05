#include "Vector.hpp"

Vector2d::Vector2d(int x, int y)
    : xPos { x }
    , yPos { y }
{
}

Vector2d::Vector2d()
{
    xPos = 0;
    yPos = 0;
}
Vector2d operator+(Vector2d const& vec2d, Vector2d const& other)
{
    return { vec2d.xPos + other.xPos, vec2d.yPos + other.yPos };
}

Vector2d operator-(Vector2d const& vec2d, Vector2d const& other)
{
    return { vec2d.xPos - other.xPos, vec2d.yPos - other.yPos };
}

Vector2d operator-(Vector2d const& vec2d, int other)
{
    return { vec2d.xPos - other, vec2d.yPos - other };
}

Vector2d operator+(Vector2d const& vec2d, int other)
{
    return { vec2d.xPos + other, vec2d.yPos + other };
}