#include <memory>
#include <iostream>

class BigOldClass
{
public:
    BigOldClass(int size) : _size(size) {} // Constructor for BigOldClass
    int _size;
};

class BigDataManager
{
public:
    // Constructor for BigDataManager that takes a shared pointer to BigOldClass
    BigDataManager(std::shared_ptr<BigOldClass> data) : data_(std::move(data)) {}

    std::shared_ptr<BigOldClass> data_; // Shared pointer to BigOldClass
};

// Function to create and return a shared pointer to a BigOldClass
std::shared_ptr<BigOldClass> make_big_thing() {
    return std::make_shared<BigOldClass>(42); // Create with any size (e.g., 42)
}

// Print function for BigDataManager
void print_manager(BigDataManager const &m) {
    std::cout << "Data of size: " << m.data_->_size << std::endl;
}

int main()
{
    // Call make_big_thing and store the result in an auto variable
    auto big_thing = make_big_thing();

    // Construct BigDataManager using the BigOldClass from make_big_thing
    BigDataManager manager(big_thing);

    // Call print_manager using the BigDataManager
    print_manager(manager);

    return 0;
}
