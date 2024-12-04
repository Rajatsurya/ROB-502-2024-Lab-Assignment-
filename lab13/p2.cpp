#include <eigen3/Eigen/Eigen>
#include <iostream>
int main()
{
Eigen::Matrix<double, 12, 3> points;
points << 0, 0, 0,
0, 1, 0,
0, 2, 0,
1, 0, 0,
1, 1, 0,
1, 2, 0,
2, 0, 0,
2, 1, 0,
2, 2, 0,
3, 0, 0,
3, 1, 0,
3, 2, 0;
// create the A matrix from points
// create the b matrix from points
// solve for x
// convert x to our plane coefficients
Eigen::MatrixXd A(points.rows(), 3);
A.col(0) = points.col(0); // x-coordinates
A.col(1) = points.col(1); // y-coordinates
A.col(2) = Eigen::VectorXd::Ones(points.rows()); // column of ones for the constant term

// Create vector b (z-coordinates)
Eigen::VectorXd b = points.col(2); // z-coordinates

 // Solve for x using the least squares method (A * x = b)
Eigen::VectorXd x = A.colPivHouseholderQr().solve(b);
    // Output the plane coefficients
    std::cout << "Plane coefficients (A, B, C): " << std::endl;
    std::cout << "A = " << x(0) << std::endl; // Coefficient for x
    std::cout << "B = " << x(1) << std::endl; // Coefficient for y
    std::cout << "C = " << x(2) << std::endl; // Constant term
return 0;
}