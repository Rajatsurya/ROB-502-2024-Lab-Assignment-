#include <iostream>

template <typename T>
class Array {
private:
  int size;
  T* elements;

public:
  Array(int size) {
    this->size = size;
    elements = new T[size];
  }

  ~Array() {
    delete[] elements;
  }

  int getSize() const {
    return size;
  }

  T& operator[](int index) {
    return elements[index];
  }

  void printArray() const {
    std::cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
      std::cout << elements[i] << " ";
    }
    std::cout << std::endl;
  }

};

template <typename T>
void printArray(const Array<T>& arr) {
  arr.printArray();
}

int main() {
  Array<int> a(3);
  a[1] = 5;
  printArray(a);

  Array<double> b(5);
  b[0] = 2.2;
  printArray(b);

  return 0;
}