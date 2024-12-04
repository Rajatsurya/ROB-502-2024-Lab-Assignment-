#include <fstream>

using namespace std;
int main(){
int x=5;
int y=6;

ofstream out_file("out.txt");

out_file<<x<<endl;
out_file<<y<<endl;
}

