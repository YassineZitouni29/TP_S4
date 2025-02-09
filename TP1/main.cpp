#include <iostream>
#ifndef EXO
#define EXO 9
#endif 
int main(){
    #if EXO == 1
    std::cout<< "Hello world!"<<std::endl;
    std::cout<<"Bienvenue en C++";
    #elif EXO == 2
    int num1;
    std::cout<< "enter a number: ";
    std::cin>> num1;
    std:: cout << "you entered: " <<num1<< std::endl;
    #elif EXO == 3
    float num1, num2;
    std:: cout << "enter two numbers"<< std::endl;
    std::cin>> num1 >> num2;
    std::cout << "the sum is " <<num1 + num2<<std::endl;
    std::cout <<"the subtraction is "<<num1-num2<<std::endl;
    std::cout <<"the product is "<<num1*num2<<std::endl;
    if (num2 != 0) {
        std::cout<< "the division is "<<num1/num2;
    }else{
        std::cout <<"you cannot divide by zero";
    }
    #elif EXO == 4
    std::cout <<"Entrez un nombre";
    int nombre;
    std::cin >>nombre;
    std::cout << "Vous avez entre "<<nombre<<std::endl; 
    #elif EXO == 5
    std::cout <<"enter the temparture in Celsius ";
    float temp;
    std::cin>> temp;
    float in_feh = temp*9/5 + 32;
    std::cout<<"the temperature in Fahrenheit is: "<<in_feh;
    #else
    std::cerr <<"dddie";
    #endif
    return 0;
}