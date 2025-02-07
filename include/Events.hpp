#ifndef EVENTS_HPP
#define EVENTS_HPP

#include <SFML/Graphics.hpp>
#include "Graphics.hpp"

namespace Graphics
{

class Event
{
private:
    sf::Event sfEvent;
    
public:

    enum class EventType
    {
        None,

        Closed,
        KeyPressed,
        MouseMove,
    };

    enum class KeyCode
    {
        None, 

        W,
        S,
        A,
        D,
        Add,
        Subtract,
    };

    EventType type;
    Point mousePos;
    KeyCode keyCode;

    Event();

    friend bool Window::pollEvent(Event& event);
};

} // Graphics

#endif // EVENTS_HPP