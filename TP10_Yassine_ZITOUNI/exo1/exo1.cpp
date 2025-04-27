#include <iostream>
#include <string>

template<typename T>
T maximum(T first, T second){
    if (first>second) return first;
    return second;
}

std::string maximum(std::string first, std::string second){
    if (first<second) return second;
    return first;
}
    
int main() {
    std::cout << maximum(5, 10) << std::endl; // Affiche 10
    std::cout << maximum(3.14, 2.71) << std::endl; // Affiche 3.14
    std::cout << maximum(std::string("chat"), std::string("chien")) << std::endl; // Affiche chien
    return 0;
}