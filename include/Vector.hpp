#ifndef VECTOR_H
#define VECTOR_H

struct Vector2d
{
public:
    Vector2d();
    Vector2d(int x, int y);
    ~Vector2d() {};
    int xPos;
    int yPos;
    int getX() const { return xPos; }
    int getY() const { return yPos; }
};

#endif