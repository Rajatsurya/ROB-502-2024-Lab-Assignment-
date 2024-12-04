#include <thread>
#include <chrono>
#include <future>
#include <iostream>
#include <vector>

unsigned long compute_thing(int thread_id, unsigned long n)
{
    auto fib = 2;
    for (auto k{0}; k < 100'000; ++k)
    {
        auto sum{2ul};
        auto last_fib = 1;
        fib = 2;
        while (fib < n)
        {
            auto const temp = fib;
            fib = fib + last_fib;
            if (fib % 2 == 0)
            {
                sum += fib;
            }
            last_fib = temp;
        }
    }
    return fib;
}

int main()
{
    using namespace std::chrono_literals;
    auto n_queries{100};
    auto kN{100'000ul};

    // Without threading
    auto const t0 = std::chrono::high_resolution_clock::now();
    for (auto i{0}; i < n_queries; ++i)
    {
        auto const s = compute_thing(i, i + kN);
    }
    auto const t1 = std::chrono::high_resolution_clock::now();

    // Now with naive threading
    auto const t2 = std::chrono::high_resolution_clock::now();
    
    // Create a vector of std::future objects
    std::vector<std::future<unsigned long>> v;
    for (auto i{0}; i < n_queries; ++i)
    {
        // Launch compute_thing asynchronously and store the future
        v.emplace_back(std::async(std::launch::async, compute_thing, i, i + kN));
    }

    // Wait for all threads to finish
    for (auto& f : v)
    {
        f.get();
    }

    auto const t3 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> dt_without_threading = t1 - t0;
    std::cout << "without threading : " << dt_without_threading.count() << " ms \n";
    
    std::chrono::duration<double, std::milli> dt_with_threading = t3 - t2;
    std::cout << "with threading : " << dt_with_threading.count() << " ms \n";

    return 0;
}

// use this command to compile it g++ file_name.cpp -o name -pthread

