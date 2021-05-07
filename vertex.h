#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
class squishPoint {
    public:
        sf::Vector2f position = sf::Vector2f(0, 0);
        sf::Vector2f velocity = sf::Vector2f(0, 0);
        sf::Vector2f force = sf::Vector2f(0, 9.8);
        sf::Vector2f rest;
        sf::Vector2f acc = force;
        sf::CircleShape shape;
        void CreatePoint(float x, float y);
        squishPoint();
        squishPoint(float x, float y);
        
};