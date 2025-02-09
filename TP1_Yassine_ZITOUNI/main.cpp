#include <iostream>
#ifndef EXO
#define EXO 2
#endif 
int main(){
    #if EXO == 1
    std::cout<< "Hello world!"<<std::endl;
    std::cout<<"Bienvenue en C++";
    #elif EXO == 2
    int num1;
    std::cout<< "enter a number: ";  //asking the user to enter a number
    std::cin>> num1;  // I take it as an input
    std:: cout << "you entered: " <<num1<< std::endl;  // I display the value entered
    #elif EXO == 3
    float num1, num2;  // I create two float variables
    std:: cout << "enter two numbers"<< std::endl;
    std::cin>> num1 >> num2; // I take them as an input
    std::cout << "the sum is " <<num1 + num2<<std::endl;  // Here I perform the operations
    std::cout <<"the subtraction is "<<num1-num2<<std::endl;
    std::cout <<"the product is "<<num1*num2<<std::endl;
    if (num2 != 0) {  // for the division, we should make sure that the second number entered is not zero
        std::cout<< "the division is "<<num1/num2;
    }else{  // else we cannot perform the division
        std::cout <<"you cannot divide by zero";
    }
    #elif EXO == 4
    std::cout <<"Entrez un nombre "; // here I just corrected the code given
    int nombre;
    std::cin >>nombre;
    std::cout << "Vous avez entrer "<<nombre<<std::endl; 
    #elif EXO == 5
    std::cout <<"enter the temperature in Celsius "; // I ask about the temperature
    float temp;  // I create a variable for it
    std::cin>> temp;  // Take it as an input
    float in_feh = temp*9/5 + 32;  // and use the formula to convert
    std::cout<<"the temperature in Fahrenheit is: "<<in_feh;  // And display the final result
    #else  // if something else is chosen besides 1, 2, 3, 4 or 5
    std::cerr <<"Define EXO as 1,2,3,4 or 5";  // I display this message
    #endif
    return 0;
}
