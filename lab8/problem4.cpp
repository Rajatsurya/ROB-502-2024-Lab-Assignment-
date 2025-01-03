#include <vector>
#include <iostream>
class Robot
{
public:
Robot(std::string const &name, int dof) : name_(name), dof_(dof)
{
std::cout << "building robot " << name_ << " with " << dof_ << " joints\n";
}
Robot(Robot const &other) : Robot(other.name_, other.dof_) {} // copy constructor
private:
int dof_;
std::string name_;
};
int main()
{
std::vector<Robot> robots;
robots.reserve(3); // this pre-allocates SPACE for 3 robots, but does NOT allocate any Robot objects
robots.push_back(Robot("tb3_1", 6));
robots.emplace_back("tb3_2", 7); // constructor is called 2 times 
// you can use whatever values you like for name and dof
return 0;
}