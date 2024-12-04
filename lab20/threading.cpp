#include <vector>
#include <string> 
#include <iostream>
#include <thread>

// Function to print an integer and a string
void print(int n, const std::string &str)
{
    std::string msg = std::to_string(n) + " : " + str;
    std::cout << msg << std::endl;
}

int main()
{
    std::vector<std::string> s = {
        "Educative.blog",
        "Educative",
        "courses",
        "are great"
    };

    std::vector<std::thread> threads;

    // Create threads for each element in the vector `s` and add to `threads` vector
    for (int i = 0; i < s.size(); ++i)
    {
        threads.emplace_back(print, i, s[i]); 
    }

    // Join all threads to ensure they complete before exiting main
    for (auto &t : threads)
    {
        t.join();
    }

    return 0;
}

// use this command to compile it g++ file_name.cpp -o name -pthread