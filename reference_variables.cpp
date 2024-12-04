#include <iostream>

int main() {
    int x = 0;
    int y = x; // This allocates new memory for the variable y and copies the value of x.
    int &rX = x; // This is a reference variable; no new memory is allocated.

    x = 5;
    rX = 6;

    std::cout << x << std::endl;  // Outputs 6
    std::cout << y << std::endl;  // Outputs 0
    std::cout << rX << std::endl; // Outputs 6

    return 0;
}
