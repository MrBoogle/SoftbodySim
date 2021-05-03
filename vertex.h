#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
class squishPoint {
    public:
        std::vector<float> position;
        std::vector<float> velocity;
        std::vector<float> force;
        sf::CircleShape shape;
        void CreatePoint(float x, float y);
        squishPoint();
        squishPoint(float x, float y);
        
};