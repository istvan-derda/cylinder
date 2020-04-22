//
// Created by istvan on 21.04.20.
//

#include "Vector3.h"

std::string Vector3::toString() {
    std::string str;
    str = std::to_string(this->x) + " "
            + std::to_string(this->y )+ " "
            + std::to_string(this->z);
    return str;
}
