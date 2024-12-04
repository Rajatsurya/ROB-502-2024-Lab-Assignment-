#include<iostream>
#include<vector>
#include<limits> // for std::numeric_limits<int>::max()

void fibonacci(int x, int y, std::vector<int>& v) {
    int temp;
    v.push_back(x);
    v.push_back(y);

    while (true) {
        temp = y;
        if (y > (std::numeric_limits<int>::max() - x)) { // Check for overflow
            break;
        }
        y = x + y;
        x = temp;
        v.push_back(y);
    }
    
    // Print the Fibonacci sequence generated
    for(int j = 0; j < v.size(); j++) {
        std::cout << v[j] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int x = 0;  // First number in the sequence
    int y = 1;  // Second number in the sequence

    std::vector<int> v; // Vector to hold the Fibonacci sequence

    // Call the function
    fibonacci(x, y, v);

    // Output the largest Fibonacci number that fits in an int
    std::cout << "The largest Fibonacci number that fits in an int: " << v.back() << std::endl;

    return 0;
}
