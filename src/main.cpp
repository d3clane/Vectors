#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Application");
    
    sf::RectangleShape line;
    line.setSize(sf::Vector2f(400, 20));

    sf::Vertex line2[] =
    {
        sf::Vertex(sf::Vector2f(100, 100)),
        sf::Vertex(sf::Vector2f(600, 200)),
        sf::Vertex(sf::Vector2f(500, 10)),
        sf::Vertex(sf::Vector2f(10, 150)),
    };
    
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.draw(line2, 4, sf::Lines);
        window.display();
    }
}