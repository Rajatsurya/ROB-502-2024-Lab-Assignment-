#include <iostream>
#include<math.h>

using namespace std;
void increment(int &x) {
    x++;
} // removed the semicolon after the closing brace

void decrement(int &y){
    y--;
}
void Half(int& z){
    z=z/2;
}

// any new function must be above the main as the compilation is top down
// void increment(int& x);
// void decrement(int& y);
// void Half(int& z);

int main(){
    int x = 5;
    int y = 6;
    int z = 7;
    cout << x << endl;

    increment(x);
    cout << x << endl;

    decrement(y);
    cout << y << endl;

    Half(z);
    cout << z << endl;

    return 0;
}

// void increment(int &x) {
//     x++;
// } // removed the semicolon after the closing brace

// void decrement(int &y){
//     y--;
// }
// void Half(int& z){
//     z=z/2;
// }