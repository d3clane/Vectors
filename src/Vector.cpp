#include <math.h>

#include "Vector.hpp"

namespace Scene
{

void Vector::setAngle(double angle)
{
    angle_ = angle;
}

void Vector::rotate(double deltaAngle)
{
    angle_ += deltaAngle;
}

void Vector::setLength(double length)
{
    length_ = length;
}

void Vector::scale(double deltaLength)
{
    length_ += deltaLength;
}

int Vector::getDx() const
{
    return (int)(length_ * cos(angle_));
}

int Vector::getDy() const
{
    return (int)(length_ * sin(angle_));
}

} // Scene