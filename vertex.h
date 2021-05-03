#pragma once

#include <vector>

class squishPoint {
    public:
        std::vector<float> position;
        std::vector<float> velocity;
        std::vector<float> force;
        void CreatePoint(float x, float y);
        squishPoint();
        squishPoint(float x, float y);
        
};