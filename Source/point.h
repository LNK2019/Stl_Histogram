#ifndef POINT_H
#define POINT_H
#include <cmath>

struct Point
{
    float x_, y_, z_;
public:
    Point(float x, float y, float z) :
         x_(x), y_(y), z_(z) {}
    Point() {}
    float getDistanceTo(Point rVal) {
        return sqrt(pow(x_ - rVal.x_,2) + pow(y_ - rVal.y_, 2) + pow(z_ - rVal.z_,2));
    }
    float getDistance() {
        return sqrt(pow(x_,2) + pow(y_,2) + pow(z_,2));
    }
};

#endif // POINT_H
