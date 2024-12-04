#include <lcm/lcm-cpp.hpp>
#include <chrono>
#include <iostream>
#include <thread>
#include <cmath>
#include <chrono>

int main()
{
    using namespace std::chrono_literals;

    lcm::LCM lcm;

    if (!lcm.good())
    {
        return 1;
    }

    auto const duration = 100ms;
    std::chrono::duration<double, std::milli> t{0};
    while (t < 60s)
    {
        auto const timestamp = t.count();
        auto const theta = std::fmod(timestamp / 1000, 2 * M_PI);
        auto const x = cos(theta);
        auto const y = sin(theta);

        std::cout << "Sending at t=" << timestamp << ": " << x << ", " << y << std::endl;
        std::this_thread::sleep_for(duration);

        t += duration;
    }
    return 0;
}
