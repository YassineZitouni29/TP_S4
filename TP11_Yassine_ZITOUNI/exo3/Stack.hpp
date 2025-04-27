#ifndef STACK
#define STACK
#include <iostream>
#include <vector>
#include <exception>
class StackFullException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Stack is full! Cannot push more elements.";
    }
};
class StackEmptyException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Stack is empty! Cannot pop elements.";
    }
};
class Stack {
    private:
        std::vector<int> elements;
        std::size_t capacity;
    public:
        Stack(std::size_t max_capacity) : capacity(max_capacity) {};
        int size(){
            return elements.size();
        }

        void push(int value) {
            if (elements.size() >= capacity) {
                throw StackFullException();
            }
            elements.push_back(value);
        }

        void pop() {
            if (elements.empty()) {
                throw StackEmptyException();
            }
            elements.pop_back();
        }
};
void func_c(Stack& s) {
    std::cout << "In func_c...\n";
    s.pop(); 
}
void func_b(Stack& s) {
    std::cout << "In func_b...\n";
    func_c(s);
}
void func_a(Stack& s) {
    std::cout << "In func_a...\n";
    func_b(s);
}
#endif