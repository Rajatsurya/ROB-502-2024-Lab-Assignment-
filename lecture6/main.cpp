#include <iostream>

using namespace std;

// any new function must be above the main as the compilation is top down
void increment(int& x);
void decrement(int& y);
void Half(int& z);

int main(){
    int x = 5;
    int y = 6;
    int z = 7;
    cout << x << endl;

    increment(x);
    cout << x << endl;

    decrement(y);
    cout << x << endl;

    Half(z);
    cout << x << endl;

    return 0;
}

void increment(int &x) {
    x++;
} // removed the semicolon after the closing brace

void decrement(int &y){
    y--;
}
void Half(int& z){
    z=z/2;
}