//
// Created by istvan on 21.04.20.
//

#ifndef ZYLINDER_VECTOR3_H
#define ZYLINDER_VECTOR3_H


class Vector3 {
public:
    double x;
    double y;
    double z;

    Vector3(double x, double y, double z) : x(x), y(y), z(z) {}
    std::string toString();
};




#endif //ZYLINDER_VECTOR3_H
