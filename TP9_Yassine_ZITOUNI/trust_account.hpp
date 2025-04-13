#ifndef TRUST
#define TRUST
#include "saving_account.hpp"
class trust_account: public saving_account{
    private:
        static constexpr float bonus_amount = 50.0;
        static constexpr float bonus_threshold = 5000.0;
        static constexpr int max_withdrawals = 3;
        static constexpr float max_withdraw_percent = 0.2;
    public:
        int num_withdrawals;
        trust_account();
        trust_account(string name);
        trust_account(string name, double balance);
        trust_account(string name, double balance, double int_rate);
        bool deposit(double amount);
        bool withdraw(double amount);
        friend ostream& operator<<(ostream& os, trust_account& trust_acc);

};
#endif