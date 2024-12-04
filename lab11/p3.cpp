#include <iostream>
#include <cmath>  // for math functions and constants
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm> 

class Shape2D {
public:
    Shape2D() : type("Unknown") {}
    
    virtual double area() const { return 0; }  // area method to be overridden in derived classes
    const std::string& getType() const { return type; }
    void setType(const std::string& type) { this->type = type; }

    // Overload the less-than operator to compare areas of Shape2D objects
    bool operator<(const Shape2D& other) const {
        return this->area() < other.area();
    }

private:
    std::string type;
};

class Circle : public Shape2D {// the public class of Shape2D is inherited
public:
    Circle(double r) : radius(r) {// we are setting the class in such a way that it can take the radius as the input
        setType("Circle");
    }
    
    // Override the area method for Circle
    virtual double area() const override {
        return M_PI * radius * radius;
    }

    // Scale the circle's radius
    void scale(int factor) {// new function scale is defined 
        radius *= factor;
    }

private:
    double radius;
};

class Triangle : public Shape2D {// the public class of Shape2D is inherited
public:
    Triangle(double b, double h) : base(b), height(h) { //  we are setting the class in such a way that it can take new arguments 
        setType("Triangle");
    }

    // Override the area method for Triangle
    virtual double area() const override {
        return 0.5 * base * height;
    }

    // Set new base value
    void setBase(double b) {
        base = b;
    }

    // Set new height value
    void setHeight(double h) {
        height = h;
    }

private:
    double base;
    double height;
};

int main() {

        Circle c1 {1.652};
        // std::cout<< c1.area() << std::endl;
        Circle c2 {1.9123};
        // std::cout<< c2.area() << std::endl;
        Triangle t1 {3.72, 5.432};
        // std::cout<< t1.area() << std::endl;
        Triangle t2 {4.12, 4.552};
        // std::cout<< t2.area() << std::endl;
        Triangle t3 {2.623, 6.52};
        // std::cout<< t3.area() << std::endl;

        std::vector<double> areas = {c1.area(), c2.area(), t1.area(), t2.area(), t3.area()};
        std::sort(areas.begin(),areas.end());// sort only works for vectors

        for (const auto& area : areas) {
        std::cout << std::fixed << std::setprecision(3) << area << std::endl;
    }

    return 0;
}