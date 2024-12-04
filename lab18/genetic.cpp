#include <algorithm>
#include <cmath>
#include <eigen3/Eigen/Eigen>
#include <iostream>
#include <vector>

// Define Problem structure
struct Problem {
    Eigen::VectorXd requiredHours;       // Hours required for each task
    Eigen::VectorXd costPerRobot;        // Cost per hour for each robot
    Eigen::MatrixXd robotCapabilities;   // Capabilities matrix (task x robot)
};

using Assignment = Eigen::Matrix<double, 4, 1>;
double penaltyPerHour = 200.0;

double fitness(const Problem &prob, const Assignment &hours, bool verbose = false) {
    double totalCost = 0.0;
    double totalPenalty = 0.0;

    // Calculate base cost
    for (int i = 0; i < prob.costPerRobot.size(); ++i) {
        totalCost += prob.costPerRobot(i) * hours(i);
    }

    // Calculate penalties
    for (int task = 0; task < prob.requiredHours.size(); ++task) {
        double allocatedHours = 0.0;

        for (int robot = 0; robot < prob.robotCapabilities.cols(); ++robot) {
            allocatedHours += prob.robotCapabilities(task, robot) * hours(robot);
        }

        if (allocatedHours < prob.requiredHours(task)) {
            totalPenalty += (prob.requiredHours(task) - allocatedHours) * penaltyPerHour;
        }
    }

    double fitnessValue = totalCost + totalPenalty;

    if (verbose) {
        std::cout << "Total Cost: " << totalCost << "\n";
        std::cout << "Total Penalty: " << totalPenalty << "\n";
        std::cout << "Fitness Value: " << fitnessValue << "\n";
    }

    return fitnessValue;
}

class Solution {
public:
    Assignment hours;
    double cost;
};

bool compareSolution(const Solution &a, const Solution &b) {
    return a.cost < b.cost; // Lower cost is better
}

using Population = std::vector<Solution>;

Solution crossOver(const Solution &a, const Solution &b) {
    Solution child;
    child.hours.head(2) = a.hours.head(2); // First two hours from 'a'
    child.hours.tail(2) = b.hours.tail(2); // Last two hours from 'b'
    return child;
}

void mutate(Solution &a)
{
    for (int i = 0; i < a.hours.size(); ++i)
    {
        double delta = ((double)rand() / RAND_MAX * 0.2) - 0.1; // Range [-0.1, 0.1] expanded to [-0.2, 0.2]
        a.hours(i) = std::max(0.0, a.hours(i) + delta); // Ensure hours do not go below 0
    }
}

int main() {
    Problem prob;
    prob.requiredHours.resize(5);
    prob.requiredHours << 10, 25, 15, 5, 20; // Hours required for each task

    prob.costPerRobot.resize(4);
    prob.costPerRobot << 75, 128, 70, 34; // Cost per hour for each robot

    prob.robotCapabilities.resize(5, 4);
    prob.robotCapabilities << 1.6, 7.2, 3.7, 0.1,   // Task 1
                               3.5, 2.1, 3.2, 0.15, // Task 2
                               0.1, 7.1, 2.9, 0.1,  // Task 3
                               2.3, 3.2, 3.4, 0.15, // Task 4
                               6.1, 0.1, 4.9, 0.15; // Task 5

    Assignment skipAllWork;
    skipAllWork << 0, 0, 0, 0;
    std::cout << "Fitness (no work): " << fitness(prob, skipAllWork) << std::endl;

    Assignment test;
    test << 2.0, 2.0, 2.5, 2.0;
    std::cout << "Fitness (test): " << fitness(prob, test) << std::endl;

    // Uncommented full solution
    const auto populationSize = 10000;
    Population population(populationSize);
    double hourMax = 4.0;
    for (int i = 0; i < populationSize; ++i) {
        population[i].hours << (double)rand() / RAND_MAX * hourMax,
            (double)rand() / RAND_MAX * hourMax,
            (double)rand() / RAND_MAX * hourMax,
            (double)rand() / RAND_MAX * hourMax;
        population[i].cost = fitness(prob, population[i].hours);
    }

    // Genetic Algorithm
    srand(0);
    for (int k = 0; k < 1000; ++k) { // 100 iterations
        std::sort(population.begin(), population.end(), compareSolution);
        int cutoffIndex = populationSize / 10; // Top 10%

        Population nextPopulation(populationSize);
        for (int i = 0; i < populationSize; ++i) {
            const Solution &a = population[rand() % cutoffIndex];
            const Solution &b = population[rand() % cutoffIndex];

            nextPopulation[i] = crossOver(a, b);
            mutate(nextPopulation[i]);
            nextPopulation[i].cost = fitness(prob, nextPopulation[i].hours);
        }

        population = nextPopulation;
    }

    std::sort(population.begin(), population.end(), compareSolution);
    std::cout << "Best in population:\n" << population[0].hours << std::endl;
    std::cout << "Cost: " << population[0].cost << std::endl;
    fitness(prob, population[0].hours, true);
}
