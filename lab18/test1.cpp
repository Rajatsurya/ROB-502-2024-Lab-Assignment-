#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>

class Point
{
public:
    Point(double x, double y) : x(x), y(y) {}
    double x, y;
};

using Problem = std::vector<Point>;
using Assignment = std::vector<int>;

class Solution
{
public:
    Solution(size_t N)
    {
        // default solution; each solution must be valid
        for (size_t i = 0; i < N; ++i)
        {
            order.push_back(i);
        }
    }
    // the order in which the points are visited; note that we never need to visit a node twice
    // therefore the assignment is a permutation of 0,1,...,N-1
    Assignment order;
    double cost;
};
double distance(const Point &a, const Point &b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return std::sqrt(dx * dx + dy * dy);
}

double scoreAssignment(const Problem &points, const Assignment &order) {
    double totalDistance = 0.0;

    for (size_t i = 1; i < order.size(); ++i) {
        int currentIndex = order[i - 1];
        int nextIndex = order[i];
        totalDistance += distance(points[currentIndex], points[nextIndex]);
    }

    return totalDistance;
}

Assignment perturbAssignment(Assignment order) {
    // Set up random number generation
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dis(0, order.size() - 1);

    // Pick two random indices to swap
    size_t idx1 = dis(gen);
    size_t idx2 = dis(gen);

    // Swap elements at the chosen indices
    std::swap(order[idx1], order[idx2]);

    return order;
}

class SimulatedAnnealingParameters {
public:
    double maxTemperature;      // Starting temperature
    double deltaTemperature;    // Cooling rate (multiplier to reduce temperature)
    double finishTemperature;   // Temperature at which we stop
};

// Simulated Annealing function
// Solution simulatedAnnealing(const Problem &problem, Solution sol, SimulatedAnnealingParameters params) {
//     // Initialize random number generator
//     std::random_device rd;
//     std::mt19937 gen(rd());
//     std::uniform_real_distribution<double> probDist(0.0, 1.0); // For probability check

//     // Set initial cost
//     sol.cost = scoreAssignment(problem, sol.order);

//     // Start the annealing process
//     for (double t = params.maxTemperature; t > params.finishTemperature; t *= params.deltaTemperature) {
//         // Generate a new candidate solution by perturbing the current solution
//         Assignment newOrder = perturbAssignment(sol.order);

//         // Calculate the cost of the new solution
//         double newCost = scoreAssignment(problem, newOrder);

//         // Calculate the difference in cost
//         double deltaCost = newCost - sol.cost;

//         // If the new solution is better, accept it
//         if (deltaCost < 0) {
//             sol.order = newOrder;
//             sol.cost = newCost;
//         }
//         // If the new solution is worse, accept it with a probability that decreases with temperature
//         else {
//             double prob = std::exp(-deltaCost / t); // Boltzmann probability
//             if (probDist(gen) < prob) {
//                 sol.order = newOrder;
//                 sol.cost = newCost;
//             }
//         }

//         // Debug output to see the process
//         std::cout << "Current cost: " << sol.cost << ", New cost: " << newCost
//                   << ", Probability: " << std::exp(-deltaCost / t) << std::endl;
//     }
    
//     // Return the final solution
//     return sol;
// }
int main()
{
    Problem prob;
    prob.emplace_back(0, 0);
    prob.emplace_back(5, 5);
    prob.emplace_back(-2, 3);
    prob.emplace_back(4, 1);
    prob.emplace_back(3, 4);
    prob.emplace_back(-4, -2);
    prob.emplace_back(2, -4);
    Solution sol(prob.size());
    // solution of default assignment
    sol.cost = scoreAssignment(prob, sol.order);
    // std::cout << sol.cost << std::endl;
    // SimulatedAnnealingParameters params{10, 0.99, 0.001};
    // auto saSolution = simulatedAnnealing(prob, sol, params);
    // std::cout << "simulated annealing solution\ncost " << saSolution.cost << std::endl;
    // for (const auto &i : saSolution.order)
    // {
    //     std::cout << i << ' ';
    // }
    // std::cout << std::endl;
    // for (const auto &i : saSolution.order)
    // {
    //     std::cout << prob[i].x << ' ' << prob[i].y << std::endl;
    // }
    std::cout<<sol.cost<<std::endl;
}