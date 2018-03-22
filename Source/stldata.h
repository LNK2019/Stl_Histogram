#ifndef STLDATA_H
#define STLDATA_H
#include "triangle.h"
#include <deque>
#include <vector>
#include <set>
#include <qstring>

struct HistogramElement {
    float corner_;
    float areasSum_;
    std::vector<Triangle> sameTriangles;
public:
    HistogramElement(float corner) : corner_(corner) {}
    void findAreasSum() {
        float sum = 0;
        for(auto it : sameTriangles) sum += it.area_;
        areasSum_ = sum;
    }
};

struct compareCorner {
    bool operator()(const HistogramElement *lVal, const HistogramElement *rVal)
    {
        return lVal->corner_ < rVal->corner_;
    }
};



class StlData
{
    std::deque<Triangle> triangles_;
public:
    bool parseData(QString filename);
    void addTriangle(Triangle triangle);
    std::set<HistogramElement*,compareCorner> getHistogram();
    float getMaxAreasSum();
    StlData();
};




#endif // STLDATA_H
