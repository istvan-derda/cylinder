//
// Created by istvan on 21.04.20.
//

#include "Cylinder.h"


#include <cmath>
#include "Vector3.cpp"

std::string Cylinder::render(int slices) {
    throwErrorIfInvalidSlices(slices);

    std::string render = "";
    render += "solid cylinder\n";

    double zFront = -(this->height / 2);
    double zBack = (this->height / 2);
    Vector3 vCenterFront = Vector3(0, 0, zFront);
    Vector3 vCenterBack = Vector3(0, 0, zBack);

    for (int i = 0; i < slices; i++) {
        double alpha1 = (2 * M_PI * i) / slices;
        double x1 = std::cos(alpha1) * this->radius;
        double y1 = std::sin(alpha1) * this->radius;
        double alpha2 = (2 * M_PI * (i + 1)) / slices;
        double x2 = std::cos(alpha2) * this->radius;
        double y2 = std::sin(alpha2) * this->radius;

        Vector3 vFront1 = Vector3(x1, y1, zFront);
        Vector3 vFront2 = Vector3(x2, y2, zFront);
        Vector3 vBack1 = Vector3(x1, y1, zBack);
        Vector3 vBack2 = Vector3(x2, y2, zBack);

        //topTriangle
        render += renderFacet(vFront1, vFront2, vCenterFront);
        //bottomTriangle
        render += renderFacet(vBack1, vCenterBack, vBack2);
        //sideRectangle
        render += renderFacet(vFront1, vBack1, vBack2);
        render += renderFacet(vFront1, vBack2, vFront2);
    }

    render += "endsolid cylinder\n";
    return render;
}

std::string Cylinder::renderFacet(Vector3 v1, Vector3 v2, Vector3 v3) {
    Vector3 normal = Vector3(0,0,0);
    std::string render = "";
    render += "facet normal " + normal.toString() + "\n";
    render += "outer loop\n";
    render += "vertex " + v1.toString() + "\n";
    render += "vertex " + v2.toString() + "\n";
    render += "vertex " + v3.toString() + "\n";
    render += "endloop\n";
    render += "endfacet\n";
    return render;
}

void Cylinder::throwErrorIfInvalidSlices(int slices) {
    if (slices < 3) { throw "number of slices must be >2"; }
    return;
}

