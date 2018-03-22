#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "point.h"
#include <cmath>

#define NUM_OF_VERTICES 3
#define PI_DEGREES 180
#define PI (float)3.14

struct Triangle
{
    using degrees = float;
    using distance = float;


    Point normal_;
    float area_;
    degrees cornerBetweenXOY_;
public:
    Triangle() {}
    Triangle(Point normal,Point A, Point B, Point C) :
        normal_(normal)
    {
        distance AtoBEdge = A.getDistanceTo(B);
        distance BtoCEdge = B.getDistanceTo(C);
        distance AtoCEdge = A.getDistanceTo(C);
        float semiP = (AtoBEdge + BtoCEdge + AtoCEdge)/2;
        area_ = sqrt(semiP * (semiP - AtoBEdge)*(semiP - BtoCEdge) * (semiP - AtoCEdge));
        Point projection(normal_.x_, normal_.y_, 0.0);
        cornerBetweenXOY_ = (acos(projection.getDistance()/normal_.getDistance())/PI) * PI_DEGREES;
        cornerBetweenXOY_ = (int)(cornerBetweenXOY_ + 0.5);
        if(normal_.z_ < 0)
            cornerBetweenXOY_ = -cornerBetweenXOY_;

    }
};

#endif // TRIANGLE_H
