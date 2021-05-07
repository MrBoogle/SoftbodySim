#include "vertex.h"
#include "globals.h"

squishPoint::squishPoint(float x, float y) {
    position = sf::Vector2f(x, y);
    this->shape.setRadius(10.f);
    this->shape.setFillColor(sf::Color::Red);
    this->shape.setPosition(x, y);
}

void squishPoint::CreatePoint(float x, float y) {
    
}