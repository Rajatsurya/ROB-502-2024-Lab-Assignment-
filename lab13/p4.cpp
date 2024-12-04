#include <eigen3/Eigen/Eigen>
#include <iostream>

Eigen::Matrix3d make_transform_mat(double theta, double dx, double dy) {
    // Create a 3x3 transformation matrix
    Eigen::Matrix3d transform = Eigen::Matrix3d::Identity();  // Start with identity matrix
    
    // Fill in the rotation part
    transform(0, 0) = std::cos(theta);  // cos(theta)
    transform(0, 1) = -std::sin(theta); // -sin(theta)
    transform(1, 0) = std::sin(theta);  // sin(theta)
    transform(1, 1) = std::cos(theta);  // cos(theta)
    
    // Fill in the translation part
    transform(0, 2) = dx;  // Translation in x
    transform(1, 2) = dy;  // Translation in y
    
    return transform;
}

int main() {
    // Define the transformation parameters
    double theta = 3.0;  // Rotation angle in radians
    double dx = 0.5;     // Translation in x
    double dy = 0.5;     // Translation in y

    // Define the 2D vector (point) to be transformed
    Eigen::Vector2d a;
    a << 0.5, 0.5;

    // Convert the 2D vector to homogeneous coordinates (add a 1 as the third component)
    Eigen::Vector3d a_homogeneous;
    a_homogeneous << a(0), a(1), 1;  // [x, y, 1]

    // Call the make_transform_mat function to get the transformation matrix
    Eigen::Matrix3d transformMatrix = make_transform_mat(theta, dx, dy);

    // Apply the transformation (multiply the vector by the transformation matrix)
    Eigen::Vector3d b = transformMatrix * a_homogeneous;

    // Output the result
    std::cout << "Transformed vector (b):\n" << b.head<2>() << std::endl;  // Only print the x and y components
    std::cout << "Homogeneous result (including translation):\n" << b << std::endl;

    return 0;
}