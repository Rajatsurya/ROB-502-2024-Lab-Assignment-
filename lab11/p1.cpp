#include <iostream>
#include <cmath>  // for math functions and constants
#include <string>
#include <iomanip>

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
    Circle c1 {1.0};  // Initialize circle with radius 1
    std::cout << c1.getType() << ' ' << std::setprecision(3) << c1.area() << std::endl;

    c1.scale(2);  // Scale the circle's radius by 2
    std::cout << std::setprecision(3) << c1.area() << std::endl;

    Triangle t1 {2.0, 5.0};  // Initialize triangle with base 2 and height 5
    std::cout << t1.getType() << ' ' << t1.area() << std::endl;

    t1.setBase(3.0);  // Change base to 3
    t1.setHeight(4.0);  // Change height to 4
    std::cout << t1.area() << std::endl;

    // Compare the areas of c1 and t1 using the overloaded < operator
    std::cout << "c1 < t1? " << (c1 < t1) << std::endl;
    std::cout << "t1 < c1? " << (t1 < c1) << std::endl;

    return 0;
}
// Do These Approaches Work? Why?
// Both approaches work because:

// Polymorphism: The area() method is declared as virtual in the base class Shape2D and is overridden in the derived classes (Circle, Triangle). This ensures that the correct area() method is called based on the actual object type (either Circle or Triangle), not just the base class type.

// Template Approach: In the template approach, the function is generalized to work with any types that have an area() method, which allows flexibility to compare different shapes without depending on the class hierarchy. This is more powerful when you're not restricted to the inheritance relationship.

// Direct Comparison Approach: In the direct comparison approach, you rely on the class hierarchy. The comparison happens within the Shape2D family, and it works because both shapes share a common base class and both override the area() method.

// Both approaches are valid and effective. Template-based comparison provides more generality and works outside the class hierarchy, while direct comparison within the Shape2D hierarchy is simpler and more constrained.