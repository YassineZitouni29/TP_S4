#include <iostream>
using namespace std;
#include <exception>
class DivideByZeroException: public exception{
    public:
        const char* what() const noexcept override{
            return "Division by zero";
        }
};
class InvalidOperationException: public exception{
    public:
        const char* what() const noexcept override{
            return "Invalid operation";
        }
};
double calculate(double num1, double num2, char operation);
int main() {
    double num1, num2;
    char operation;
    std::cout << "Enter␣first␣number:␣";
    std::cin >> num1;
    std::cout << "Enter␣second␣number:␣";
    std::cin >> num2;
    std::cout << "Enter␣operation␣(+,␣-,␣*,␣/):␣";
    std::cin >> operation;
    try {
        double result = calculate(num1, num2, operation);
        std::cout << "Result:␣" << result << std::endl;
    }
    catch (const DivideByZeroException& ex) {
        std::cerr << ex.what() << std::endl;
    }
    catch (const InvalidOperationException& ex) {
        std::cerr << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown␣error␣occurred" << std::endl;
    }
    std::cout << "Program␣completed" << std::endl;
    return 0;
}
double calculate(double num1, double num2, char operation){
    if (operation == '+'){
        return num1 + num2;
    }else if (operation == '-'){
        return num1 - num2;
    }else if(operation == '*'){
        return num1 * num2;
    }else if(operation == '/'){
        if (num2 == 0) throw DivideByZeroException();
        return num1/num2;
    }else{ throw InvalidOperationException();}
}