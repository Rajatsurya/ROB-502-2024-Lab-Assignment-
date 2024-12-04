#include <iostream>
#include <unordered_map>
#include <string>
class Robot
{
public:
Robot(std::string const &name, int dof) : name_(name), dof_(dof)
{
std::cout << "building robot " << name_ << " with " << dof_ << " joints\n";
}
int dof_;
std::string name_;
};
namespace std {
ostream& operator<<(ostream& os, const Robot& r)
{
os << r.name_;
return os;
}
}
int main() {
std::unordered_map<std::string, Robot> mymap;
// std::cout << mymap.at("mykey") << std::endl; // [1] // trying to acesses a key that does not exist so run time error
std::cout << mymap["mykey"] << std::endl; // [2] // trys to create a key and no default constructors are present in the class robot and you cannot do this
return 0;
}