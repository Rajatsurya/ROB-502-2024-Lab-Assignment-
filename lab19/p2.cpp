#include <iostream>
#include <vector>
#include <eigen3/Eigen/Eigen>

using State = Eigen::Vector3d;

std::vector<State> neighbors(const State& start) {
    std::vector<State> neighbors;

    // Define possible directions for neighbors
    std::vector<State> directions = {
        State(1, 0, 0),   // +1 on the first element
        State(-1, 0, 0),  // -1 on the first element
        State(0, 1, 0),   // +1 on the second element
        State(0, -1, 0),  // -1 on the second element
        State(0, 0, 1),   // +1 on the third element
        State(0, 0, -1)   // -1 on the third element
    };

    // Generate neighbors and check constraint
    for (const auto& dir : directions) {
        State neighbor = start + dir;  // Generate neighbor

        // Check the constraint: |x[0] - x[1]| > x[2]
        if (std::abs(neighbor[0] - neighbor[1]) > neighbor[2]) {
            neighbors.push_back(neighbor);  // Add valid neighbor
        }
    }

    return neighbors;
}

int main() {
    State x;
    x << 3, 4, 0;
    auto n = neighbors(x);
    for (const auto& xx : n) {
        std::cout << xx.transpose() << std::endl;
    }
}
