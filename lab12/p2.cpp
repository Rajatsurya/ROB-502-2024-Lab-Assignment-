#include <eigen3/Eigen/Dense>
#include <iostream>
#include <cmath>
#include <cassert>

int main()
{
    // Constructors, create the following, using the letter as the variable name 
    Eigen::Vector2i a;
    a << 0, 1;

    // Integer vector of size 3
    Eigen::Vector3i b;
    b << 0, -1, 3;

    // Integer vector of size 4
    Eigen::Vector4i c;
    c << 0, -1, 0, 1;

    // Matrix of doubles (2x2 matrix)
    Eigen::Matrix2d d;
    d << 0, 1,
         2, 3;

    // Create an integer matrix by casting the transpose of d
    Eigen::Matrix2i i = d.transpose().cast<int>(); // Explicitly cast to int

    // Define the rotation matrix function as a lambda function within main()
    auto e = [](double t = M_PI / 2) -> Eigen::Matrix3d {
        Eigen::Matrix3d e;
        e << cos(t), -sin(t), 0,
             sin(t),  cos(t), 0,
             0,      0,      1;
        return e;
    };

    // Initialize a 5x2 matrix of doubles
    Eigen::MatrixXd f(5, 2);
    f << 0.1, 0.1, 
         0.2, 0.0, 
         0.3, -0.1, 
         0.4, 0.0, 
         0.5, 0.1;

    // Assertions to check initialization
    assert(std::abs(e().sum() - 1) < 0.01);
    assert(std::abs(f.sum() - 1.6) < 0.01);

    // Create a 3x3 identity matrix called g of type double
    Eigen::Matrix3d g{Eigen::Matrix3d::Identity()}; 

    // h = g + e
    Eigen::Matrix3d h = g + e(); 

    // Element-wise absolute value of vector b, casting to double
    Eigen::Vector3d j = b.cast<double>().cwiseAbs(); // Cast b to double

    // k = h + j, broadcasting over the columns
    Eigen::Matrix3d k = h.colwise() + j; 

    // Set l to be the mean of each column in 'f'
    Eigen::Vector2d l = f.colwise().mean();

    // m = e * e^T
    Eigen::Matrix3d m = e() * e().transpose();

    // n = a + 5; Using an array for n
    Eigen::Array2i n = a.array() + 5; 

    // o = k + m
    Eigen::Matrix3d o = k + m; 

    // Get the first row o and store it in the variable o_first_row
    Eigen::Vector3d o_first_row = o.row(0); 

    // Use head to get the first 3 elements of the first column in f, and store it in the variable f_head
    Eigen::Vector3d f_head = f.col(0).head<3>(); // Looks at the top of the matrix

    // Compute the dot product of f_head and o_first_row and store it in a variable p
    double p = f_head.dot(o_first_row);

    // Output the result
    std::cout << "p: " << p << '\n';

    return 0;
}
