#include <iostream>
#include <cmath>
#ifndef EXO
#define EXO 6  // Define EXO if not already defined, defaulting to 6
#endif
#define PI 3.14159265359  // Define PI as a constant

int value = 100;  // Global variable

// Function to compute factorial at compile-time
constexpr int factorielle(int n){
    if (n==1) return 1;
    return n*factorielle(n-1);
};

// Function to safely multiply two integers while handling overflow
int safeMultiply(int a,int b){
    if (a == 0 || b == 0) {
        return 0;  // Multiplication with zero always results in zero
    }
    int minn = std::numeric_limits<int>::min();  // Minimum possible int value
    int maxx = std::numeric_limits<int>::max();  // Maximum possible int value

    // Check for overflow cases based on signs of a and b
    if (a>0 && b>0 && a>maxx/b) return -1;
    if (a>0 && b<0 && b<minn/a) return -1;
    if (a<0 && b>0 && a<minn/b) return -1;
    if (a<0 && b<0 && a<maxx/b) return -1;

    return a*b;  // If no overflow, return the product
}

int main(){
    #if EXO == 1
    // Compute and display the size of an array
    int tableau[] = {1,8,9,7,8,9,8,9,8,5};
    std::cout << "la taille totale du tableau est "<< sizeof(tableau)<<" octets"<<std::endl;
    std::cout << "la taille d'un element est " <<sizeof(int)<< " octets"<<std::endl;
    std::cout << "Nombres d'elements "<< sizeof(tableau)/sizeof(int)<<std::endl;

    #elif EXO == 2
    // Carpet cleaning cost estimation program
    const int tarif_small = 250;
    const int tarif_big = 350;
    const int TVA = 6;
    const int validite_estimation = 30;
    int num_petit, num_grand;

    // Taking input for number of small and big rooms
    std::cin >> num_petit >> num_grand;

    // Displaying estimation details
    std::cout << "Estimate for carpet cleaning service"<<std::endl;
    std::cout << "Number of small rooms: " << num_petit <<std::endl;
    std::cout << "Number of big rooms: " <<num_grand <<std::endl;
    std::cout << "Price per small rooms: "<<tarif_small<<std::endl;
    std::cout <<  "Price per big rooms: " <<tarif_big<<std::endl;

    int cost = tarif_small*num_petit + tarif_big*num_grand;  // Compute total cost
    std::cout << "Cost: "<< cost<<std::endl;

    float tax = cost*TVA/100;  // Compute tax
    std::cout << "Tax: "<<tax<<std::endl;

    // Display final total and validity period
    std::cout << "=================================="<<std::endl;
    std::cout << "Total estimate: "<< cost+tax<<std::endl;
    std::cout << "This estimate is valid for " << validite_estimation<<" days"<<std::endl;

    #elif EXO == 3
    // Compute and assert factorial at compile time
    constexpr int x = factorielle(5);
    static_assert(x==120, "Error: ");  // Ensures the result is correct at compile time
    std::cout<<x<<std::endl;

    #elif EXO == 4
    // Demonstrate local vs global variable scope
    int value = 50;
    std::cout<<"The local value "<<value<<std::endl;  // Displays local variable
    std::cout<<"The global value "<<::value<<std::endl;  // Displays global variable using scope resolution operator

    #elif EXO == 5
    // Demonstrating const and constexpr
    const int num_mois = 12;
    std::cout<<"Number of months in a year "<< num_mois<<std::endl;

    constexpr int rayon = 7;  // Compile-time constant
    std::cout<<"Radius of the circle is "<<rayon<<std::endl;

    double surface = pow(rayon,2)*PI;  // Compute the surface area of a circle
    std::cout<<"The surface is : "<<surface<<std::endl;

    // rayon = 2; // Uncommenting this would cause an error because rayon is constexpr

    #elif EXO == 6
    // Test the safeMultiply function with different values
    int a = 30000;
    int b = 1000;
    std::cout<<safeMultiply(a,b)<<std::endl;  // Should print the product if no overflow

    a = 300000;
    b = 1000000;
    std::cout<<safeMultiply(a,b)<<std::endl;  // Should return -1 due to overflow

    #endif
}
