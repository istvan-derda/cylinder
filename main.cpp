#include <iostream>
#include <fstream>
#include "Cylinder.cpp"

double getHeightFromUserInput();

double getRadiusFromUserInput();

int getResolutionFromUserInput();

void PrintCheekyCommentOnResolution(int resolution);

void renderCylinderToOutfile(double height, double radius, int resolution);

void printMessage(std::string message) {
    std::cout << message << std::endl;
}

int main() {
    std::cout << "A command-line-program to render a cylinder to stl" << std::endl;

    double height = getHeightFromUserInput();
    double radius = getRadiusFromUserInput();
    int resolution = getResolutionFromUserInput();

    PrintCheekyCommentOnResolution(resolution);

    renderCylinderToOutfile(height, radius, resolution);

    printMessage("\n\nRendered cylinder to cylinder.stl next to the executable.");

    return 0;
}

void renderCylinderToOutfile(double height, double radius, int resolution) {
    Cylinder cylinder = Cylinder(height, radius);
    std::string renderedScene = cylinder.render(resolution);

    std::ofstream outfile;
    outfile.open("cylinder.stl");
    outfile << renderedScene;
    outfile.close();
}

void PrintCheekyCommentOnResolution(int resolution) {
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
}

int getResolutionFromUserInput() {
    int resolution;
    do {
        std::cout << "Enter the desired NUMBER OF SIDES of the cylinder when rendered (>= 3)" << std::endl;
        std::cin >> resolution;
    } while (resolution < 3);
    return resolution;
}

double getHeightFromUserInput() {
    double height = 0;
    do {
        std::cout << "Enter the HEIGHT of the cylinder (>0)" << std::endl;
        std::cin >> height;
    } while (!(height > 0));
    return height;
}

double getRadiusFromUserInput() {
    double radius;
    do {
        std::cout << "Enter the RADIUS of the cylinder (>0)" << std::endl;
        std::cin >> radius;
    } while (!(radius>0));
    return radius;
}

