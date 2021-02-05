#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <math.h>

struct Vector2d
{
public:
    Vector2d();
    Vector2d(float x, float y);
    ~Vector2d() {};
    float xPos;
    float yPos;

    //--------------------- function here -----------------//

    float dot(Vector2d other) const;
    float length() const;
    float getX() const { return xPos; }
    float getY() const { return yPos; }
    void normalize();

    //-------------overloading --------------//
    Vector2d&
    operator=(Vector2d&)
        = default;
    friend std::ostream& operator<<(std::ostream& os, Vector2d const& vec);
};

#endif