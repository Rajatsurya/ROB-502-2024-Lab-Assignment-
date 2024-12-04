#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Name_pairs {
private:
    std::vector<std::string> name;
    std::vector<double> age;

public:
    void read_names(const std::vector<std::string>& names) {
        name = names;
    }

    void read_ages() {
        age.clear();  // Clear existing ages
        for (const auto& n : name) {
            double a;
            std::cout << "Enter age for " << n << ": ";
            std::cin >> a;
            age.push_back(a);
        }
    }

    void print() const {
        for (size_t i = 0; i < name.size(); ++i) {
            std::cout << name[i] << ", " << age[i] << std::endl;
        }
    }
};

int main() {
    Name_pairs np;
    np.read_names({"Tom", "Peter", "Johnson", "Dmitry"});
    np.read_ages();
    np.print();
    return 0;
}
