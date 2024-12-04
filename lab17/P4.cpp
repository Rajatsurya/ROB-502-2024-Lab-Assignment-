#include <iostream>
#include <memory>

class BigOldClass
{
public:
    BigOldClass(int size) : _size(size) // Constructor 1: initializes with `size`
    {
        std::cout << "constructing BigOldClass: " << this << std::endl;
    }

    BigOldClass(BigOldClass const& copy) // Copy constructor
    {
        std::cout << "constructing BigOldClass by copying: " << this << std::endl;
        _size = copy._size;
    }

    ~BigOldClass() // Destructor
    {
        std::cout << "destructing BigOldClass: " << this << std::endl;
    }

    int _size;
};

void print_copy(BigOldClass c) // Takes `BigOldClass` by value (triggers copy constructor)
{
    std::cout << "pass by value: address: " << &c << std::endl;
}

void print_reference(BigOldClass const &c) // Takes `BigOldClass` by const reference (no constructor or destructor)
{
    std::cout << "pass by const ref: address: " << &c << std::endl;
}

void print_pointer(BigOldClass const *c) // Takes `BigOldClass` by pointer (no constructor or destructor)
{
    std::cout << "pass by raw ptr: address: " << c << std::endl;
}

void print_unique_pointer(std::unique_ptr<BigOldClass> const &c) // Takes `unique_ptr` by const ref (no constructor or destructor)
{
    std::cout << "pass by const ref to unique_ptr: address: " << c.get() << std::endl;
}

int main()
{
    BigOldClass c1(100); // Constructor 1 called for `c1`
    // Output: "constructing BigOldClass: <address of c1>"

    auto *c1_ptr = &c1; // No constructor or destructor called; only a pointer assignment

    // `c1` is passed by const reference, so the copy constructor is called here to create the managed object
    auto const c1_unique_ptr_copy = std::make_unique<BigOldClass>(c1); 
    // Copy constructor is called for the new instance in the unique_ptr
    // Output: "constructing BigOldClass by copying: <address of the new BigOldClass in unique_ptr>"

    // Directly constructs a new `BigOldClass` with `size=100`, so Constructor 1 is called
    auto const c1_unique_ptr_emplace = std::make_unique<BigOldClass>(100);
    // Output: "constructing BigOldClass: <address of the new BigOldClass in unique_ptr>"

    print_copy(c1); // Calls `print_copy` with `c1` by value, so a copy is made.
    // Copy constructor called for the copy made within `print_copy`
    // Output: "constructing BigOldClass by copying: <address of copy>"
    // Output: "pass by value: address: <address of copy>"
    // Destructor called for the copy after `print_copy` completes
    // Output: "destructing BigOldClass: <address of copy>"

    print_reference(c1); // Calls `print_reference` with `c1` by const reference
    // No constructor or destructor
    // Output: "pass by const ref: address: <address of c1>"

    print_pointer(&c1); // Calls `print_pointer` with a pointer to `c1`
    // No constructor or destructor
    // Output: "pass by raw ptr: address: <address of c1>"

    print_unique_pointer(c1_unique_ptr_copy); // Calls `print_unique_pointer` with a reference to `c1_unique_ptr_copy`
    // No constructor or destructor
    // Output: "pass by const ref to unique_ptr: address: <address of c1_unique_ptr_copy's managed object>"

    print_unique_pointer(c1_unique_ptr_emplace); // Calls `print_unique_pointer` with a reference to `c1_unique_ptr_emplace`
    // No constructor or destructor
    // Output: "pass by const ref to unique_ptr: address: <address of c1_unique_ptr_emplace's managed object>"

    return 0;
} // `c1`, `c1_unique_ptr_copy`, and `c1_unique_ptr_emplace` go out of scope here
// Destructor called for `c1`
// Output: "destructing BigOldClass: <address of c1>"
// Destructor called for `c1_unique_ptr_copy`'s managed object
// Output: "destructing BigOldClass: <address of c1_unique_ptr_copy's managed object>"
// Destructor called for `c1_unique_ptr_emplace`'s managed object
// Output: "destructing BigOldClass: <address of c1_unique_ptr_emplace's managed object>"



// Constructor/Destructor	Number of Calls
//Parameterized Constructor	  3
//Copy Constructor	          2
//Destructor	              5