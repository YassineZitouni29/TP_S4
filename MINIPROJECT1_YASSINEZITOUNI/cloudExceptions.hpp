#ifndef CLOUDEXCEPTION
#define CLOUDEXCEPTION
#include <exception>
#include <iostream>
#include <string>
using namespace std;
class cloudException: public std::runtime_error{
    private:
        string message;
    public:
        cloudException(string message): runtime_error(message),message(message){}
        const char* what() const noexcept override = 0;
};
class AllocationException: public cloudException{
    private:
        string message;
    public:
        AllocationException(string message): cloudException(message){}
        const char* what() const noexcept override{
            return message.c_str();
        }
};
class FileException: public cloudException{
    private:
        string message;
    public:
        FileException(string message): cloudException(message){}
        const char* what() const noexcept override{
            return message.c_str();
        }
};
#endif