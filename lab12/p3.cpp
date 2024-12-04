#include <fstream>
#include <eigen3/Eigen/Dense>
#include <cmath>
#include <stdexcept>

int main() {
    Eigen::IOFormat CSVFormat(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", "\n");
    std::ofstream outfile{"pendulum_output.csv"};
    if (!outfile.good()) {
        throw std::runtime_error("failed to open file for writing!");
    }

    float const g = 9.8;
    float const l = 0.1;
    float const dt = 0.005; // this is Δt

    // Create a vector for [x, xdot] and initialize it to [pi/4, 0]
    Eigen::Vector2f x;
    x << M_PI / 4, 0;

    // Create the matrix A
    Eigen::Matrix2f A;
    A << 0, 1,
         -g/l, 0;

    // Roll out the dynamics using the equation in the lab document
    for (int i{0}; i < 100; ++i) {
        // Write the current x to the outfile
        outfile << x.format(CSVFormat) << '\n';

        // Update x based on the dynamics
        x = x + dt * A * x;
    }

    return 0;
}