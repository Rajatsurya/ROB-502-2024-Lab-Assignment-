# include<iostream>

int main(){
    int*numbers= new int[10];
    for (int i=0 ; i < 10 ; i++){
        numbers[i]=i*10;
        std::cout<<numbers[i]<<std::endl;
    }
    delete[] numbers;
    return 0;


}

