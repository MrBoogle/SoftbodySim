#include "vertex.h"
#include "globals.h"

squishPoint::squishPoint(float x, float y) {
    position[0] = x;
    position[1] = y;
}

void squishPoint::CreatePoint(float x, float y) {
    squishPoint* newPoint = new squishPoint(x, y);
    points.push_back(newPoint);
}