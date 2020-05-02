#include <iostream>
#include <fstream>
#include "Cylinder.cpp"

void printMessage(std::string message) {
    std::cout << message << std::endl;
}

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


    if (resolution < 7) {
        std::cout << "Edgy!" << std::endl;
    } else if (resolution < 20) {
        std::cout << "Here you go!" << std::endl;
    } else if (resolution < 100) {
        std::cout << "Mmh, so smooth" << std::endl;
    } else if (resolution < 5000) {
        std::cout << "You must have an amazing printer!" << std::endl;
    } else if (resolution < 50000) {
        std::cout << "Yea, I can still do that" << std::endl;
    } else if (resolution < 500000) {
        std::cout << "Ok, give me a sec" << std::endl;
    } else if (resolution < 1000000) {
        printMessage("Are you trying to heat your room with a CPU?");
    } else if (resolution >= 1000000) {
        printMessage("This is a benchmark, right?");
    }

    Cylinder cylinder = Cylinder(height, radius);
    std::string renderedScene = cylinder.render(resolution);

    std::ofstream outfile;
    outfile.open("cylinder.stl");
    outfile << renderedScene;
    outfile.close();

    printMessage("\n\nRendered cylinder to cylinder.stl next to the executable.");

    return 0;
}

