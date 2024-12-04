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

    std::cout<< sizeof(Circle) << std::endl;
    std::cout<< sizeof(Triangle) << std::endl;

    // virtual functions adds to the size of the class 


    return 0;
}