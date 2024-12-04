#include <iostream>


template <typename T> 
T square(T num) { 
return num * num; 
} 


int main() {
  double n1=5.5;
  int n2=4;

  std::cout << square<double>(n1) << std::endl; 
  std::cout << square<int>(n1) << std::endl;
  std::cout << square<double>(n2) << std::endl; 
  std::cout << square<int>(n2) << std::endl;    
}