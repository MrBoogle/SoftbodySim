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
    sf::Texture texture;
    if (!texture.loadFromFile("cute_image.jpeg"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    // Start the game loop
    sf::CircleShape shape(5.f);
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
                    
                    shape.setFillColor(sf::Color(100, 250, 50));
                    shape.setPosition(event.mouseButton.x, event.mouseButton.y);
                    
                }
}
        }
        // Clear screen
        window.clear(sf::Color::White);
        window.draw(shape);
        // Draw the sprite
        //window.draw(sprite);
        // Draw the string
       // window.draw(text);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}