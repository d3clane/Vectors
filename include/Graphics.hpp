#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <SFML/Graphics.hpp>

namespace Graphics
{

struct Point
{
    int x, y;

    Point(int x, int y) : x(x), y(y) {}
};

struct Line
{
    Point start, end;

    Line(const Point& start, const Point& end) : start(start), end(end) {}
};

class Window
{
private:
    sf::RenderWindow window_;

public:
    Window(int width, int height, const char* title);

    bool isOpen();
    void close();
    void clear();

    void drawLine(Line line);

    void display();
};

} // Graphics

#endif // GRAPHICS_HPP