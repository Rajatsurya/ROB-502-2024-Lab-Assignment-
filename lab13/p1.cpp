#include <iostream>
#include <eigen3/Eigen/Eigen>
int main()
{
Eigen::VectorXd sensor(10);
sensor << 0., 0.11111111, 0.22222222, 0.33333333, 0.44444444, 0.55555556, 0.66666667, 0.77777778, 0.88888889, 1.0;
Eigen::VectorXd distance(10);
distance << 0.48147829, 0.70278627, 0.94916103, 1.1409607, 1.38118014, 1.62292857, 1.81760639, 2.04022307, 2.27369675, 2.495571;
// create A using sensor
// create b using distance
// solve for x using QR method (see lecture slides)
// write down the values for x1 and x2

Eigen::Matrix<double, 10,2>A;
A.setOnes();
A.col(0)=sensor;
Eigen::VectorXd b = distance;
Eigen::VectorXd x = A.colPivHouseholderQr().solve(b);

std::cout<<"x1:" << x(0) << " x2:" <<x(1) << '\n';
return 0;
}