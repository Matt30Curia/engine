#include "Vector2.h"
#include <iostream>



bool Vector2D::operator==(Vector2D point)
{
    return point.x == x && point.y == y;
}



Vector2D Vector2D::operator+=(float n)
{
    return Vector2D(x + n, y + n);
}

void Vector2D::operator+=(Vector2D point)
{
    x += point.x;
    y += point.y;
}
/*
Vector2D Vector2D::operator-=(float n)
{
    return Vector2D();
}

Vector2D Vector2D::operator-=(Vector2D point)
{
    return Vector2D();
}

Vector2D Vector2D::operator/=(float n)
{
    return Vector2D();
}

Vector2D Vector2D::operator/=(Vector2D point)
{
    return Vector2D();
}*/

Vector2D Vector2D::operator*(float n)
{
    return Vector2D(x * n, y * n);
}

Vector2D Vector2D::operator*(Vector2D point)
{
    return Vector2D(x * point.x, y * point.y);
}

Vector2D Vector2D::operator+(float n)
{
    return Vector2D(x + n, y + n);
}

Vector2D Vector2D::operator+(Vector2D point)
{
    return Vector2D(x + point.x, y + point.y);
}

Vector2D Vector2D::operator-(float n)
{
    return Vector2D(x - n, y - n);
}

Vector2D Vector2D::operator-(Vector2D point)
{
    return Vector2D(x - point.x, y - point.y);
}

Vector2D Vector2D::operator/(float n)
{
    return Vector2D(x / n, y / n);
}

Vector2D Vector2D::operator/(Vector2D point)
{
    return Vector2D(x / point.x, y / point.y);
}

Vector2D Vector2D::rotate(float angle)
{
    rotation = angle;
    return Vector2D(std::cos(angle * RAD), std::sin(angle * RAD));
}

Vector2 Vector2D::toVector2()
{
    return Vector2(x,y);
}


