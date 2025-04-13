#include "trust_account.hpp"
#include <iostream>
#include "saving_account.hpp"
using namespace std;
trust_account::trust_account(string name, double balance, double int_rate): saving_account(name,balance, int_rate),num_withdrawals(0){}
trust_account::trust_account(string name, double balance)
    : saving_account(name, balance,0), num_withdrawals{0} {
}
trust_account::trust_account(): saving_account{}, num_withdrawals{0}{}
trust_account::trust_account(string name):saving_account{name}, num_withdrawals{0}{}
bool trust_account::deposit(double amount) {
    if (amount < 0)
        return false;
    else if (amount < 5000)
        balance += (amount*(1+int_rate/100));
    else
        balance += (amount + bonus_amount);

    return true;
}

bool trust_account::withdraw(double amount){
    if (amount<0) return false;
    if (amount<=max_withdraw_percent*balance && num_withdrawals<max_withdrawals){
        balance-=amount;
        num_withdrawals+=1;
        return true;
    }
    return false;
}
ostream& operator<<(ostream& os, trust_account& trust_acc) {
    if (trust_acc.name!="------"){
    os << "[Trust Account: Name: " << trust_acc.name
       << " Balance: " << trust_acc.balance
       << " Interest Rate: " << trust_acc.int_rate
       << " Withdrawals: " << trust_acc.num_withdrawals << "]";
    return os;  
    }else{
        os << "[Trust Account: Unnamed_account " 
        << " Balance: " << trust_acc.balance
        << " Interest Rate: " << trust_acc.int_rate
        << " Withdrawals: " << trust_acc.num_withdrawals << "]";
     return os; 
    }
}
