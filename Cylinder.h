//
// Created by istvan on 21.04.20.
//

#ifndef ZYLINDER_CYLINDER_H
#define ZYLINDER_CYLINDER_H

#include "Vector3.h"


class Cylinder {
public:
    double height;
    double radius;

    Cylinder(double height, double radius) : height(height), radius(radius) {}

    std::string render(int slices);
private:
    std::string renderSideRectangle(int count, int total);


    std::string renderFacet(Vector3 v1, Vector3 v2, Vector3 v3);

    std::string frontTriangle(int count, int totalSlices);

    std::string backTriangle(int i, int slices);
};


#endif //ZYLINDER_CYLINDER_H
