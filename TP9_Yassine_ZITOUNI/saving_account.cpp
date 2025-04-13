#include "saving_account.hpp"
#include "account.hpp"
using namespace std;

saving_account::saving_account()
    : Account{}, int_rate{def_int_rate} {}

saving_account::saving_account(string name)
    : Account{name}, int_rate{def_int_rate} {}
saving_account::saving_account(std::string name, double balance, double int_rate)
    : Account(name, balance), int_rate(int_rate) {}
    
bool saving_account::deposit(double amount) {
    if (amount < 0) return false;
       balance += (amount*(1+int_rate/100));
    return true;
} 
bool saving_account::withdraw(double amount) {
    if (amount > balance) return false;
    balance -= amount;
    return true;
}    
ostream& operator<<(ostream& os, const saving_account& save_acc){
    if (save_acc.name!="------"){
    os<<"[Saving account name: "<<save_acc.name<<" balance: "<<save_acc.balance<<" intrest rate: "<<save_acc.int_rate<<" ]";
    return os;
    }else{
        os<<"[Saving account name: Unnamed account Balance: "<<save_acc.balance<<" interest rate: "<<save_acc.int_rate<<" ]";
    return os;
    }
}