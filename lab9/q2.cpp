#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
struct Student
{
std::string first_name;
std::string last_name;
std::string major;
int age;
};
int addAges(int accumulation, Student const &s)
{
// --- Your code here
return accumulation+s.age;

// ---
}
int main()
{
std::vector<Student> students{
{"peter", "mitrano", "robotics", 26},
{"sheng", "zhong", "robotics", 25},
{"dmitry", "berenson", "robotics", 52},
{"ben", "kuipers", "CS", 88},
{"jana", "pavlasek", "robotics", 27},
{"lean", "sue", "ECE", 19},
};
// --- Your code here
std::cout<< std::accumulate(students.begin(), students.end(), 0, addAges)<< std::endl;
    int count = std::count_if(students.begin(), students.end(), [](const Student &s) {
        return s.age < 30;
    });
std::cout << "the number of students who are younger than 30 are "<< count<<std::endl;
// ---
return EXIT_SUCCESS;
}