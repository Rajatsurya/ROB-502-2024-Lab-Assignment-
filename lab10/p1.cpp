#include <iostream>
#include <string>
using namespace std;
class Base {
public:
int _i;
Base(int i) {
this->_i = i;
cout << "Constructing base " << _i << endl;
}
~Base() {
cout << "Destructing base " << _i << endl ;
}
};
class Derived: public Base {
public:
Derived(int i) : Base(i) {
cout << "Constructing derived " << _i << endl;
}
~Derived() {
cout << "Destructing derived " << _i << endl;
}
};
int main() {
Derived d{1};
Base b{2};
}