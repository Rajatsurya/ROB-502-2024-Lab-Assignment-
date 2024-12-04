#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <string>

// Struct to store joint limits
struct JointLimit
{
    double lower_;
    double upper_;
    JointLimit(double lower, double upper) : lower_(lower), upper_(upper) {}
};

// Clip function to restrict joint position within limits
double clip(double joint_position, JointLimit const &joint_limit)
{
    if (joint_position < joint_limit.lower_)
    {
        return joint_limit.lower_;
    }
    else if (joint_position > joint_limit.upper_)
    {
        return joint_limit.upper_;
    }
    else
    {
        return joint_position;
    }
}

// Enforce joint limits on each joint in q using joint_limits
void enforce_joint_limits(std::map<std::string, JointLimit> const &joint_limits, std::map<std::string, double> &q) {
    for (auto const& kv : q) // range-based for loop with "kv" as auto const&
    {
        std::string const joint_name = kv.first;
        double joint_position = kv.second;
        
        // Get the joint limit for the current joint
        JointLimit const joint_limit = joint_limits.at(joint_name);
        
        // Clip the joint position within limits and update in q
        q[joint_name] = clip(joint_position, joint_limit);
    }
}

int main()
{
    // Vector of joint values
    std::vector<double> joint_values{0, 0.2, 0.5, -0.4, 0.5};

    // Modify joint_values by doubling each joint value
    for (auto& joint_i : joint_values) // using auto& to modify joint values
    {
        joint_i *= 2;
    }

    // Define joint limits and current joint positions
    std::map<std::string, JointLimit> joint_limits{
        {"joint1", JointLimit{0, M_PI}},
        {"joint2", JointLimit{-M_PI, M_PI}},
        {"joint3", JointLimit{-M_PI, 0}},
        {"joint4", JointLimit{-2 * M_PI, 2 * M_PI}},
        {"joint5", JointLimit{-2 * M_PI, 2 * M_PI}},
    };
    
    std::map<std::string, double> q{
        {"joint1", -2.0},
        {"joint2", 2.0},
        {"joint3", 2.0},
        {"joint4", 3.0},
    };

    // Enforce the joint limits on q
    enforce_joint_limits(joint_limits, q);

    // Calculate the final answer
    double final_answer = 0;

    // Sum the values of q (joint positions)
    for (auto const& kv : q) // using auto const& for kv to iterate over map "q"
    {
        final_answer += kv.second;
    }

    // Sum the values in joint_values
    for (auto joint_i : joint_values) // using auto for joint_i to iterate over joint_values
    {
        final_answer += joint_i;
    }

    // Output the final result
    std::cout << final_answer << "\n";
    return 0;
}
