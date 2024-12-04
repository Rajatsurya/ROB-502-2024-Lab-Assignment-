#include <eigen3/Eigen/Eigen>
#include <iostream>
int main() {
// [x, y, z, 1]
Eigen::Vector3d x(0.2, 0.5, 1.1);
Eigen::Vector4d x_h = x.homogeneous();
std::cout << x_h << '\n';
return 0;
}