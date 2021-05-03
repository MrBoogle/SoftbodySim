#include "vertex.h"
#include "globals.h"

squishPoint::squishPoint(float x, float y) {
    position.resize(2);
    velocity.resize(2);
    force.resize(2);
    position[0] = x;
    position[1] = y;
    this->shape.setRadius(10.f);
    this->shape.setFillColor(sf::Color::Red);
    this->shape.setPosition(x, y);
}

void squishPoint::CreatePoint(float x, float y) {
    
}