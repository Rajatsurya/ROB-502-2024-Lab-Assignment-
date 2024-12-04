#include <iostream>   // # is a preprocessor directive - i.e must process before the rest of compiling
// includes some other code in your program
// it includes iostream
using namespace std; //this ine makes stl functions -easier to refer to in your code
int main() { // main is the main function that is going to run 
cout << "hello world!"  << endl; // this is the logic that runs in the main function
// cout is an output string
// endl is the command to tell end of line
return 0; 
}

// command to compile in the terminal g++ hello_world.cpp  (name of the file to compile) -o hello_world (name you wish to give)

// another way to write the code is 
// #include <iostream>  
// int main() { 
// std::cout << "hello world!"  << std::endl; 
// return 0; 
// }