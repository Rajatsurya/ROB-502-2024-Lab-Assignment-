#include <iostream>
#include <string>

class Robot {
int links;
public:
Robot() :links(0) {};
Robot(int l) :links(l) {};
int getLinks() const {return links;}
};
class PandaArm : public Robot {
    public:
     PandaArm() : Robot() {}
     PandaArm(int l) : Robot(l) {}
};

int main() {
PandaArm p;
std::cout << p.getLinks() << std::endl;
PandaArm p2(7);
std::cout << p2.getLinks() << std::endl;
}