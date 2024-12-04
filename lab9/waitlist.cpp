#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

class Student {
public:
    std::string first_name;
    std::string last_name;
    int age;

    Student(std::string fname, std::string lname, int age)
        : first_name(fname), last_name(lname), age(age) {}
};

// Define the operator<< outside the class (no need for friend here)
std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << s.first_name << " " << s.last_name << ", Age: " << s.age;
    return os;
}

// Function to convert std::queue to std::vector
std::vector<Student> queue_to_vector(std::queue<Student> q) {
    std::vector<Student> vec;
    while (!q.empty()) {
        vec.push_back(q.front());
        q.pop();
    }
    return vec;
}

int main() {
    // Creating a queue of Student objects
    std::queue<Student> waitlist;

    // Using emplace to add students to the queue
    waitlist.emplace("Wei", "CA", 21);
    waitlist.emplace("Alison", "TX", 24);
    waitlist.emplace("Juan", "MI", 22);

    // Convert the queue to a vector
    std::vector<Student> student_list = queue_to_vector(waitlist);

    // Using std::min_element to find the student with the minimum age

    return 0;
}
