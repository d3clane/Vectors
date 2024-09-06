#ifndef COORDS_SYSTEM_HPP
#define COORDS_SYSTEM_HPP

#include "Graphics.hpp"
#include "Vector.hpp"

namespace Scene
{

struct Point
{
    double x, y;

    Point(double x, double y) : x(x), y(y) {}
};

class CoordsSystem
{
    Graphics::Point center_;
    
    unsigned int stepX, stepY;

public:

    CoordsSystem(unsigned int stepX, unsigned int stepY, const Graphics::Point& center) : 
        stepX(stepX), stepY(stepY), center_(center) {}

    void drawLine  (Graphics::Window& window, const Vector& vector, const Point& begin) const;
    void drawVector(Graphics::Window& window, const Vector& vector, const Point& begin) const;
};

} // Scene

#endif // COORDS_SYSTEM_HPP