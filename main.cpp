#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include "vertex.h"

std::vector<squishPoint*> points;
std::vector<std::pair<float, std::pair<sf::Vector2f, sf::Vector2f>>> springs;


float getDistance (sf::Vector2f first, sf::Vector2f sec) {
    return sqrt(pow(first.x-sec.x, 2.0) + pow(first.y-sec.y, 2));
}

//Sets window size to be 800px by 600px
int windowX = 800;
int windowY = 600;

void update(squishPoint* p, float speed) {
    p->velocity += p->force * speed;
    p->position += p->velocity * speed;
    if (p->position.y > windowY - 2*p->shape.getRadius()) p->position.y = windowY - 2*p->shape.getRadius();
    else if (p->position.y < 0) p->position.y = 0;
    if (p->position.x > windowX - 2*p->shape.getRadius()) p->position.x = windowX - 2*p->shape.getRadius();
    else if (p->position.x < 0) p->position.x = 0;
    p->shape.setPosition(p->position.x,p->position.y);
    
}


int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(windowX, windowY), "Softbody Sim");
    // Load a sprite to display

    sf::RectangleShape playButton;
    playButton.setSize(sf::Vector2f(50, 50));
    playButton.setPosition(750, 0);
    playButton.setFillColor(sf::Color::Red);
    bool play = false;


    sf::Clock clock;
    float lastTime = 0;
    // Start the game loop
    while (window.isOpen())
    {
        float currentTime = clock.restart().asSeconds();
        float fps = 1.f / (currentTime - lastTime);
        lastTime = currentTime;
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
                    squishPoint* newPoint = new squishPoint(event.mouseButton.x, event.mouseButton.y);
                    //Adds the new point to the global vector that is the softbody shape
                    points.push_back(newPoint);
                    //Update springs between points
                    if (points.size() >= 2) {
                        float initDist = getDistance (points[springs.size()-1]->position, newPoint->position);
                        springs[springs.size()-1] = std::make_pair(initDist, std::make_pair(points[springs.size()-1]->position, newPoint->position));
                        float lastDist = getDistance (points[0]->position, newPoint->position);
                        springs.push_back(std::make_pair(lastDist, std::make_pair(newPoint->position, points[0]->position)));

                    }


                } else if (event.mouseButton.button == sf::Mouse::Left) {
                    if (event.mouseButton.x > 750 && event.mouseButton.y < 50) {
                        if (play) {
                            play = false;
                            playButton.setFillColor(sf::Color::Red);
                        } else {
                            play = true;
                            playButton.setFillColor(sf::Color::Green);
                        }
                    }
                }
}
        }
        // Clear screen
        window.clear(sf::Color::White);
        
        if (play)
        
        for (int p = 0; p < points.size(); p++) {
            



            //Update position of all points
            if (play) update(points[p], 0.002);
            //Draw all points
            window.draw(points[p]->shape);
        }

        window.draw(playButton);

        window.display();
    }
    return EXIT_SUCCESS;
}