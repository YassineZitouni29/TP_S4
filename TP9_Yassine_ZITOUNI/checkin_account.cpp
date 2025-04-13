#include "checkin_account.hpp"
#include <string>

checking_account::checking_account(): Account{}{}

checking_account::checking_account(string name)
    : Account{name}{}

    
    checking_account::checking_account(std::string name, double balance)
        : Account(name, balance) {}
    
    bool checking_account::deposit(double amount) {
        if (amount < 0) return false;
        balance += amount;
        return true;
    }
    
    bool checking_account::withdraw(double amount) {
        if ((amount + per_check_fee) > balance) return false;
        balance -= (amount + per_check_fee);
        return true;
    }
    
ostream& operator<<(ostream& os, checking_account& check_acc){
    if (check_acc.name!="------"){
    os<<"[Account name: "<<check_acc.name<<" balance: "<<check_acc.balance<<" ]";
    return os;
    }else{
        os<<"[Account name: Unnammed account, balance: "<<check_acc.balance<<" ]";
    return os;
    }
}