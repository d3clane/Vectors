#include <iostream>

#include "Graphics.hpp"
#include "Vector.hpp"
#include "CoordsSystem.hpp"
#include "Events.hpp"

int main()
{    
   
    Graphics::Window window(800, 600, "Vectors");

    Scene::CoordsSystem coordsSystem(50, 50, Graphics::Point{500, 500});
    // 250 250
    Scene::Vector vector{M_PI_2, 4};

    while (window.isOpen())
    {
        Graphics::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Graphics::Event::EventType::Closed)
                window.close();
        }

        window.clear();

        coordsSystem.drawVector(window, vector, Scene::Point{-5, -5});
        
        window.display();

        vector.setAngle(std::atan2(event.mousePos.y - 250, event.mousePos.x - 250));
        //vector.scale(0.000001);
    }

}