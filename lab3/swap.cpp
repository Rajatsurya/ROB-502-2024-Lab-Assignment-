#include<iostream>
void swap_v(int a, int b){
    int temp;
    temp =a;
    a=b;
    b=temp;
}
void swap_r(int& a, int& b){
    int temp;
    temp =a;
    a=b;
    b=temp;
}
// void swap_cr(const int& a, const int& b){
//     int temp;
//     temp =a;
//     a=b;
//     b=temp;
// } cannot be done as it is a constant 


int main(){
    int x = 7; 
    int y =9; 
    swap_v(x,y);
    std::cout <<x<< "," <<y<< "." << std::endl;

    swap_r(x,y);
    std::cout <<x<< "," <<y<< "." << std::endl;

    


}