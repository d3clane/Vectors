#include <cassert>
#include <cmath>

#include "Vector.hpp"

namespace Scene
{

namespace
{

double getLength(double dx, double dy);
double getAngle (double dx, double dy);

double getLength(double dx, double dy)
{
    assert(std::isfinite(dx));
    assert(std::isfinite(dy));

    return sqrt(dx * dx + dy * dy);
}

double getAngle (double dx, double dy)
{
    assert(std::isfinite(dx));
    assert(std::isfinite(dy));
    assert(dx != 0);

    return atan2(dy, dx);
}

}

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
    return (int)(length_ * std::cos(angle_));
}

int Vector::getDy() const
{
    return (int)(length_ * std::sin(angle_));
}

Vector Vector::operator + (const Vector& other) const
{
    double dx = getDx() + other.getDx();
    double dy = getDy() + other.getDy();

    return Vector(getAngle(dx, dy), getLength(dx, dy));
}

Vector Vector::operator - (const Vector& other) const
{
    double dx = getDx() - other.getDx();
    double dy = getDy() - other.getDy();

    return Vector(getAngle(dx, dy), getLength(dx, dy));
}

Vector Vector::operator * (const double coeff)  const
{
    assert(std::isfinite(coeff));

    return Vector(angle_, length_ * coeff);
}

Vector Vector::operator / (const double coeff)  const
{
    assert(std::isfinite(coeff));
    assert(coeff != 0);

    return Vector(angle_, length_ / coeff);
}

double Vector::operator ^ (const Vector& other) const   
{
    return length_ * other.length_ * std::cos(angle_ - other.angle_);
}

} // Scene