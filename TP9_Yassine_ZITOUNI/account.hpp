#ifndef ACCOUNT
#define ACCOUNT
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Account{
    private: 
        static constexpr char def_name[] = "------";
        static constexpr double def_balance = 1000;
    protected:
        string name;
        double balance;
    public:
        string get_name() const { return name; }
        double get_balance() const { return balance; }
        Account(string name = def_name, double balance = def_balance);
        bool deposit(double amount);
        bool withdraw(double amount);
        friend ostream& operator<<(ostream& os, const Account& acc);

};
#endif