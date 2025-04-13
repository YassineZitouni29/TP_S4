#ifndef SAVING
#define SAVING
#include "account.hpp"
class saving_account: public Account{
    private:
        static constexpr double def_int_rate = 1;
    public:
        double int_rate;
        saving_account();
        saving_account(string name);
        saving_account(string name, double balance, double int_rate = def_int_rate);
        bool deposit(double amount);
        bool withdraw(double amount);
        friend ostream& operator<<(ostream& os, const saving_account& save_acc);
};
#endif