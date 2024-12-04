#include<iostream>
#include<vector>

// Your fibonacci function
void fibonacci(int x, int y, std::vector<int> v, int n) {
    int temp;
    v.push_back(x);
    v.push_back(y);
    for(int i = 0; i < n - 2; i++) {
        temp = y;
        y = x + y;
        x = temp;
        v.push_back(y);
    }

    for(int j = 0; j < v.size(); j++) {
        std::cout << v[j] << " ";
    }
}

int main() {
    int x = 0;  // First number in the sequence
    int y = 1;  // Second number in the sequence
    int n = 10; // Number of terms in the sequence

    std::vector<int> v; // Vector to hold the Fibonacci sequence

    // Call the function
    fibonacci(x, y, v, n);

    return 0;
}
