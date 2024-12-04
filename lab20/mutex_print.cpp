#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std::chrono_literals;

// Global variables
std::vector<double> myVector(32, 0);
std::mutex myMutex;

void increment()
{
    for (auto &vec_i : myVector)
    {
        std::this_thread::sleep_for(3ms);

        // Lock the mutex before modifying myVector
        myMutex.lock();
        vec_i += 1;
        // Unlock the mutex after modification
        myMutex.unlock();
    }
}

void printVector()
{
    for (auto const &i : myVector)
    {
        std::this_thread::sleep_for(7ms);

        // Lock the mutex before reading myVector
        myMutex.lock();
        std::cout << i << ",";
        myMutex.unlock();
    }
    std::cout << std::endl;
}

int main()
{
    for (auto i{0}; i < 10; ++i)
    {
        std::thread t1(increment);
        std::thread t2(increment);
        std::thread print_thread(printVector);

        t1.join();
        print_thread.join();
        t2.join();
    }
    return 0;
}
