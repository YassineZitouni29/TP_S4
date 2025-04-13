#ifndef CHECKING
#define CHECKING
#include "account.hpp"
class checking_account: public Account{
    private:
        static constexpr double per_check_fee = 1.5;
    public:
        checking_account(string name, double balance);
        checking_account();
        checking_account(string name);
        bool withdraw(double amount);
        bool deposit(double amount);
        friend ostream& operator<<(ostream& os, checking_account& check_acc);

};
#endif