#include <vector>
#include <algorithm>
#include <iostream>

int main () {
std::vector<int> vec{0,4,3,5,6,1,7,6,4};
int result;
std::sort(vec.begin(),vec.end(),std::greater<int>());
result=vec[3];
if (vec.size() >= 4){
    std::cout << result << "\n";
}
else {
    std::cout << "the size of the vector is not big enough" << std::endl;
}
return 0;
}