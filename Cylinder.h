//
// Created by istvan on 21.04.20.
//

#ifndef CYLINDER_CYLINDER_H
#define CYLINDER_CYLINDER_H

#include "Vector3.h"


class Cylinder {
public:
    Cylinder(double height, double radius) : height(height), radius(radius) {}

    std::string render(int slices);

private:
    double height;
    double radius;

    std::string renderFacet(Vector3 v1, Vector3 v2, Vector3 v3);

    void throwErrorIfInvalidSlices(int slices);
};


#endif //CYLINDER_CYLINDER_H
