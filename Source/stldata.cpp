#include "stldata.h"
#include <qfile>
#include <iostream>
#include <QTextStream>
#include <qstringlist>
#include <set>
#define SPACE ' '
StlData::StlData()
{

}

void StlData::addTriangle(Triangle triangle){
    triangles_.push_back(triangle);
}


bool StlData::parseData(QString filename) {
    QFile output(filename);
    if(!output.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }
    std::vector<Point> vertices;
    QString buffForLine;
    QStringList buffForWords;
    QTextStream strStream(&output);
    strStream.readLine();
    while(true){
        buffForLine = strStream.readLine();
        buffForWords = buffForLine.split(SPACE);
        if(strStream.atEnd())
            break;
        Point normal(buffForWords.at(4).toFloat(), buffForWords.at(5).toFloat(),
                     buffForWords.at(6).toFloat());
        strStream.readLine();
        for(size_t i = 0; i < NUM_OF_VERTICES; ++i) {
            buffForLine = strStream.readLine();
            buffForWords = buffForLine.split(SPACE);
            vertices.push_back(Point(buffForWords[8].toFloat(),
                                     buffForWords[9].toFloat(), buffForWords[10].toFloat()));
        }
        addTriangle(Triangle(normal, vertices[0], vertices[1], vertices[2]));
        vertices.clear();
        strStream.readLine();
        strStream.readLine();
    }
    return true;
}

std::set<HistogramElement*,compareCorner> StlData::getHistogram() {

    std::set<HistogramElement*,compareCorner> areasSet_;
    for(auto it  : triangles_) {
       auto feedBackPair = areasSet_.insert(new HistogramElement(it.cornerBetweenXOY_));
       HistogramElement *buff = (*feedBackPair.first);
       buff->sameTriangles.push_back(it);
    }
    for(auto it : areasSet_) it->findAreasSum();
    return areasSet_;
}
