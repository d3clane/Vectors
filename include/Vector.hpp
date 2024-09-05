#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <stddef.h>

namespace Scene
{

class Vector
{
    double angle_;
    double length_;

public:
    Vector(double angle, double length) : angle_(angle), length_(length) {}

    void setAngle(double angle);
    void rotate  (double deltaAngle);

    void setLength(double length);
    void scale    (double deltaLength);

    int getDx () const;
    int getDy () const;
};

} // Scene

#endif // VECTOR_HPP