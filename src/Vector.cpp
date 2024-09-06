#include <cassert>
#include <cmath>

#include "Vector.hpp"

namespace Scene
{

namespace
{

double calcLength(double dx, double dy);
double calcAngle (double dx, double dy);

double calcLength(double dx, double dy)
{
    assert(std::isfinite(dx));
    assert(std::isfinite(dy));

    return sqrt(dx * dx + dy * dy);
}

double calcAngle (double dx, double dy)
{
    assert(std::isfinite(dx));
    assert(std::isfinite(dy));

    return atan2(dy, dx);
}

} // anonymous namespace

Vector::Vector(double dx, double dy, bool settingInDxDy) : 
    angle_(calcAngle(dx, dy)), length_(calcLength(dx, dy)) 
{
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
    assert(std::isfinite(length));

    length_ = length >= 0 ? length : 0;
}

void Vector::scale(double deltaLength)
{
    assert(std::isfinite(deltaLength));

    length_ += deltaLength;

    if (length_ < 0)
        length_ = 0;
}

double Vector::getDx() const
{
    return length_ * std::cos(angle_);
}

double Vector::getDy() const
{
    return length_ * std::sin(angle_);
}

double Vector::getAngle()  const
{
    return angle_;
}

double Vector::getLength() const
{
    return length_;
}

Vector Vector::GetNormal() const
{
    return Vector(angle_ + M_PI_2, 1.);
}

Vector Vector::operator - () const
{
    return Vector(angle_ + M_PI, length_);
}

Vector Vector::operator + (const Vector& other) const
{
    double dx = getDx() + other.getDx();
    double dy = getDy() + other.getDy();

    return Vector(calcAngle(dx, dy), calcLength(dx, dy));
}

Vector Vector::operator - (const Vector& other) const
{
    double dx = getDx() - other.getDx();
    double dy = getDy() - other.getDy();

    return Vector(calcAngle(dx, dy), calcLength(dx, dy));
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