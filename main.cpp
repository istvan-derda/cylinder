#include <iostream>
#include <fstream>
#include "Cylinder.cpp"

int main() {
    double height;
    double radius;
    int resolution;
    std::cout << "Enter the HEIGHT of the cylinder" << std::endl;
    std::cin >> height;
    std::cout << "Enter the RADIUS of the cylinder" << std::endl;
    std::cin >> radius;
    do {
        std::cout << "Enter the desired NUMBER OF SIDES of the cylinder when rendered (min 3)" << std::endl;
        std::cin >> resolution;
    } while (resolution<3);


    Cylinder cylinder = Cylinder(height, radius);
    std::string renderedScene = cylinder.render(resolution);

    std::ofstream outfile;
    outfile.open("cylinder.stl");
    outfile << renderedScene;
    outfile.close();

    return 0;
}

