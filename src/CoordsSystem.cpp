#include "CoordsSystem.hpp"

namespace Scene
{

using Graphics::Line;

void CoordsSystem::drawLine(Graphics::Window& window, 
                            const Vector& vector, const Point& beginInCoordsSystem) const
{
    int dx = (int)(vector.getDx() * stepX);
    int dy = (int)(vector.getDy() * stepY);

    Graphics::Point begin(center_.x + beginInCoordsSystem.x * stepX, center_.y + beginInCoordsSystem.y * stepY);
    Graphics::Point end(dx + begin.x, dy + begin.y);

    window.drawLine(Line(begin, end));  
}

void CoordsSystem::drawVector(Graphics::Window& window, 
                              const Vector& vector, const Point& beginInCoordsSystem) const
{
    drawLine(window, vector, beginInCoordsSystem);

    Vector normal = vector.GetNormal();

    const double prettyLength = 0.2;
    normal.setLength(prettyLength);

    double normalLength = prettyLength;
    Vector coDirectionalVector = Vector(vector.getAngle(), normalLength);

    Vector arrowVector1 =  normal - coDirectionalVector;
    Vector arrowVector2 = -normal - coDirectionalVector;

    // TODO: it should be function named shift
    Point end = Point(beginInCoordsSystem.x + vector.getDx(), beginInCoordsSystem.y + vector.getDy());
    drawLine(window, arrowVector1, end);
    drawLine(window, arrowVector2, end);
}

} // Scene