#include "Graphics.hpp"

namespace Graphics
{

Window::Window(int width, int height, const char* title) : 
        window_(sf::VideoMode(width, height), title) 
{
}

void Window::display()
{
    window_.display();
}

bool Window::isOpen()
{
    return window_.isOpen();
}

void Window::close()
{
    window_.close();
}

void Window::clear()
{
    window_.clear();
}

void Window::drawLine(Line line)
{
    sf::Vertex drewLine[] =
    {
        sf::Vertex(sf::Vector2f(line.start.x, line.start.y)),
        sf::Vertex(sf::Vector2f(line.end.x,   line.end.y  )),
    };

    window_.draw(drewLine, sizeof(drewLine) / sizeof(*drewLine), sf::Lines);
}

} // Graphics