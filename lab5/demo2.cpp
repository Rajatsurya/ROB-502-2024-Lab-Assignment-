// Robot class has a name, and a joint configuration, etc...
#include <string>
#include <iostream>
#include <vector>

class Robot
{
public:
    Robot(std::string name) : name_(name) {}

    void setJointConfig(std::vector<double> const &q)
    {
        q_ = q;
    }

    std::string name_;
    std::vector<double> q_;
};

bool is_at_home_config(Robot r)
{
    // return true if all the joint values are 0

    // ranged-for loop
    // for (int i=0; i<r.q_.size(); ++i) {
    //     double q_it = r.q_[i];
    // }
    for (double const q_i : r.q_) {
        if (std::abs(q_i) > 0.0001) {
            return false;
        }
    }
    return true;
}

int main()
{
    Robot r("bb8");
    r.setJointConfig({0, 0.1, 1.2, 0});
    std::cout << is_at_home_config(r) << std::endl;
    return 0;
}