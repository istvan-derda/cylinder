#include <iostream>
#include <fstream>
#include "Cylinder.cpp"

int main() {
    double height;
    double radius;
    int resolution;

    std::cout << "A command-line-program to render a cylinder to stl" << std::endl;
    std::cout << "Enter the HEIGHT of the cylinder" << std::endl;
    std::cin >> height;
    std::cout << "Enter the RADIUS of the cylinder" << std::endl;
    std::cin >> radius;

    do {
        std::cout << "Enter the desired NUMBER OF SIDES of the cylinder when rendered (min 3)" << std::endl;
        std::cin >> resolution;
    } while (resolution < 3);

    // an dieser Stelle switch-case?
    // Satzanfang groß
    // std::cout vllt auslagern und die verschiedenen ausgabenin eine variable packen und nach dem switch ausgeben
    if (resolution < 7) {
        std::cout << "edgy!" << std::endl;
    } else if (resolution < 20) {
        std::cout << "here you go!" << std::endl;
    } else if (resolution < 100) {
        std::cout << "mmh, so smooth" << std::endl;
    } else if (resolution < 5000) {
        std::cout << "you must have an amazing printer!" << std::endl;
    } else if (resolution < 50000) {
        std::cout << "yea, I can still do that" << std::endl;
    } else if (resolution < 500000) {
        std::cout << "ok, give me a sec" << std::endl;
    } else if (resolution >= 500000) {
        std::cout << "are you trying to heat your room with a cpu?" << std::endl;
    }

    Cylinder cylinder = Cylinder(height, radius);
    std::string renderedScene = cylinder.render(resolution);

    std::ofstream outfile;
    outfile.open("cylinder.stl");
    outfile << renderedScene;
    outfile.close();

    return 0;
}

