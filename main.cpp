#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "vertex.h"

std::vector<squishPoint*> points;


int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Softbody Sim");
    // Load a sprite to display

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::MouseButtonPressed)
{
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    std::cout << "the right button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                    squishPoint* newPoint = new squishPoint(event.mouseButton.x, event.mouseButton.y);
                    //Adds the new point to the global vector that is the softbody shape
                   points.push_back(newPoint);
                }
}
        }
        // Clear screen
        window.clear(sf::Color::White);
        
        for (int p = 0; p < points.size(); p++) {
            window.draw(points[p]->shape);
        }



        window.display();
    }
    return EXIT_SUCCESS;
}