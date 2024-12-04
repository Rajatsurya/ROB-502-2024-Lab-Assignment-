#include <thread>
#include <future>
#include <eigen3/Eigen/Eigen>
#include <vector>
#include <string>
#include <chrono>
#include <iostream>
#include <random>

double long_computation(int n_problems)
{
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(-1, 1);
    int n = 1000;
    int m = 100;
    double solution = 0;
    for (auto i{0}; i < n_problems; ++i)
    {
        Eigen::MatrixXd A(n, m);
        Eigen::VectorXd b(n);
        for (auto r{0}; r < n; ++r)
        {
            b(r) = distribution(generator);
            for (auto c{0}; c < m; ++c)
            {
                A(r, c) = distribution(generator);
            }
        }
        Eigen::VectorXd x = A.colPivHouseholderQr().solve(b);
        solution += x.sum();
    }
    return solution;
}

int main()
{
    using namespace std::chrono_literals;
    std::vector<std::string> spinner_chars = {"\\", "|", "/", "-"};
    
    // Start the computation asynchronously
    auto future_result = std::async(std::launch::async, long_computation, 10);

    // Spinner animation while computation runs
    auto const t0 = std::chrono::high_resolution_clock::now();
    while (future_result.wait_for(100ms) != std::future_status::ready)
    {
        for (const auto &c : spinner_chars)
        {
            std::cout << "\b" << c << std::flush;
            std::this_thread::sleep_for(100ms);
        }
    }

    // Get the result of the computation
    double solution = future_result.get();
    auto const t1 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> dt = t1 - t0;
    std::cout << "\b";  // Clear the last spinner character
    std::cout << "Computation took " << dt.count() << " ms\n";
    std::cout << "solution : " << solution << "\n";

    return 0;
}
