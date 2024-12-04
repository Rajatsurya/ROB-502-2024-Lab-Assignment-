#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h> 

class Circle {
public:
    Circle(double r) : radius(r) {}
    double area() const { return M_PI * radius * radius; }
    void scale(double factor) { radius *= factor; }
private:
    double radius;
};

int main() {
    std::vector<Circle> circles{ {4.76}, {1.2}, {4.7} }; // Initialize with Circle objects

    circles[1].scale(0.07); // Scale the second circle

    std::cout << std::fixed << std::setprecision(3) << circles[1].area(); // Print the area of the second circle
}
