// Fixing common errors, Example 4
#include <iostream>
#include <cmath>
#include <vector>
void square_inplace(std::vector<double> &x)
{
for (int i=0; i < x.size(); ++i)
{
x[i] = x[i] * x[i];
}
}
int main()
{
//std::vector<double> const x{2,0.2,0};// remove the constant
std::vector<double> x{2,0.2,0};
square_inplace(x);
for (double const x_i : x) {
std::cout << x_i << "\n";
}
return EXIT_SUCCESS;
}